# -*- Mode: Makefile; tab-width: 8; indent-tabs-mode: t; -*-
SUBDIRS = components

ACLOCAL_AMFLAGS = -I m4macros $$ACLOCAL_OPTIONS

noinst_DATA = deploy xpi

JAR_TARGET_FILES =      \
        content         \
        locale

XPI_TARGET_FILES = 				\
	install.rdf				\
	platform				\
	chrome				        \
	chrome.manifest                         \
	components/BeckyImport$(SHARED_LIBRARY_SUFFIX)

if PLATFORM_WINNT
BINARY_SOURCE_DIR = components/BeckyImport/Release
else
BINARY_SOURCE_DIR = components/.libs
endif

deploy:
	(cp $(BINARY_SOURCE_DIR)/BeckyImport$(SHARED_LIBRARY_SUFFIX) \
	 components/)

xpi:
	(rm -rf chrome && \
	 mkdir -p chrome && \
	 zip -q -r -9 chrome/$(PACKAGE_NAME).jar $(JAR_TARGET_FILES) -x \*.git/\* && \
	 rm -f $(PACKAGE_NAME)-$(PACKAGE_VERSION).xpi && \
	 zip -q -r -9 $(PACKAGE_NAME)-$(PACKAGE_VERSION).xpi $(XPI_TARGET_FILES) -x \*.git/\* )

