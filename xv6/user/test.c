#include "user/user.h"

int main() {
    int counter = 0;
    for(volatile long i = 0; i < 100000000; i++){
        counter ++;
    }
    printf("%d", counter);
}