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

#ifndef BeckyMailImporter_h___
#define BeckyMailImporter_h___

#include <nsIImportMail.h>

#define MJ_BECKYIMPORT_MAIL_CONTRACT_ID \
  "@mozilla-japan.org/import/becky/mail;1"

#define MJ_BECKYIMPORT_MAIL_CID                     \
{                                                   \
  0x335b2634, 0xec60, 0x4389,                       \
  {0x8b, 0x2d, 0x28, 0xd7, 0x02, 0xab, 0x83, 0x8c}}

class nsIFile;
class nsISupportsArray;

class BeckyMailImporter : public nsIImportMail
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMPORTMAIL

  BeckyMailImporter();
  virtual ~BeckyMailImporter();

private:
  PRUint32 mReadBytes;
  PRUint32 CountMailboxSize(nsIFile *aMailboxFolder);
  nsresult CollectMailboxesInDirectory(nsIFile *aDirectory,
                                       PRUint32 aDepth,
                                       nsISupportsArray *aCollected);

  nsresult CollectMailboxesInFolderListFile(nsIFile *aListFile,
                                            PRUint32 aDepth,
                                            nsISupportsArray *aCollected);
  nsresult AppendMailboxDescriptor(nsIFile *aEntry,
                                   PRUint32 aDepth,
                                   nsISupportsArray *aCollected);
  nsresult ImportMailFile(nsIFile *aMailFile,
                          nsIOutputStream *aOutputStream);
};

#endif /* BeckyMailImporter_h___ */
