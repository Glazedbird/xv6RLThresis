#include "user/user.h"

int main() {
    printf("before\n");
    vmprint();
    sbrk(1);
    printf("after\n");
    vmprint();
    exit(0);
}