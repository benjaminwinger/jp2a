VERSION = @VERSION@
SUBDIRS = src
man_MANS = man/jp2a.1
EXTRA_DIST = tests/??*.txt tests/??*.html tests/??*.jpg tests/run-tests.sh tests/Makefile include/??*.h man/jp2a.1 LICENSES

check: all
	cd tests/; make check
