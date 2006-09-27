bin_PROGRAMS=symbol_table
symbol_table_SOURCES=symbol_table.cc symbol_table.1 xmalloc.c system.h aclocal.m4 getopt.c getopt1.c getopt.h

#  uncomment the following if symbol_table requires the math library
#symbol_table_LDADD=-lm

EXTRA_DIST=symbol_table.lsm.in #NAME.texinfo symbol_table.spec.in

#  if you write a self-test script named `chk', uncomment the
#  following and add `chk' to the EXTRA_DIST list
#TESTS=chk

#  build and install the .info pages
info_TEXINFOS = symbol_table.texinfo
symbol_table_TEXINFOS = gpl.texinfo

#  install the man pages
man_MANS=symbol_table.1
