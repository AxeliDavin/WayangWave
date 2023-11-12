#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    boolean aktif = true;

    while(aktif == true){
        readInput();
        if(IsKataSama(currentWord, "START")){ /*Kalo ga ada di Command list sama sekali*/
            aktif = false;
            STARTC();
        } else if (!IsKataSama(currentWord, "LIST COMMAND")) {/*Kalo ga ada di Command list sama sekali*/
            printf("Command tidak diketahui!\n");
        } else {/*Kalo ada di Command list tapi belom boleh dijalanin*/
            printf("Command tidak bisa dieksekusi!\n");
        }
    }
}