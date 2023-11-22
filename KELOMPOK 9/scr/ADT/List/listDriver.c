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
    InsertAtList(&lagu, 4, 1);
    DisplayList(lagu);

    // Cek fungsi FirstIdx, LastIdx, Length
    printf("First Index: %d\n", FirstIdxList(lagu));
    printf("Last Index: %d\n", LastIdxList(lagu));
    printf("Panjang list: %d\n", LengthList(lagu));

    printf("Nilai elemen pertama: %d\n", GetList(lagu, FirstIdxList(lagu))); // Cek fungsi Get
    SetList(&lagu, FirstIdxList(lagu), 2); // Cek fungsi SetList
    printf("Nilai elemen pertama setelah perubahan: %d\n", GetList(lagu, FirstIdxList(lagu)));

    // Cek fungsi IsIdxValid
    if (IsIdxValidList(lagu, 120))
    {
        printf("Index 120 valid\n");
    }else{
        printf("Index 120 tidak valid\n");
    }

    // Cek fungsi IdxIdxEff
    if (IsIdxEffList(lagu, 4))
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
    DeleteAtList(&lagu, 1);
    DeleteFirstList(&lagu);
    DeleteLastList(&lagu);
    printf("Nilai list setelah di delete: ");
    DisplayList(lagu);
    
    // Cek fungsi Concat
    List L1, L2;
    MakeList(&L1);
    MakeList(&L2);
    InsertFirstList(&L1, 2);
    InsertFirstList(&L2, 20);
    printf("Hasil list gabungan L1 dan L2: ");
    List L3 = Concatlist(L1,L2);
    DisplayList(L3);
}

