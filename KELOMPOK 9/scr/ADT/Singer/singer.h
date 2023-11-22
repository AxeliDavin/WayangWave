// singer.h

#ifndef singer_H
#define singer_H
#include <stdio.h>
#include "../boolean.h"
#include "../MesinKalimat/mesinkalimat.h"
#include "../Album/album.h"

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
void CreateEmptyMapSinger(Singer *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai NilMap */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapSinger(Singer M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai NilMap */

boolean IsFullMapSinger(Singer M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valtypeSinger ValueSinger(Singer M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMapSinger(Singer *M, keytype k, valtypeSinger v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMapSinger(Singer *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMapSinger(Singer M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif
