#include "mesinkarakter.h"
#include <stdio.h>

static FILE * pita;
static int retval;

int main(){
    printf("Masukkan input:\n");
    START();
    while (currentChar != MARK) {
        printf("Karakter yang terbaca: %c\n", currentChar);
        ADV();
    }


    char filename[] = "../../save/savefile.txt";
    printf("Membaca file %s . . .\n", filename);
    STARTFILE(filename);
    while (currentChar != MARK) {
        printf("Karakter yang terbaca: %c\n", currentChar);
        ADVFILE();
    }

    return 0;
}