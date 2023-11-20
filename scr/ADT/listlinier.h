/* File : ListLinierlinier.h */
/* contoh ADT ListLinier berkait dengan representasi fisik pointer  */
/* Representasi listlinieraddress dengan pointer */
/* infotype adalah integer */

#ifndef ListLinierlinier_H
#define ListLinierlinier_H

#include "boolean.h"

#define Nil NULL

typedef int infotype;
typedef struct tElmtListLinier *listlinieraddress;
typedef struct tElmtListLinier { 
	infotype info;
	listlinieraddress next;
} ElmtListLinier;
typedef struct {
	listlinieraddress First;
} ListLinier;

/* Definisi ListLinier : */
/* ListLinier kosong : First(L) = Nil */
/* Setiap elemen dengan listlinieraddress P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListLinier : jika listlinieraddressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST ListLinier KOSONG ******************/
boolean IsEmptyListLinier (ListLinier L);
/* Mengirim true jika ListLinier kosong */

/****************** PEMBUATAN ListLinier KOSONG ******************/
void CreateEmptyListLinier (ListLinier *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListLinier kosong */

/****************** Manajemen Memori ******************/
listlinieraddress Alokasi (infotype X);
/* Mengirimkan listlinieraddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka listlinieraddress tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (listlinieraddress *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian listlinieraddress P */

/****************** PENCARIAN SEBUAH ELEMEN ListLinier ******************/
listlinieraddress SearchListLinier (ListLinier L, infotype X);
/* Mencari apakah ada elemen ListLinier dengan info(P)= X */
/* Jika ada, mengirimkan listlinieraddress elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListLinier *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListLinier *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListLinier di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListLinier *L, infotype *X);
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListLinier *L, infotype *X);
/* I.S. ListLinier tidak kosong */
/* F.S. Elemen terakhir ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListLinier (ListLinier *L, listlinieraddress P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-listlinieraddress P sebagai elemen pertama */
void InsertAfter (ListLinier *L, listlinieraddress P, listlinieraddress Prec);
/* I.S. Prec pastilah elemen ListLinier dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastListLinier (ListLinier *L, listlinieraddress P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListLinier *L, listlinieraddress *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama ListLinier sebelum penghapusan */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListLinier *L, infotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListLinier berlistlinieraddress P, dengan info(P)=X  */
/* Maka P dihapus dari ListLinier dan di-dealokasi */
/* Jika tidak ada elemen ListLinier dengan info(P)=X, maka ListLinier tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
void DelLast (ListLinier *L, listlinieraddress *P);
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListLinier sebelum penghapusan  */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListLinier *L, listlinieraddress *Pdel, listlinieraddress Prec);
/* I.S. ListLinier tidak kosong. Prec adalah anggota ListLinier  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListLinier yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListLinier ******************/
void PrintInfo (ListLinier L);
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika ListLinier tidak kosong, isi ListLinier dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListLinier kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (ListLinier L);
/* Mengirimkan banyaknya elemen ListLinier; mengirimkan 0 jika ListLinier kosong */

/*** Prekondisi untuk Max/Min/rata-rata : ListLinier tidak kosong ***/
infotype Max (ListLinier L);
/* Mengirimkan nilai info(P) yang maksimum */
listlinieraddress AdrMax (ListLinier L);
/* Mengirimkan listlinieraddress P, dengan info(P) yang bernilai maksimum */
infotype Min (ListLinier L);
/* Mengirimkan nilai info(P) yang minimum */
listlinieraddress AdrMin (ListLinier L);
/* Mengirimkan listlinieraddress P, dengan info(P) yang bernilai minimum */
float Average (ListLinier L);
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP ListLinier ******************/

void InversListLinier (ListLinier *L);
/* I.S. sembarang. */
/* F.S. elemen ListLinier dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen ListLinier, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (ListLinier *L1, ListLinier *L2, ListLinier *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah ListLinier : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen ListLinier L1 dan L2) */
/* dan L1 serta L2 menjadi ListLinier kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif