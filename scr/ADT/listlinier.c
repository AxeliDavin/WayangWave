/* File : ListLinier.C */
/* contoh ADT ListLinier berkait dengan representasi fisik pointer  */
/* Representasi listlinieraddress dengan pointer */
/* infotype adalah integer */

#include "stdio.h"
#include "stdlib.h"
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST ListLinier KOSONG ******************/
boolean IsEmptyListLinier (ListLinier L)
/* Mengirim true jika ListLinier kosong */
{
  return First(L) == Nil;
}

/****************** PEMBUATAN ListLinier KOSONG ******************/
void CreateEmptyListLinier (ListLinier *L)
/* I.S. sembarang             */
/* F.S. Terbentuk ListLinier kosong */
{
  First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
listlinieraddress Alokasi (infotype X)
/* Mengirimkan listlinieraddress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka listlinieraddress tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  listlinieraddress P = (listlinieraddress) malloc(1 * sizeof (ElmtListLinier));
  if (P != Nil) {
    Info(P) = X;
    Next(P) = Nil;
    return P;
  } {
    return Nil;
  }
}

void Dealokasi (listlinieraddress *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian listlinieraddress P */
{
  free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN ListLinier ******************/
listlinieraddress SearchListLinier (ListLinier L, infotype X)
/* Mencari apakah ada elemen ListLinier dengan Info(P)= X */
/* Jika ada, mengirimkan listlinieraddress elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
  listlinieraddress P;
  boolean bFound = false;

  if (!IsEmptyListLinier(L)) {
    P = First(L);
    while (!bFound && P != Nil) {
      if (X == Info(P)) {
        bFound = true;
      } else {
        P = Next(P);
      }
    }

    if (bFound) {
      return P;
    } else {
      return Nil;
    }

  } else {
    return Nil;
  }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListLinier *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
  listlinieraddress P = Alokasi(X);
  if (P != Nil) {
    InsertFirstListLinier(L, P);
  }
}

void InsVLast (ListLinier *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListLinier di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
  listlinieraddress P = Alokasi(X);
  if (P != Nil) {
    InsertLastListLinier(L, P);
  }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListLinier *L, infotype *X)
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
  listlinieraddress P = First(*L);
  *X = Info(P);
  First(*L) = Next(P);
  Dealokasi(&P);
}

void DelVLast (ListLinier *L, infotype *X)
/* I.S. ListLinier tidak kosong */
/* F.S. Elemen terakhir ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
  listlinieraddress P = First(*L);
  listlinieraddress Prec = Nil;

  while (Next(P) != Nil) {
    Prec = P;
    P = Next(P);
  }

  *X = Info(P);
  if (Prec != Nil) {
    Next(Prec) = Nil;
  } else {
    First(*L) = Nil;
  }
  Dealokasi(&P);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListLinier (ListLinier *L, listlinieraddress P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-listlinieraddress P sebagai elemen pertama */
{
  Next(P) = First(*L);
  First(*L) = P;
}

void InsertAfter (ListLinier *L, listlinieraddress P, listlinieraddress Prec)
/* I.S. Prec pastilah elemen ListLinier dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
  Next(P) = Next(Prec);
  Next(Prec) = P;
}

void InsertLastListLinier (ListLinier *L, listlinieraddress P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
  listlinieraddress Last;

  if (IsEmptyListLinier(*L)) {
    InsertFirstListLinier(L, P);
  } else {
    Last = First(*L);
    while (Next(Last) != Nil) {
      Last = Next(Last);
    }
    InsertAfter(L, P, Last);
  }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListLinier *L, listlinieraddress *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama ListLinier sebelum penghapusan */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
  *P = First(*L);
  First(*L) = Next(First(*L));
  Next(*P) = Nil;
}

void DelP (ListLinier *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListLinier berlistlinieraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ListLinier dan di-dealokasi */
/* Jika tidak ada elemen ListLinier dengan Info(P)=X, maka ListLinier tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
{
  listlinieraddress Prec;
  listlinieraddress P;
  boolean bFound = false;

  if (!IsEmptyListLinier(*L)) {
    if (X == Info(First(*L))) {
      DelFirst(L, &P);
      Dealokasi(&P);
    } else {
      P = First(*L);
      while (!bFound && P != Nil) {
        if (Info(P) == X) {
          bFound = true;
        } else {
          Prec = P;
          P = Next(P);
        }
      }

      if (bFound) {
        DelAfter(L, &P, Prec);
        Dealokasi(&P);
      }
    }
  }
}

void DelLast (ListLinier *L, listlinieraddress *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListLinier sebelum penghapusan  */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
  listlinieraddress Last = First(*L);
  listlinieraddress PrecLast = Nil;

  while (Next(Last) != Nil) {
    PrecLast = Last;
    Last = Next(Last);
  }

  *P = Last;
  if (PrecLast == Nil) {
    First(*L) = Nil;
  } else {
    Next(PrecLast) = Nil;
  }
}

void DelAfter (ListLinier *L, listlinieraddress *Pdel, listlinieraddress Prec)
/* I.S. ListLinier tidak kosong. Prec adalah anggota ListLinier  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListLinier yang dihapus  */
{
  *Pdel = Next(Prec);
  Next(Prec) = Next(Next(Prec));
  Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN ListLinier ******************/
void PrintInfo (ListLinier L)
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika ListLinier tidak kosong, isi ListLinier dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListLinier kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
{
  listlinieraddress P;
  boolean isFirst = true;

  printf("[");
  if (!IsEmptyListLinier(L)) {
    P = First(L);
    while (P != Nil) {
      if (!isFirst) {
        printf(",");
      }
      printf("%d", Info(P));
      isFirst = false;

      P = Next(P);
    }
  }
  printf("]\n");


}
int NbElmt (ListLinier L)
/* Mengirimkan banyaknya elemen ListLinier; mengirimkan 0 jika ListLinier kosong */
{
  int cnt = 0;
  listlinieraddress P;

  if (!IsEmptyListLinier(L)) {
    P = First(L);
    while (P != Nil) {
      cnt++;
      P = Next(P);
    }
  }

  return cnt;
}

/*** Prekondisi untuk Max/Min/rata-rata : ListLinier tidak kosong ***/
infotype Max (ListLinier L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
  infotype max_temp = Info(First(L));
  listlinieraddress P = Next(First(L));
  while (P != Nil) {
    if (Info(P) > max_temp) {
      max_temp = Info(P);
    }
    P = Next(P);
  }

  return max_temp;
}

listlinieraddress AdrMax (ListLinier L)
/* Mengirimkan listlinieraddress P, dengan info(P) yang bernilai maksimum */
{
  listlinieraddress PMax = First(L);
  listlinieraddress P = Next(First(L));
  while (P != Nil) {
    if (Info(P) > Info(PMax)) {
      PMax = P;
    }
    P = Next(P);
  }

  return PMax;
}

infotype Min (ListLinier L)
/* Mengirimkan nilai info(P) yang minimum */
{
  infotype min_temp = Info(First(L));
  listlinieraddress P = Next(First(L));
  while (P != Nil) {
    if (Info(P) < min_temp) {
      min_temp = Info(P);
    }
    P = Next(P);
  }

  return min_temp;
}

listlinieraddress AdrMin (ListLinier L)
/* Mengirimkan listlinieraddress P, dengan info(P) yang bernilai minimum */
{
  listlinieraddress PMin = First(L);
  listlinieraddress P = Next(First(L));
  while (P != Nil) {
    if (Info(P) < Info(PMin)) {
      PMin = P;
    }
    P = Next(P);
  }

  return PMin;
}

float Average (ListLinier L)
/* Mengirimkan nilai rata-rata info(P) */
{
	infotype sum = 0;
	int count = 0;
	listlinieraddress P = First(L);
	
	while (P != Nil) {
		sum += Info(P);
		count++;
		P = Next(P);
	}
	return sum * 1.0 / count;
}

/****************** PROSES TERHADAP ListLinier ******************/
void InversListLinier (ListLinier *L)
/* I.S. sembarang. */
/* F.S. elemen ListLinier dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen ListLinier, tanpa melakukan alokasi/dealokasi. */
{
	listlinieraddress P;
	listlinieraddress Prec = Nil;
	listlinieraddress Succ;
	
	if (!IsEmptyListLinier(*L)) {
		P = First(*L);
		while (P != Nil) {
			Succ = Next(P);
			Next(P) = Prec;
			Prec = P;
			P = Succ;
		}
		First(*L) = Prec;
	}
}


void Konkat1 (ListLinier *L1, ListLinier *L2, ListLinier *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah ListLinier : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen ListLinier L1 dan L2) */
/* dan L1 serta L2 menjadi ListLinier kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
  listlinieraddress Last1;

  CreateEmptyListLinier(L3);
  if (IsEmptyListLinier(*L1)) {
    First(*L3) = First(*L2);
  } else {
    First(*L3) = First(*L1);
    Last1 = First(*L1);
    while (Next(Last1) != Nil) {
      Last1 = Next(Last1);
    }
    Next(Last1) = First(*L2);
  }

  First(*L1) = Nil;
  First(*L2) = Nil;
}