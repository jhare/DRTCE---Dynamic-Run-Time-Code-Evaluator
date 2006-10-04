bin_PROGRAMS=context_tree
context_tree_SOURCES=context_tree.cc context_tree.1 xmalloc.c system.h aclocal.m4 getopt.c getopt1.c getopt.h

#  uncomment the following if context_tree requires the math library
#context_tree_LDADD=-lm

EXTRA_DIST=context_tree.lsm.in #NAME.texinfo context_tree.spec.in

#  if you write a self-test script named `chk', uncomment the
#  following and add `chk' to the EXTRA_DIST list
#TESTS=chk

#  build and install the .info pages
info_TEXINFOS = context_tree.texinfo
context_tree_TEXINFOS = gpl.texinfo

#  install the man pages
man_MANS=context_tree.1
