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

#ifndef _BeckyUtils_H__
#define _BeckyUtils_H__

class nsIFile;
class nsILineInputStream;
class nsIINIParser;

class BeckyUtils {
public:
  static nsresult FindUserDirectory(nsIFile **aFile);
  static nsresult ConvertNativeStringToUTF8(const nsACString& aOriginal,
                                            nsACString& _retval);
  static nsresult ConvertNativeStringToUTF16(const nsACString& aOriginal,
                                             nsAString& _retval);
  static nsresult CreateLineInputStream(nsIFile *aFile,
                                        nsILineInputStream **_retval);
  static nsresult GetDefaultMailboxDirectory(nsIFile **_retval);
  static nsresult GetFolderListFile(nsIFile *aLocation,
                                    nsIFile **_retval);
  static nsresult GetDefaultFolderName(nsIFile *aFolderListFile,
                                       nsACString& name);
  static nsresult GetDefaultMailboxINIFile(nsIFile **_retval);
  static nsresult GetMailboxINIFile(nsIFile *aDirectory, nsIFile **_retval);
  static nsresult CreateINIParserForFile(nsIFile *aFile,
                                         nsIINIParser **aParser);
  static nsresult GetMaiboxNameFromINIFile(nsIFile *aFile, nsCString &aName);
  static nsresult ConvertToUTF8File(nsIFile *aSourceFile,
                                    nsIFile **_retval);
  static nsresult TranslateFolderName(const nsAString & aFolderName,
                                      nsAString & _retval NS_OUTPARAM);
  static PRBool StringEndsWith(const nsAString &aHaystack, const nsAString &aNeedle);
  static PRBool StringBeginsWith(const nsAString &aHaystack, const nsAString &aNeedle);
};


#endif /* _BeckyUtils_H__ */
