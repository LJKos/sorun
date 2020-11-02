#include <stdio.h>

void test_fun() {
    printf("test function\n");
}

int start(int argc, char *argv[]) {
    printf("Hello world!\n");
    
    test_fun();
    
    return 0;
}
