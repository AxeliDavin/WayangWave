#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    boolean aktif = true;

    while(aktif == true){
        readInput();
        // printf("%s\n", currentWord.TabWord);
        if(IsKataSama(currentWord.TabWord, "START")){ /*Kalo ga ada di Command list sama sekali*/
            // aktif = false;
            STARTC();
        } else if (!IsKataSama(currentWord.TabWord, "LIST COMMAND")) {/*Kalo ga ada di Command list sama sekali*/
            printf("Command tidak diketahui!\n");
        } else {/*Kalo ada di Command list tapi belom boleh dijalanin*/
            printf("Command tidak bisa dieksekusi!\n");
        }
    }
}