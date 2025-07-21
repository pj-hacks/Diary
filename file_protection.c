#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_protection.h"
//#include "utility.h"



extern char *user_name;

int fileEncryption( char * password)
{

    const char *var_name = user_name;
    const char *user_password = password;   
    char *shell = getenv("SHELL");
    char command[256];

    if (shell == NULL){
    printf("Couldn't detect shell. Using a fallback method.\n");
    goto fallback;
}
    if (strstr(shell, "bash")){
snprintf(command, sizeof(command), "echo 'export %s=%s' >> ~/.bashrc", var_name, user_password);
}
    else if (strstr(shell, "zsh")){
snprintf(command, sizeof(command), "echo 'export %s=%s' >> ~/.zshrc", var_name, user_password);
}
    else if(strstr(shell, "fish")){
    snprintf(command, sizeof(command), "echo 'set -x %s %s' >> ~/.config/fish/config.fish", var_name, user_password);
}
    else if(strstr(shell, "tcsh") || strstr(shell, "csh")){
    snprintf(command, sizeof(command), "echo 'setenv %s %s' >> ~/.tcshrc", var_name, user_password);
}
    else {
    printf("Unknown shell: %s. Using a fallback method.\n", shell);
    goto fallback;
}
    if (system(command) == 0) {
    printf("%s set in your shell's config. Run 'source' on the file or restart your terminal. \n", var_name);
}
    else{
    printf("Failed to set %s,\n", var_name);
    return 1;
}
return 0;

fallback:
    printf("Run this manually: expory %s = %s \n", var_name, user_password);
    return 0;
}


int fileDecryption( char *userPassword)
{

    char *user_password = getenv(user_name); //This gets the user password saved in the environmental variable
    if (user_password == NULL) {
        printf("Error: environmental variable '%s' not found.\n", user_name);
        return 1;
    }


    if ( strcmp(userPassword, user_password) != 0){  //This compare two strings to see if they are equal
        printf("\ninitial_password not matching with first password entered.\n");
        return 1;
    }
    else{
        printf("\nSuccessfully created a password lock.\nDo not share your password with anyone not even your friends.\n");
    }

    return 1;

}

