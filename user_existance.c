#include <ctype.h> // included ctype for isdigit()
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcat
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include "user_creation.h"
#include "user_existance.h"
#include "file_management.h"
#include "utility.h"
#include "compliment.h"
#include "file_creation.h"

#define MAX_NAME_LENGTH 50  //used to store the maxumum name of the user

#define MAX_LENGTH 100

int user_existance(char *user_name)
{

//int main(){
  int found = 0;  // This variable checks if the user exist
  printf("\nCHECKING IF USER EXISTS\n");
//char user_File[MAX_LENGTH] = "u";
  char *name_Search = (char*)malloc(MAX_LENGTH);

  char *user_Identity = (char*)malloc((MAX_NAME_LENGTH));  //This is a buffer for storing the username.
  strcpy(user_Identity, user_name);

  FILE *user_Search;
  user_Search =fopen("userfiles.txt", "r");

  while(fgets(name_Search, MAX_NAME_LENGTH, user_Search)!= NULL) {
    remove_newline(name_Search);
    if(strcmp(user_Identity, name_Search) == 0) {
      //printf("\n User exist\n");
      found = 1;
      file_management(user_name);
      fclose(user_Search);
      free(name_Search);
      return 1;
      //free(user_Identity);
    }
  }

  if (found == 0) {
    printf("\nCreation of files\n");
    user_Search = fopen("userfiles.txt", "a");
    fprintf(user_Search, "%s\n", user_Identity);
    user_creation(user_Identity);
    fclose(user_Search);
  }


  return 0;
}

