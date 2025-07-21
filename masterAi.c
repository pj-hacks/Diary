/* THIS PROGRAM IS JUST A SIMPLE            THAT*/
// #include <ctype.h> // included ctype for isdigit()
// #include "compliment.h"
// #include "file_protection.h"
#include "user_existance.h"
#include "utility.h"
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcat
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
// #include "userfiles.h"

#define NUM_COMPLIMENTS 26
#define MAX_NAME_LENGTH 50

char user_name[MAX_NAME_LENGTH]; // The maximun length of the name is 50

int main() {

  srand(time(NULL));

  printf("WELCOME TO MALLOT\n\t"); // This is the welcome page of mallot.

  printf("Enter your name: "); // Prompting user for input.

  fgets(user_name, sizeof(user_name), stdin);
        //Takes the name of the user and then uses it to check for the
                // existence if the user.

  remove_newline(user_name);

  user_existance(
      user_name); // This function check for the existence of the user.

  printf("\nLove to see you again \n");
}
