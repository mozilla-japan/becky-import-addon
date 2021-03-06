/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1999
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <mozilla-config.h>
#include <prprf.h>
#include <prmem.h>
#include <nsCOMPtr.h>
#include <nsIStringBundle.h>
#include <nsIServiceManager.h>
#include <nsIProxyObjectManager.h>
#include <nsIURI.h>
#include <nsServiceManagerUtils.h>
#include <nsIProxyObjectManager.h>
#include <nsXPCOMCIDInternal.h>

#include "BeckyStringBundle.h"

#define BECKY_MESSAGES_URL       "chrome://becky-import/locale/beckyImportMessages.properties"

nsIStringBundle *BeckyStringBundle::mBundle = nsnull;

nsIStringBundle *
BeckyStringBundle::GetStringBundle(void)
{
  if (mBundle)
    return mBundle;

  nsresult rv;
  nsIStringBundle *sBundle = nsnull;

  nsCOMPtr<nsIStringBundleService> sBundleService = do_GetService(NS_STRINGBUNDLE_CONTRACTID, &rv);
  if (NS_SUCCEEDED(rv) && (nsnull != sBundleService)) {
    rv = sBundleService->CreateBundle(BECKY_MESSAGES_URL, &sBundle);
  }

  mBundle = sBundle;

  return sBundle;
}

nsIStringBundle *
BeckyStringBundle::GetStringBundleProxy(void)
{
  if (!mBundle)
    return nsnull;

  nsresult rv;
  nsCOMPtr<nsIProxyObjectManager> proxyObjectManager = do_GetService(NS_XPCOMPROXY_CONTRACTID, &rv);
  if (NS_FAILED(rv))
    return nsnull;

  nsIStringBundle *stringBundleProxy = nsnull;
  proxyObjectManager->GetProxyForObject(NS_PROXY_TO_MAIN_THREAD,
                                        NS_GET_IID(nsIStringBundle),
                                        mBundle, NS_PROXY_SYNC | NS_PROXY_ALWAYS,
                                        (void **) &stringBundleProxy);
  return stringBundleProxy;
}

void
BeckyStringBundle::GetStringByID(PRInt32 stringID, nsString& result, nsIStringBundle *pBundle)
{
  PRUnichar *ptrv = GetStringByID(stringID, pBundle);
  result = ptrv;
  FreeString(ptrv);
}

PRUnichar *
BeckyStringBundle::GetStringByID(PRInt32 stringID, nsIStringBundle *pBundle)
{
  if (!pBundle)
    pBundle = GetStringBundle();

  if (pBundle) {
    PRUnichar *ptrv = nsnull;
    nsresult rv = pBundle->GetStringFromID(stringID, &ptrv);

    if (NS_SUCCEEDED(rv) && ptrv)
      return ptrv;
  }

  nsString resultString;
  resultString.AppendLiteral("[StringID ");
  resultString.AppendInt(stringID);
  resultString.AppendLiteral("?]");

  return ToNewUnicode(resultString);
}

void
BeckyStringBundle::Cleanup(void)
{
  if (mBundle)
    mBundle->Release();
  mBundle = nsnull;
}
