#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "utility.h"



int remove_newline(char *input)
{
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
  }

  return 0;
}

void clear_buffer()
{
  int c;
  while((c = getchar()) != '\n' );
}

char *get_current_directory(void)
{
  char *cwd = NULL;

#ifdef __linux__
  cwd = getcwd(NULL, 0);  // GNU extension: auto allocates exact size
#else
  cwd = malloc(PATH_MAX);
  if (cwd != NULL && getcwd(cwd, PATH_MAX) == NULL) {
    free(cwd);
    cwd = NULL;
  }
#endif

  return cwd;
}
