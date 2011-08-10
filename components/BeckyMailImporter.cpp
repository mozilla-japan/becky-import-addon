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

#include "BeckyMailImporter.h"

NS_IMPL_ISUPPORTS1(BeckyMailImporter, nsIImportMail)

BeckyMailImporter::BeckyMailImporter()
{
  /* member initializers and constructor code */
}

BeckyMailImporter::~BeckyMailImporter()
{
  /* destructor code */
}

NS_IMETHODIMP
BeckyMailImporter::GetDefaultLocation(nsIFile **aLocation NS_OUTPARAM,
                                      PRBool *aFound NS_OUTPARAM,
                                      PRBool *aUserVerify NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
BeckyMailImporter::FindMailboxes(nsIFile *aLocation,
                                 nsISupportsArray **_retval NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
BeckyMailImporter::ImportMailbox(nsIImportMailboxDescriptor *aSource,
                                 nsIFile *aDestination,
                                 PRUnichar **aErrorLog NS_OUTPARAM,
                                 PRUnichar **aSuccessLog NS_OUTPARAM,
                                 PRBool *aFatalError NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
BeckyMailImporter::GetImportProgress(PRUint32 *_retval NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

NS_IMETHODIMP
BeckyMailImporter::TranslateFolderName(const nsAString & aFolderName,
                                       nsAString & _retval NS_OUTPARAM)
{
  return NS_ERROR_NOT_IMPLEMENTED;
}

nsresult
BeckyMailImporter::Create(nsIImportMail** aImport)
{
  NS_ENSURE_ARG_POINTER(aImport);
  *aImport = new BeckyMailImporter();
  if (!*aImport)
    return NS_ERROR_OUT_OF_MEMORY;

  NS_ADDREF(*aImport);
  return NS_OK;
}
