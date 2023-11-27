#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *printThread(void *arg) {
    while (1) {
        printf("Printing...\n");
        sleep(1); // 출력을 느리게 하기 위한 임시 sleep
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, printThread, NULL);

    while (1) {
        char input[100];
        printf("Enter something: ");
        scanf("%s", input);
        printf("You entered: %s\n", input);
    }

    pthread_join(thread, NULL);
    return 0;
}




// cd /workspace/SeowonCProject/project/ && gcc ./test4.c -o /tmp/a.out -pthread -lm -ljson-c -lncurses && clear && /tmp/a.out