#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    boolean aktif = true;

    while(aktif == true){
        printf(">> ");
        START();
        /*belom tapi baru generalnya*/
        if(IsKataSama(currentWord, "START")){ /*Kalo ga ada di Command list sama sekali*/
            aktif = false;
            STARTC();
        } else if (!IsKataSama(currentWord, START)) {/*Kalo ga ada di Command list sama sekali*/
            printf("Command tidak diketahui!");
        } else {/*Kalo ada di Command list tapi belom boleh dijalanin*/
            printf("Command tidak bisa dieksekusi!");
        }
    }
}

