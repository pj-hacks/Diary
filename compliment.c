#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "utility.h"

void compliment(char *user_name)
{

#define NUM_COMPLIMENTS 26
#define MAX_NAME_LENGTH 50
  srand(time(NULL));
  char *compliments[NUM_COMPLIMENTS] = {
    "Amazing user_name",      "Beautiful name!", "Charming name!",
    "Delightful user_name!",  "Elagante name!",  "Fantastic name!",
    "Gorgeous user_name!",    "Happy name!",     "Incredible name!",
    "Joyful user_name!",      "Kooky name!",     "lovely name!",
    "Magical user_name!",     "Nice name!",      "Optimistic name!",
    "Preety user_name!",      "Quirky name!",    "Remarkable name!",
    "Sensational user_name!", "Terrific name!",  "Unique name!",
    "Vibrant user_name!",     "Wonderful name!", "xtra special name!",
    "Youtful user_name!",     "Zealous name!",
  };
  int random_index = rand() % NUM_COMPLIMENTS;

  printf("\n\n%s you have a %s name", user_name, compliments[random_index]);
}
