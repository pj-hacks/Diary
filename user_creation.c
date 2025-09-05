#include "file_creation.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int user_creation(char *userfolder)
// int main(int argc, char *argv[])
{
  if (mkdir(userfolder, 0755) ==
      0) { // this if statement here create a folder for the user uf ther user
    // dint have ine.

  } else {
    perror("\tError creating folder\n");
  }
  printf("\tACCOUNT CREATION...\t\t\t\n");
  printf("\tThe name of your folder is %s\n", userfolder);

  printf("\tProceeding to file creation.. \n");
  file_creation(userfolder); // this function create the files for the user.
  puts("\npress enter to exist ...!");
  getchar();
  return 0;
}
