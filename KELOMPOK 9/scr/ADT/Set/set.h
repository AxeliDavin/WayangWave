#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilSet 0
#define MaxElSet 100

typedef int infotypeset;
typedef int setaddress;
typedef char namalagutype;
typedef int IdAlbumType;

typedef struct {
    namalagutype namalagu;
    IdAlbumType IdAlbum;
} infotypeset;

typedef struct
{
    infotypeset Elements[MaxElSet];
    setaddress Count;
} Set;

/* Definisi Set S kosong : S.Count = NilSet */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count berNilSetai NilSet */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count berNilSetai NilSet */

boolean IsFullSet(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count berNilSetai MaxElSet */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotypeset Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotypeset Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotypeset Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif