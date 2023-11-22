#include "listdinamis.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin array;
    array.A = (ElType *)malloc(InitialSize * sizeof(ElType));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free(array->A);
    array->Capacity = 0;
    array->Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyDinamis(ArrayDin array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthDinamis(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType GetDinamis(ArrayDin array, IdxType i){
    return (array.A[i]);
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacityDinamis(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAtDinamis(ArrayDin *array, ElType el, IdxType i){
    if (array->Neff >= array->Capacity) {
        // Jika kapasitas tidak cukup, alokasi ulang memori
        int newCapacity = array->Capacity * 2;
        ElType *newA = (ElType *)malloc(newCapacity * sizeof(ElType));
        for (int j = 0; j < array->Neff; j++) {
            newA[j] = array->A[j];
        }
        free(array->A);
        array->A = newA;
        array->Capacity = newCapacity;
    }

    for (int j = array->Neff; j > i; j--) {
        array->A[j] = array->A[j - 1];
    }
    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastDinamis(ArrayDin *array, ElType el){
    InsertAtDinamis(array, el, array->Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstDinamis(ArrayDin *array, ElType el){
    InsertAtDinamis(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAtDinamis(ArrayDin *array, IdxType i){
    for (int j = i; j < array->Neff - 1; j++) {
        array->A[j] = array->A[j + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLastDinamis(ArrayDin *array){
    DeleteAtDinamis(array, array->Neff-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAtDinamis(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    printf("[");
    for (int i = 0; i < array.Neff; i++)
    {
        printf("%d", array.A[i]);
        if (i < array.Neff - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    int i = 0;
    int j = array->Neff - 1;
    while (i < j) {
        ElType temp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = temp;
        i++;
        j--;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
    ArrayDin copy;
    copy.A = (ElType *)malloc(array.Capacity * sizeof(ElType));
    copy.Capacity = array.Capacity;
    copy.Neff = array.Neff;
    for (int i = 0; i < array.Neff; i++) {
        copy.A[i] = array.A[i];
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    for (int i = 0; i < array.Neff; i++) {
        if (array.A[i] == el) {
            return i; // Mengembalikan indeks pertama yang ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}
