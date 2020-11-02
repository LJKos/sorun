#include <stdio.h>

void test_fun() {
    printf("test fun\n");
}

int start(int argc, char *argv[]) {
    printf("Hello sorun!\n");
    //printf("argc: %d\n", argc);
    //printf("argv[0]: %s\n", argv[0]);
    
    test_fun();
    
    return 0;
}
