/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../boolean.h"
#include "../MesinKalimat/mesinkalimat.h"
#include "../Song.h"

#define NilStack -1
#define MaxElStack 100
/* NilStack adalah stack dengan elemen kosong . */

typedef int infotypestack;
typedef int stackaddress;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
    Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
}contentStack;

typedef struct {
    contentStack buffer[CAPACITY];
    int IDXTOP;
} Stack;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).IDXTOP
#define     TOP(S) (S).buffer[(S).IDXTOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP berNilStackai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, contentStack val);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, CurrentSong* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */

#endif