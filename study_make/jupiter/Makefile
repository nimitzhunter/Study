package = jupiter
version = 1.0
distdir = $(package)-$(version)

all clean jupiter:
	cd src && $(MAKE) $@


# make target
dist: $(distdir).tar.gz

#create tarball
# need to distdir to be created first
$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@;
	rm -rf $(distdir);


#create distribution directory
# this version won't work if distdir already exists (not necessarily a directory, but any file with the same name)
# can't add distdir to PHONY because its a real filesystem target
#$(distdir):
#	mkdir $(distdir);
#	cp -r src $(distdir)/.;

# now distdir depends on FORCE and FORCE is not a filesystem target.
$(distdir):FORCE
	mkdir $(distdir);
	cp -r src $(distdir)/.;

# because FORCE is not a file system, it can be added to .PHONY
FORCE:
	rm -rf $(distdir)

.PHONY: FORCE all clean
