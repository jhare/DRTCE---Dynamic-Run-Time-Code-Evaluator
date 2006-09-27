/* 
   symbol_table - The symbol table is an operation counter for the drtce.

   Copyright (C) 2006 Joseph Hare

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  

*/

#include <stdio.h>
#include <sys/types.h>
#include <getopt.h>
#include "system.h"

#define EXIT_FAILURE 1

extern "C" {
  char *xstrdup (char *p);
}

static void usage (int status);

/* The name the program was run with, stripped of any leading path. */
char *program_name;

/* Option flags and variables */

char *oname = "stdout";		/* --output */
FILE *ofile;
char *desired_directory;	/* --directory */
int want_quiet;			/* --quiet, --silent */

static struct option const long_options[] =
{
  {"output", required_argument, 0, 'o'},
  {"quiet", no_argument, 0, 'q'},
  {"silent", no_argument, 0, 'q'},
  {"verbose", no_argument, 0, 'v'},
  {"directory", required_argument, 0, 22},
  {"help", no_argument, 0, 'h'},
  {"version", no_argument, 0, 'V'},
  {NULL, 0, NULL, 0}
};

static int decode_switches (int argc, char **argv);

int
main (int argc, char **argv)
{
  int i;

  program_name = argv[0];

  i = decode_switches (argc, argv);

  /* do the work */

  exit (0);
}

/* Set all the option flags according to the switches specified.
   Return the index of the first non-option argument.  */

static int
decode_switches (int argc, char **argv)
{
  int c;

  ofile = stdout;

  while ((c = getopt_long (argc, argv, 
			   "q"	/* quiet or silent */
			   "v"	/* verbose */
			   "o:"	/* output */
			   "h"	/* help */
			   "V",	/* version */
			   long_options, (int *) 0)) != EOF)
    {
      switch (c)
	{
	case 'o':		/* --output */
	  oname = xstrdup(optarg);
	  ofile = fopen(oname, "w");
	  if (!ofile)
	    {
	      fprintf(stderr, "cannot open %s for writing", optarg);
	      exit(1);
	    }
	  break;
	case 'q':		/* --quiet, --silent */
	  want_quiet = 1;
	  break;
	case 22:		/* --directory */
	  desired_directory = xstrdup(optarg);
	  break;
	case 'V':
	  printf ("symbol_table %s\n", VERSION);
	  exit (0);

	case 'h':
	  usage (0);

	default:
	  usage (EXIT_FAILURE);
	}
    }

  return optind;
}


static void
usage (int status)
{
  printf (_("%s - The symbol table is an operation counter for the drtce.\n"), program_name);
  printf (_("Usage: %s [OPTION]... [FILE]...\n"), program_name);
  printf (_("Options:\n"
"  -o, --output NAME          send output to NAME instead of standard output\n"
"  -q, --quiet, --silent      inhibit usual output\n"
"  --verbose                  print more information\n"
"  --directory NAME           use specified directory \n"
"  -h, --help                 display this help and exit\n"
"  -V, --version              output version information and exit\n"
));
  exit (status);
}
