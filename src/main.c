/*
 * main.c
 * 
 * Copyright 2021 joee <joee@savage.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "ufunc.h"
#include "argparse.h"
#include "joelog.h"

int main(int argc, char **argv)
{
  /* ufunc */
  char *homedir = load_homedir();
  // printf("%s\n",homedir);
  
  /* argparge */
  struct arguments arguments;
  /* Default values. */
  arguments.silent = 0;
  arguments.verbose = 0;
  arguments.output_file = strcat(homedir,"/output.log");
  // printf("%s\n",arguments.output_file);
  /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
  argp_parse (&argp, argc, argv, 0, 0, &arguments);
  
  stdin_to_file(arguments.args[0],arguments.args[1],arguments.output_file);
  return 0;
  
}

