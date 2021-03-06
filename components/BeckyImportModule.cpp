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

#include <mozilla-config.h>
#include <ModuleUtils.h>
#include <nsID.h>

#include "BeckyImport.h"
#include "BeckyStringBundle.h"
#include "BeckySettingsImporter.h"
#include "BeckyFiltersImporter.h"
#include "BeckyMailImporter.h"
#include "BeckyAddressBooksImporter.h"
#include "BeckyProfileMigrator.h"

NS_DEFINE_NAMED_CID(MJ_BECKYIMPORT_CID);
NS_DEFINE_NAMED_CID(MJ_BECKYIMPORT_SETTINGS_CID);
NS_DEFINE_NAMED_CID(MJ_BECKYIMPORT_FILTERS_CID);
NS_DEFINE_NAMED_CID(MJ_BECKYIMPORT_MAIL_CID);
NS_DEFINE_NAMED_CID(MJ_BECKYIMPORT_ADDRESSBOOKS_CID);
NS_DEFINE_NAMED_CID(MJ_BECKY_PROFILE_MIGRATOR_CID);

NS_GENERIC_FACTORY_CONSTRUCTOR(BeckyImport)
NS_GENERIC_FACTORY_CONSTRUCTOR(BeckySettingsImporter)
NS_GENERIC_FACTORY_CONSTRUCTOR(BeckyFiltersImporter)
NS_GENERIC_FACTORY_CONSTRUCTOR(BeckyMailImporter)
NS_GENERIC_FACTORY_CONSTRUCTOR(BeckyAddressBooksImporter)
NS_GENERIC_FACTORY_CONSTRUCTOR(BeckyProfileMigrator)

static const mozilla::Module::CategoryEntry kBeckyImportCategories[] = {
  { "mailnewsimport", "{f7a0d2c3-61ea-4754-9bc3-d948f36b4cbb}", kBeckySupportsString },
  { NULL }
};

const mozilla::Module::CIDEntry kBeckyImportCIDs[] = {
  { &kMJ_BECKYIMPORT_CID, false, NULL, BeckyImportConstructor },
  { &kMJ_BECKYIMPORT_SETTINGS_CID, false, NULL, BeckySettingsImporterConstructor },
  { &kMJ_BECKYIMPORT_ADDRESSBOOKS_CID, false, NULL, BeckyAddressBooksImporterConstructor },
  { &kMJ_BECKYIMPORT_FILTERS_CID, false, NULL, BeckyFiltersImporterConstructor },
  { &kMJ_BECKYIMPORT_MAIL_CID, false, NULL, BeckyMailImporterConstructor },
  { &kMJ_BECKY_PROFILE_MIGRATOR_CID, false, NULL, BeckyProfileMigratorConstructor },
  { NULL }
};
const mozilla::Module::ContractIDEntry kBeckyImportContracts[] = {
  { "@mozilla-japan.org/import/becky;1", &kMJ_BECKYIMPORT_CID },
  { MJ_BECKYIMPORT_SETTINGS_CONTRACT_ID, &kMJ_BECKYIMPORT_SETTINGS_CID },
  { MJ_BECKYIMPORT_FILTERS_CONTRACT_ID, &kMJ_BECKYIMPORT_FILTERS_CID },
  { MJ_BECKYIMPORT_MAIL_CONTRACT_ID, &kMJ_BECKYIMPORT_MAIL_CID },
  { MJ_BECKYIMPORT_ADDRESSBOOKS_CONTRACT_ID, &kMJ_BECKYIMPORT_ADDRESSBOOKS_CID },
  { MJ_BECKY_PROFILE_MIGRATOR_CONTRACT_ID, &kMJ_BECKY_PROFILE_MIGRATOR_CID },
  { NULL }
};

static void
importModuleDtor()
{
  BeckyStringBundle::Cleanup();
}

static const mozilla::Module kBeckyImportModule = {
  mozilla::Module::kVersion,
  kBeckyImportCIDs,
  kBeckyImportContracts,
  kBeckyImportCategories,
  NULL,
  NULL,
  importModuleDtor
};

NSMODULE_DEFN(mjBeckyImportServiceModule) = &kBeckyImportModule;

