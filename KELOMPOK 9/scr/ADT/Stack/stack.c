#include <stdio.h>
#include "../boolean.h"
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP berNilStackai NilStack */
{
    (*S).IDXTOP = -1;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==NilStack);
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */
{
    return (Top(S)==MaxElStack-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, contentStack val)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if ((*S).IDXTOP == -1)
    {
        Top(*S) = 0;
        InfoLagu(*S) = JudulLagu;
        InfoAlbum(*S) = NamaAlbum;
        InfoPenyanyi(*S) = NamaPenyanyi;
        
    }
    else
    {
        if ((*S).IDXTOP < 50-1) {
            Top(*S)++;
            InfoLagu(*S) = JudulLagu;
            InfoAlbum(*S) = NamaAlbum;
            InfoPenyanyi(*S) = NamaPenyanyi;
        }
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, CurrentSong* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X).JudulLagu = (*S).JudulLagu[(*S).IDXTOP];
    (*X).NamaAlbum = (*S).NamaAlbum[(*S).IDXTOP];
    (*X).NamaPenyanyi = (*S).NamaPenyanyi[(*S).IDXTOP];
    Top(*S) -= 1;
}