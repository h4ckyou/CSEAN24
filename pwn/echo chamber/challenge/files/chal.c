#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


typedef struct {
    char *shellcode;
    int size;
} shelly;


shelly *ptr;
uint8_t is_called = 0;


void setup(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


void read_int() {
    char input[100];

    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    input[strcspn(input, "\n")] = '\0';

    if (strchr(input, '-') != NULL) {
        fprintf(stdout, "You thing you smart huh??\n");
        exit(EXIT_FAILURE);
    }
    
    ptr->size = atoi(input);
}


int _(){
    void *dest;

    puts("Welcome ADMIN!");

    ptr = (shelly *)malloc(sizeof(shelly));
    if (ptr == NULL){
        perror("memory allocation failed");
        return 1;
    }

    puts("Give me some goodies and I'll consume it.\n");
    puts("Enter size of goodies:");
    read_int();
    
    if (ptr->size == 0 || ptr->size > 0x10) {
        fprintf(stdout, "Too bad I only like small things\n");
        exit(EXIT_FAILURE);
    }

    dest = mmap(NULL, 0x100, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (dest == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    puts("Super good!, Now give me some goodies");
    read(STDIN_FILENO, &ptr->shellcode, (unsigned char)ptr->size);

    puts("Time to consume it...\n");
    
    memcpy(dest, (char *)&ptr->shellcode + 0x10, (unsigned char)ptr->size);

    ((void (*)(void))dest)();

    return 0;

}


unsigned long long get_num() {
    char buf[24];
    read(STDIN_FILENO, buf, 15);
    return strtoul(buf, NULL, 10);
}


int menu(){
    char buf[24];
    int choice;

    puts("1. Read content");
    puts("2. Enable debug mode");
    puts("3. Exit Program");
    printf("> ");
    
    return get_num();
}


void read_content(){
    void *addr;

    printf("Enter address: ");
    read(STDIN_FILENO, &addr, sizeof(addr));

    printf("Content of address: ");
    write(STDOUT_FILENO, addr, 8);
    
    putchar(0xa);

    puts("Done.");
}


void debug(){
    void *tmp = &debug;
    void *tmp2 = &tmp;
    printf("frame: %p\n", __builtin_frame_address(0));
    printf("Not fully implemented.\n");
}


int backdoor(){
    char buf[40];
    void* addr;
    size_t nbytes;

    if (is_called == 0){
        is_called = 1;
    } else {
        printf("You've got just a shot do better!\n");
        return 1;
    }

    printf("Address: ");
    read(STDIN_FILENO, &addr, sizeof(addr));

    printf("Number of bytes: ");
    nbytes = get_num();

    if (nbytes > 8){
        printf("Don't you think this is too large?");
        return 1;
    }

    printf("Content: ");
    read(STDIN_FILENO, addr, 8);

    puts("Done.");
}


int challenge(){
    while (1) {
        int choice =  menu();

        switch (choice)
        {
        case 1:
            read_content();
            break;
        case 2:
            debug();
            break;
        case 3:
            exit(EXIT_SUCCESS);
            break;
        case 1337:
            backdoor();
            break;
        default:
            puts("Invalid choice");
            break;
        }
    }

}


int main(void){

    setup();
    challenge();

    return 0;
} 
