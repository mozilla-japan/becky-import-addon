var description = 'Filters component tests'
var gFilters;

function setUp() {
}

function tearDown() {
}

testCreate.description = "create instance test";
testCreate.priority = 'must';
function testCreate() {
  gFilters = Cc["@mozilla-japan.org/import/becky/filters;1"].getService(Ci.nsIImportFilters);
  assert.isDefined(gFilters);
}
