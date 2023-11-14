#include <stdio.h>
#include <stdlib.h>
#include "console.h"

int main(){
    boolean aktif = true;

    while(aktif == true){
        readInput();
        if(IsKataSama(currentWord.TabWord, "START")){ /*Kalo ga ada di Command list sama sekali*/
            aktif = false;
            STARTC();
        } else if (IsKataSama(currentWord.TabWord, "LIST COMMAND"/*Belom dibuat List command yang ada bisa dijalanin*/)) {/*Kalo ada di command list tapi belom boleh dijalanin*/
            printf("Command tidak bisa dieksekusi!\n");
        } else {/*Kalo input ga ada di command list sama sekali*/
            printf("Command tidak diketahui!\n");
        }
    }
}