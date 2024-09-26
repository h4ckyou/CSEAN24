#include <stdio.h>

void getflag(void)
__attribute__((destructor));

int main(){
    puts("This program does nothing.");
    return 0;
}

void getflag(void){
    __asm__(".intel_syntax noprefix;\
    xor r8, r8;\
    mov r8, 0x637466;\
    xor rdi, rdi;\
    mov rdi, 0x63101107;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x6e4e1712;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x66180757;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x6d131855;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x5f1b4414;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x5f061a05;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x721a0412;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x31531a39;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x680a1002;\
    xor rdi, r8;\
    xor rdi, rdi;\
    mov rdi, 0x330d551b;\
    xor rdi, r8;\
    .att_syntax;");
}
