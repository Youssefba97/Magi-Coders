## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartfarm

smartfarm_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	capteurs.c capteurs.h \
	tree.c tree.h \
	fonction.c fonction.h \
	client.c client.h \
	equip.c equip.h \
	troupeau.c troupeau.h \
	tree1.c tree1.h \
	auth.c auth.h \
	functions.c functions.h \
	tree2.c tree2.h

smartfarm_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

