#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dlfcn.h>

#define MAX_COMMAND_LEN 1024

int main(int argc, char *argv[]) {
    printf("[sorun]\n");
    void *cmds = dlopen("core/cmd.so", RTLD_LOCAL | RTLD_LAZY);
    if (!cmds) {
        printf("[error][loading \"cmd.so\" failed]\n[exiting]\n");
        return 0;
    }
    
    int ret = 0;
    char command[MAX_COMMAND_LEN];
    char cmd[MAX_COMMAND_LEN];
    char args[MAX_COMMAND_LEN];
    
    do {
        printf("> ");
        fgets(command, MAX_COMMAND_LEN, stdin);
        command[strlen(command) - 1] = '\0';
        
        int i = 0;
        while (!isspace(command[i])) i++;
        command[i] = '\0';
        strcpy(cmd, command);
        i++;
        strcpy(args, &command[i]);
        
        int (*runcmd)(char *) = dlsym(cmds, cmd);
        if (runcmd != NULL) {
            ret = runcmd(args);
        }
        
    } while (strcmp(cmd, "quit") != 0 || ret != 0);
    
    printf("[closing]\n");
    dlclose(cmds);
    
    return 0;
}
