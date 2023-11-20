/* File : playlist.h */
/* ADT Playlist menggunakan list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah pointer to char */

#ifndef playlist_H
#define playlist_H

#include "boolean.h"

#define Nil NULL

typedef char *infotype;
typedef char *name;
typedef struct tElmtlist *address;
typedef struct {
    infotype lagu;
    infotype album;
    infotype penyanyi;
} content;
typedef struct tElmtlist { 
	content info;
	address next;
} ElmtList;

typedef struct {
    name namePL;
	address First;
} Playlist;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(PL) ((PL).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyPlaylist (Playlist PL);
/* Mengirim true jika playlist kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyPlaylist (Playlist *PL);
/* I.S. sembarang             */
/* F.S. Terbentuk playlist kosong */

/****************** Manajemen Memori ******************/
address AlokasiPlaylist (content X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiPlaylist (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN Playlist ******************/
address SearchPlaylist (Playlist L, content X);
/* Mencari apakah ada elemen Playlist dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

content GetSongFromPlaylist(Playlist PL, int idx) {
/* Dapetin lagu dari Playlist*/
/* Udah include nama lagu, album, dan artisnya*/
}

content SetContent (infotype song, infotype album, infotype singer) {
/* Set data sebuah lagu menjadi tipe data content */
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (Playlist *L, content X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (Playlist *L, content X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (Playlist *L, content *X);
/* I.S. Playlist L tidak kosong  */
/* F.S. Elemen pertama Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (Playlist *L, content *X);
/* I.S. Playlist tidak kosong */
/* F.S. Elemen terakhir Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (Playlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (Playlist *L, address P, address Prec);
/* I.S. Prec pastilah elemen Playlist dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (Playlist *L, address P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (Playlist *L, address *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama Playlist sebelum penghapusan */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (Playlist *L, content X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen Playlist beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari Playlist dan di-dealokasi */
/* Jika tidak ada elemen Playlist dengan info(P)=X, maka Playlist tetap */
/* Playlist mungkin menjadi kosong karena penghapusan */
void DelLast (Playlist *L, address *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir Playlist sebelum penghapusan  */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (Playlist *L, address *Pdel, address Prec);
/* I.S. Playlist tidak kosong. Prec adalah anggota Playlist  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Playlist yang dihapus  */

/****************** PROSES SEMUA ELEMEN Playlist ******************/
void PrintInfoPlaylist (Playlist PL);
/* I.S. Playlist mungkin kosong */
/* F.S. Jika Playlist tidak kosong, isi Playlist dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Playlist kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */

int NbElmtPlaylist (Playlist PL);
/* Mengirimkan banyaknya elemen Playlist; mengirimkan 0 jika Playlist kosong */

/****************** PROSES TERHADAP PLAYLIST ******************/

void InversPlaylist (Playlist *L);
/* I.S. sembarang. */
/* F.S. elemen Playlist dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen Playlist, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (Playlist *PL1, Playlist *PL2, Playlist *PL3);
/* I.S. PL1 dan PL2 sembarang */
/* F.S. PL1 dan PL2 kosong, PL3 adalah hasil konkatenasi PL1 & PL2 */
/* Konkatenasi dua buah Playlist : PL1 dan PL2    */
/* menghasilkan PL3 yang baru (dengan elemen Playlist PL1 dan PL2) */
/* dan PL1 serta PL2 menjadi Playlist kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif