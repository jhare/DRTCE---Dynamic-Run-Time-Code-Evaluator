bin_PROGRAMS=smart_type
smart_type_SOURCES=smart_type.cc smart_type.1 xmalloc.c system.h aclocal.m4 getopt.c getopt1.c getopt.h

#  uncomment the following if smart_type requires the math library
#smart_type_LDADD=-lm

EXTRA_DIST=smart_type.lsm.in #NAME.texinfo smart_type.spec.in

#  if you write a self-test script named `chk', uncomment the
#  following and add `chk' to the EXTRA_DIST list
#TESTS=chk

#  build and install the .info pages
info_TEXINFOS = smart_type.texinfo
smart_type_TEXINFOS = gpl.texinfo

#  install the man pages
man_MANS=smart_type.1
