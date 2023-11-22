// singer.h

#ifndef singer_H
#define singer_H
#include <stdio.h>
#include "../boolean.h"
#include "../MesinKalimat/mesinkalimat.h"
#include "../album.h"

// MODUL MAP SINGER

#define NilMap 0
#define MaxElMap 20

typedef Kalimat keytype;
typedef SetLagu valtypeSinger;
typedef int address;

typedef struct {
	keytype NamaPenyanyi;
	valtypeSinger isiAlbum; // List Album yang dimiliki penyanyi
} infotypeSinger;

// 1
typedef struct {
	infotypeSinger PenyanyiAlbum[MaxElMap];
	address NEff;
} Singer;

typedef struct
{
	Singer Singer[50];
} ListSinger;

/* Definisi Map M kosong : M.Count = NilMap */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Album *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai NilMap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Album M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai NilMap */

boolean IsFullMap(Album M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valtypeAlbum Value(Album M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Album *M, keytype k, valtypeAlbum v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Album *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Album M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif
