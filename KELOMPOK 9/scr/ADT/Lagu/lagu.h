// lagu.h

#ifndef lagu_H
#define lagu_H
#include <stdio.h>
#include "../MesinKalimat/mesinkalimat.h"
#include "../boolean.h"

/* MODUL SET LAGU
Deklarasi set yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSet 0
#define MaxElSet 100

typedef int setaddress;
typedef struct {   
   Kalimat JudulLagu[MaxElSet];
  int Count;
} SetLagu;


/* Definisi Set S kosong : S.Count = NilSet */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(SetLagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count berNilSetai NilSet */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(SetLagu S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count berNilSetai NilSet */

boolean IsFullSet(SetLagu S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count berNilSetai MaxElSet */

/* ********** Operator Dasar Set ********* */
void Insert(SetLagu *S, Kalimat Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(SetLagu *S, Kalimat Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(SetLagu S, Kalimat Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif