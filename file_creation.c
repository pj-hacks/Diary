#include <ctype.h> // included ctype for isdigit()
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcat
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include "file_protection.h"
#include "file_creation.h"
#include "utility.h"


int file_creation(char * userfolder)
{
//char password[300];
  char leaving; //This hilds the users decision to leave or stay
  FILE *userfiles;  //This file pointer hold the user file and open it in append mode.

  char *files[] = {"/personal_diary.txt", "/medical.txt", "/social.txt", "/financial.txt", "/academic.txt"};  // array of string, for file creation

  printf("\ttDo you want to continue (y or n)\n"); // prompting the user for input
  scanf(" %c",&leaving);
  clear_buffer();  //clear the buffer

  if (leaving == 'y') {
//the if statement copys the path

    printf("\nOpening files ....\n");
    for(int count = 0; count <= 4; count++) { // this for loop runs as long as count
      char full_Path[PATH_MAX];

      snprintf(full_Path, sizeof(full_Path), "%s%s", userfolder, files[count]);

      userfiles = fopen(full_Path, "a");
      if(userfiles == NULL) {
        perror("error opening the file");
        return 1;

      }
      printf("\nSuccessfully opened %s", files[count]);

      fclose(userfiles);

    }
    return 0;
  }
  return 0;
}
