#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <linux/limits.h>
#include "utility.h"
#include "file_protection.h"
#include "file_management.h"

#define NUM_EDITORS 4
#define CMD_BUFFER 512
#define leave_loop 0

const char *editor(int i);
char *build_command(const char *cwd, const char *editor, const char *filename);
void show_file_options();
void open_file(const char *username, const char *filename);

int control = leave_loop; // controls while loop

int file_management(char *username)
{
  int file_access;
  printf("Welcome back %s.\n", username);

  while (1) {
    show_file_options();
    printf("\nWhat file do you want to access. (0) to exit: ");
    scanf("%d", &file_access);
    clear_buffer();

    switch (file_access) {
    case 1:
      open_file(username, "personal_diary.txt");
      break;
    case 2:
      open_file(username, "financial.txt");
      break;
    case 3:
      open_file(username, "medical.txt");
      break;
    case 4:
      open_file(username, "academic.txt");
      break;
    case 5:
      open_file(username, "social.txt");
      break;
    case 0:
      printf("Leaving...\nPress enter to leave..\n");
      getchar();
      return 0;
    default:
      printf("Invalid option. Try again.\n");
      break;
    }
    printf("\nSaving file ....\n");
    sleep(2);
    printf("Saved\n");
  }
  return 0;
}

void show_file_options()
{
  printf("This are the list of files you have: \n1. personal_diary \n2. financial \n3. medical \n4. academic \n5. social");
  printf("\nRemember that you are to select from 1-5 and 0 if you want to exit\n");
}

void open_file(const char *username, const char *filename)
{
  int choice;

  printf("\nSelect an editor:\n1: vim\n2: nvim\n3: nano\n4: emacs\nEditor :> ");
  scanf("%d", &choice);
  clear_buffer();

  const char *chosen_editor = editor(choice);
  if (strcmp(chosen_editor, "") == 0) {
    printf("Invalid editor selection.\n");
    return;
  }
  int lenght_of_command = strlen(username) + strlen(filename) + 50;
  char *command = malloc(lenght_of_command);
  snprintf(command, lenght_of_command, "%s %s/%s", chosen_editor, username, filename);
  if (command) {
    system(command);
    free(command);
  }
}

const char *editor(int i)
{
  const char *EditorList[NUM_EDITORS] = {"vim", "nvim", "nano", "emacs"};
  if (i >= 1 && i <= NUM_EDITORS) {
    return EditorList[i - 1];
  }
  return "";
}

