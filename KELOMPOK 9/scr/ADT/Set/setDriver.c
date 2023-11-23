#include "set.h"
#include <stdio.h>

int main(){
    Set lagu;
    CreateEmptySet(&lagu); //Fungsi createemptyset

    if (IsEmptySet(lagu)){
        printf("Kosong\n"); //Tes IsEmptySet
    }

    infotypeset val = 1;
    infotypeset val1 = 2;
    infotypeset val2 = 3;
    infotypeset val3 = 4;
    infotypeset val4 = 5;
    infotypeset val5 = 6;
    infotypeset val6 = 7;
    infotypeset val7 = 8;
    infotypeset val8 = 9;
    infotypeset val9 = 10;
    infotypeset val10 = 11;
    infotypeset val11 = 12;
    infotypeset val12 = 13;
    infotypeset val13 = 14;
    infotypeset val14 = 15;
    infotypeset val15 = 16;
    
    Insert(&lagu, val);
    Insert(&lagu, val1);
    Insert(&lagu, val2);
    Insert(&lagu, val3);
    Insert(&lagu, val4);
    Insert(&lagu, val5);
    Insert(&lagu, val6);
    Insert(&lagu, val7);
    Insert(&lagu, val8);
    Insert(&lagu, val9);
    Insert(&lagu, val10);
    Insert(&lagu, val11);
    Insert(&lagu, val12);
    Insert(&lagu, val13);
    Insert(&lagu, val14);
    Insert(&lagu, val15);

    if (IsFullSet(lagu)){
        printf("Penuh\n"); // Tes IsFullSet
    }

    if (IsMemberSet(lagu, val10)){
        printf("Ada"); //Tes IsMemberSet
    }

    Delete(&lagu, val10); //Tes Delete

    if (IsMemberSet(lagu, val10)){
        printf("Ada"); //Tes IsMemberSet, kalo keprint berarti salah
    }
}

