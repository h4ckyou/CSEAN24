#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


int backdoor(__uint16_t key1, __uint16_t key2) {
    char flag[40];
    FILE *stream = fopen("flag.txt", "r");

    if (stream == NULL) {
        puts("Error opening flag.txt, contact admin!");
        return 1;
    }

    if (key1 == 0xdead && key2 == 0xbeef) {
        size_t bytesRead = fread(flag, sizeof(char), sizeof(flag) - 1, stream);
        flag[bytesRead] = '\0';
        puts(flag);
    } else {
        puts("Invalid keys");
    }

    fclose(stream);
    
    return 0;
}

void helper(){
    asm(
        "pop %rdi\n"
        "pop %rsi\n"
        "ret\n"
    );
}


int feedback(){
    char buf[40] = {0};

    puts("What's your final complaint...");
    read(0, buf, 0x60);

    puts("Ok thanks for your opinion");

    return 0;
}


int challenge(){
    char choice[5];

    puts("Welcome to part one of the first pwn challenge");
    puts("What's a CTF without a beginners's pwn :)");
    puts("Would you like to give any feedback?");
    scanf("%4s", choice);
    getchar();

    if (strncmp(choice, "yes", 3) == 0) {
        feedback();
    } else {
        puts("Goodbye");
        return 1;
    }

    return 0;
}


int main(void){

    init();
    challenge();

    return 0;
}
