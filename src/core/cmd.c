#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dlfcn.h>

int info(const char *args) {
    printf("currently supported commands:\n");
    printf("\t- info\n");
    printf("\t- help\n");
    printf("\t- quit\n");
    printf("\n");
    printf("version: dev\n");
    
    return 0;
}

int help(const char *args) {
    printf("Type commads to use sorun. More information by typing 'info'.\n");
    
    return 0;
}

int attach(const char *args) {
    printf("%s\n", args);
    return 0;
}

int detach(const char *args) {
    printf("%s\n", args);
    return 0;
}

int run(const char *args) {
    // TODO: more options to args
    void *so = dlopen(args, RTLD_LOCAL | RTLD_LAZY);
    if (!so) {
        printf("[error] Could not open %s.\n", args);
        return 1;
    }
    
    int ret = 0;
    int (*start)(int, char **) = dlsym(so, "start");
    if (!start) {
        printf("[error] Cannot execute \"start\".\n");
        dlclose(so);
        return 1;
    } else {
        printf("[executing]\n\n");
        ret = start(0, NULL);
        printf("\n[finished]\n");
    }
    
    dlclose(so);
    
    return ret;
}

int quit(const char *args) {
    return 0;
}
