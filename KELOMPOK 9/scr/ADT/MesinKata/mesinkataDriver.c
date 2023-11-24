#include "mesinkata.h"
#include <stdio.h>

boolean EndWord;

int main(){
    printf("Masukkan input: ");
    STARTWORD();

    printf("%s", currentWord.TabWord);
    

    // Untuk menginput
    printf("\nMasukkan input lagi: ");
    Word temp = takeInput();

    // Untuk menginput menggunakan setup default
    printf("Word to integer: %d\n", WordToInt(&temp));

    return 0;
}