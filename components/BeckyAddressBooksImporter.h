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

#ifndef BeckyAddressBooksImporter_h___
#define BeckyAddressBooksImporter_h___

#include <nsIImportAddressBooks.h>

#define MJ_BECKYIMPORT_ADDRESSBOOKS_CONTRACT_ID \
  "@mozilla-japan.org/import/becky/addressbooks;1"

#define MJ_BECKYIMPORT_ADDRESSBOOKS_CID             \
{                                                   \
  0xcac8d716, 0xabee, 0x4be4,                       \
  {0x81, 0x31, 0xd9, 0x0a, 0xff, 0x57, 0x1a, 0x20}}

class BeckyAddressBooksImporter : public nsIImportAddressBooks
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMPORTADDRESSBOOKS

  BeckyAddressBooksImporter();
  virtual ~BeckyAddressBooksImporter();

private:
  PRUint32 mReadBytes;
};

#endif /* BeckyAddressBooksImporter_h___ */
