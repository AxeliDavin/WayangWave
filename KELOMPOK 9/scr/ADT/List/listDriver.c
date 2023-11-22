#include "list.h"
#include <stdio.h>

int main(){
    List lagu;
    MakeList(&lagu); // Cek fungsi MakeList
    if (IsEmptyList(lagu))
    {
        printf("True Empty\n");  // Print jika list lagu kosong
    }
    
    // Cek fungsi Insert
    InsertFirstList(&lagu, 9);
    InsertLastList(&lagu, 10);
    InsertAt(&lagu, 4, 1);
    DisplayList(lagu);

    // Cek fungsi FirstIdx, LastIdx, Length
    printf("First Index: %d\n", FirstIdx(lagu));
    printf("Last Index: %d\n", LastIdx(lagu));
    printf("Panjang list: %d\n", Length(lagu));

    printf("Nilai elemen pertama: %d\n", Get(lagu, FirstIdx(lagu))); // Cek fungsi Get
    SetList(&lagu, FirstIdx(lagu), 2); // Cek fungsi SetList
    printf("Nilai elemen pertama setelah perubahan: %d\n", Get(lagu, FirstIdx(lagu)));

    // Cek fungsi IsIdxValid
    if (IsIdxValid(lagu, 120))
    {
        printf("Index 120 valid\n");
    }else{
        printf("Index 120 tidak valid\n");
    }

    // Cek fungsi IdxIdxEff
    if (IsIdxEff(lagu, 4))
    {
        printf("Index 4 efektif\n");
    }else{
        printf("Index 4 tidak efektif\n");
    }

    // Cek fungsi SearchList
    if (!SearchList(lagu, 1000))
    {
        printf("False Element\n");
    }

    printf("Nilai list sebelum didelete: ");
    DisplayList(lagu);

    // Cek fungsi Delete
    DeleteAt(&lagu, 1);
    DeleteFirst(&lagu);
    DeleteLast(&lagu);
    printf("Nilai list setelah di delete: ");
    DisplayList(lagu);
    
    // Cek fungsi Concat
    List L1, L2;
    MakeList(&L1);
    MakeList(&L2);
    InsertFirstList(&L1, 2);
    InsertFirstList(&L2, 20);
    printf("Hasil list gabungan L1 dan L2: ");
    List L3 = Concat(L1,L2);
    DisplayList(L3);
}

