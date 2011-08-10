/* vim: set ts=2 et sw=2 tw=80: */
/*
 *
 * ***** BEGIN LICENSE BLOCK *****
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
 * The Original Code is mozilla.org Code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
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

#include <nsMsgBaseCID.h>
#include <nsIMsgAccountManager.h>
#include <nsServiceManagerUtils.h>

#include "BeckySettingsImporter.h"

NS_IMPL_ISUPPORTS1(BeckySettingsImporter, nsIImportSettings)

BeckySettingsImporter::BeckySettingsImporter()
{
  /* member initializers and constructor code */
}

BeckySettingsImporter::~BeckySettingsImporter()
{
  /* destructor code */
}

NS_IMETHODIMP
BeckySettingsImporter::AutoLocate(PRUnichar **aDescription NS_OUTPARAM,
                                  nsIFile **aLocation NS_OUTPARAM,
                                  PRBool *_retval NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
BeckySettingsImporter::SetLocation(nsIFile *aLocation)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

nsresult
GetIncomingServer(const nsString &aUserName,
                  const nsString &aServerName,
                  nsIMsgIncomingServer **aServer)
{
  nsresult rv;
  nsCOMPtr<nsIMsgAccountManager> accountManager = do_GetService(NS_MSGACCOUNTMANAGER_CONTRACTID, &rv);
  NS_ENSURE_SUCCESS(rv, rv);

  nsCOMPtr<nsIMsgIncomingServer> incomingServer;
  rv = accountManager->FindServer(NS_ConvertUTF16toUTF8(aUserName),
                                  NS_ConvertUTF16toUTF8(aServerName),
                                  NS_LITERAL_CSTRING("pop3"),
                                  getter_AddRefs(incomingServer));

  if (NS_FAILED(rv) || !incomingServer) {
    rv = accountManager->CreateIncomingServer(NS_ConvertUTF16toUTF8(aUserName),
                                              NS_ConvertUTF16toUTF8(aServerName),
                                              NS_LITERAL_CSTRING("pop3"),
                                              getter_AddRefs(incomingServer));
  }
  NS_IF_ADDREF(*aServer = incomingServer);

  return NS_OK;
}

NS_IMETHODIMP
BeckySettingsImporter::Import(nsIMsgAccount **aLocalMailAccount NS_OUTPARAM,
                              PRBool *_retval NS_OUTPARAM)
{
  nsresult rv;
  nsAutoString userName, serverName;

  nsCOMPtr<nsIMsgIncomingServer> incomingServer;
  rv = GetIncomingServer(userName, serverName, getter_AddRefs(incomingServer));
  NS_ENSURE_SUCCESS(rv, rv);

  nsCOMPtr<nsIMsgAccountManager> accountManager =
    do_GetService(NS_MSGACCOUNTMANAGER_CONTRACTID, &rv);

  nsCOMPtr<nsIMsgIncomingServer> localFoldersServer;
  accountManager->GetLocalFoldersServer(getter_AddRefs(localFoldersServer));

  nsCOMPtr<nsIMsgAccount> localFoldersAccount;
  accountManager->FindAccountForServer(localFoldersServer,
                                       getter_AddRefs(localFoldersAccount));

  nsCOMPtr<nsIMsgAccount> account;
  rv = accountManager->CreateAccount(getter_AddRefs(account));
  rv = account->SetIncomingServer(incomingServer);

  if (aLocalMailAccount)
    account.forget(aLocalMailAccount);
  *_retval = PR_TRUE;
  return NS_OK;
}

nsresult
BeckySettingsImporter::Create(nsIImportSettings** aImport)
{
  NS_ENSURE_ARG_POINTER(aImport);
  NS_IF_ADDREF(*aImport = new BeckySettingsImporter());
  return NS_OK;
}
