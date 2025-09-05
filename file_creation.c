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

//char decision[12];
//char file_input[60];
// char file_mode[4];

int file_creation(char * userfolder)
{
  char password[300];
  char leaving; //This hilds the users decision to leave or stay
  FILE *userfiles;  //This file pointer hold the user file and open it in append mode.
  //buffer to store the current working directory
  printf("\nYou need to creat a unique password for the security of your information so no intruder can access it.\n");

  // fileEncryption(password);
  char *files[] = {"/personal_diary.txt", "/medical.txt", "/social.txt", "/financial.txt", "/academic.txt"};  // array of string, for file creation

  printf("\ttDo you want to continue (y or n)\n"); // prompting the user for input
  scanf("%c",&leaving);
  clear_buffer();  //clear the buffer

  if (leaving == 'y') {
//the if statement copys the path

//ends here
    printf("\nOpening files ....\n");
    for(int count = 0; count <= 4; count++) { // this for loop runs as long as count
      char cwd[PATH_MAX];
      char full_Path[PATH_MAX];
      //char complete_path[PATH_MAX];
      if(getcwd(cwd, sizeof(cwd)) != NULL) {
        strcpy(full_Path, cwd);  //copies the current directory into full_Path
        strcat(full_Path, "/");
        strcat(full_Path, userfolder); //appending the name of the user to the full_Path
        strcat(full_Path, files[count]); //concatenates the file names into full_Path
        // strcpy(complete_path, full_Path);  //copy the full_Path int complete_path
      } else {
        perror("getcwd()error");
      }
      //  printf("\n%s",complete_path);
      userfiles = fopen(full_Path, "a");
      sleep(1);
      printf("\nSuccessfully opened %s", files[count]);
      if(userfiles == NULL) {
        perror("error opening the file");
        return 1;
      }
      fclose(userfiles);
    }

  }
  return 0;
}
