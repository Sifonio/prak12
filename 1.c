#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Отримано сигнал %d\n", sig);
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESETHAND;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESETHAND;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Натисніть Ctrl+C кілька разів...\n");

    while (1) {
        pause();
    }
    
    return 0;
}
//gcc -Wall 1.c -o 1