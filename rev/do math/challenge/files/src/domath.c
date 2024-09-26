#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define ROWS 10
#define COLS 5
#define check 0x20578

int encoded[ROWS][COLS] = {
    {48138, 43700, 48610, 55386, 41354},
    {45660, 38441, 43791, 52243, 37258},
    {40387, 36162, 35800, 43957, 34248},
    {43944, 38721, 46945, 49989, 38896},
    {47623, 40923, 42940, 51410, 41681},
    {47625, 41417, 45866, 52662, 41045},
    {46413, 41660, 45539, 52571, 40967},
    {36860, 34670, 38049, 43983, 34919},
    {44205, 39322, 48087, 51048, 38335},
    {45885, 38844, 49276, 52596, 38116}
};


int key[5][5] = {
    {99, 115, 101, 97, 110},
    {45, 99, 116, 102, 45},
    {105, 115, 45, 116, 104},
    {101, 45, 98, 101, 115},
    {116, 45, 102, 114, 33}
};


void correct(){
    puts("You escaped the matrix (-^=^-)\n Good job");

}


void wrong(){
    puts("Oops! Try harder \\o/ \n");
}


int compute() {
    char value[SIZE+1] = {0};
    int matrix[ROWS][COLS];

    read(0, value, SIZE);

    /// convert the value in the value array to a 10x5 matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = value[i * COLS + j];
        }
    }
 
    // matrix multiplication on the matrix with the 5x5 key matrix
    int result[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += matrix[i][k] * key[k][j];
            }
        }
    }

    // for (int i = 0; i < ROWS; i++){
    //     for (int j = 0; j < COLS; j++){
    //         printf("%d:%d\n", result[i][j], encoded[i][j]);
    //     }
    // }

    // compare matmul value with some hardcoded constants
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (result[i][j] != encoded[i][j]) {
                return 1; 
            }
        }
    }

    return 0;
}


int main() {
    int i, j, k;
    int c;
    int value[4];

    int sum = 0;

    for (c = 0; c < 4; c++){
         scanf("%d", &value[c]);
    }

    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                    sum += key[j][k] * value[i];
            }
        }
    }

    if (sum == check) {

        printf("passed check!\n");

        if (compute() == 0) {
            correct();
            return 0;
        }
        else {
            wrong();
            return -1;
        }
    } 
    else {
        wrong();
        return -1;
    }
    
}
