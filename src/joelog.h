/*
 * joelog.h
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// only needed until i added the regex to the scanf 
//~ void seek_to_next_line( void )
//~ {
    //~ int c;
    //~ while( (c = fgetc( stdin )) != EOF && c != '\n' );
//~ }

void stdin_to_file( char arg1[], char arg2[] , char *filename)
{
  char log[30];
  char filestore[30];
  // char storage[];
  char yes_no[1];
  int answer = 0;
  int result;
  FILE *fptr;
  printf("%s\n",arg1);
  printf("%s\n",arg2);
  fptr = fopen(filename,"a");
  if(fptr == NULL)
  {
    printf("Effor");
    exit(1);
  }
  
  while(answer == 0) {
    printf("Enter log: ");
    // scanf("%30s",&log);
    // scanf("%10[0-9a-zA-Z ]",&log);
    scanf("%30[^\n]",&log);
    printf("%s\n",&log);
    printf("Is this correct?(y/n)\n");
    // seek_to_next_line();
    scanf("%1s",&yes_no);
    result = strcmp(yes_no,"y");
    if (result == 0){
      //printf("%s\n",&log);
      fprintf(fptr,"%s\n",log);
      answer = 1;
    }
  }
  
  fclose(fptr);
  // return 0;
  
}
// pythons input() function

//~ char name[256];
//~ scanf("%256[^\n]", name);
//~ void getText(char *message, char *variable, int size){
    //~ printf("\n %s: ", message);
    //~ fgets(variable, sizeof(char) * size, stdin);
    //~ sscanf(variable, "%[^\n]", variable);
//~ }

//~ char name[20];
//~ getText("Your name", name, 20);
