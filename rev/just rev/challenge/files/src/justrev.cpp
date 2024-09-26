#include <iostream>
#include <cstring>

#define size 56

int enc_flag[size + 1] = {
    0xc6, 0x20, 0x6a, 0x29, 0x0c, 0x3b, 0x0c, 0x69, 0xba, 0x6a, 
    0xba, 0x69, 0xda, 0x6d, 0xbb, 0x3e, 0xeb, 0x2f, 0xb6, 0x3e,
    0x8b, 0x31, 0xb6, 0x2f, 0x0c, 0x30, 0xca, 0x6a, 0xc6, 0x2b,
    0xc6, 0x27, 0x0c, 0x2b, 0xb6, 0x2d, 0xca, 0x26, 0x1b, 0x3e,
    0xcb, 0x69, 0xaa, 0x3e, 0x6a, 0x6d, 0x9b, 0x22, 0xcb, 0x29, 
    0x1b, 0x70, 0xab, 0x3c, 0xcb, 0x2a, 0x00
    };


void swap(char *buf, int n) {
    char tmp_buf[n];

    for (int i = 0; i < n - 1; i += 2) {
        char tmp1 = buf[i];
        char tmp2 = buf[i + 1];
        tmp_buf[i] = tmp2;
        tmp_buf[i + 1] = tmp1;
    }

    for (int i = 0; i < n; i++) {
        buf[i] = tmp_buf[i];
    }
}


int rotate_byte(int byte, int shift) {
    int r = ((byte << shift) | (byte >> (8 - shift))) & 0xFF;
    return r;
}


void reverse(char *buf, int n) {
    char tmp_buf[n];

    for (int i = 0; i < n; i++) {
        tmp_buf[i] = buf[n - 1 - i];
    }

    for (int i = 0; i < n; i++) {
        buf[i] = tmp_buf[i];
    }
}


int mangle(char *buf, int n) {
    char tmp_buf[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (j % 2 == 0) {
            int r = (~((rotate_byte(buf[i] ^ 0x40, 4) - 0xcafe) & 0xff)) & 0xff;
            tmp_buf[i] = r;
        } else {
            int r = (~(((buf[i] + 0x20) - 0xbabe) & 0xff)) & 0xff;
            tmp_buf[i] = r;
        }

        j += 1;
    }

    for (int i = 0; i < n; i++) {
        buf[i] = tmp_buf[i];
    }

    return j;
}

int main(void){
    char input[size + 1];
    int n;

    std::cout << "Reversing is pain but can you find your way around this?" << std::endl;
    std::cout << "Flag: ";
    std::cin >> input;
    n = strlen(input);

    swap(input, n);
    reverse(input, n);
    mangle(input, n);

    for (int i = 0; i < n; i++){
        // std::cout << input[i] << static_cast<char>(enc_flag[i]) << std::endl;
        if (input[i] != static_cast<char>(enc_flag[i])){
            std::cout << "Wrong." << std::endl;
            return 0;
        }
    }

    std::cout << "Correct!" << std::endl;
    return 0;
} 
