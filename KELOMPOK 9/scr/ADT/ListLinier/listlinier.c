#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLinked (ListLinier L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLinked (ListLinier *L)
/* I.S. sembarang             */
/* F.S. Terbentuk ListLinier kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiLinked (infoType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    ElmtList *value = (ElmtList *) malloc(sizeof (ElmtList));

    if (value != Nil)
    {
        Info(value) = X;
        Next(value) = Nil;
        return value;
    } else
    {
        return Nil;
    }
}

void DealokasiLinked (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN ListLinier ******************/
boolean SearchLinked (ListLinier L, infoType X)
/* Mencari apakah ada elemen ListLinier dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address p = First(L);

    if (IsEmptyLinked(L))
    {
        return false;
    } else
    {
        while (p != Nil)
        {
            if (isKalimatEqual(JudulLagu(p), X.JudulLagu) && isKalimatEqual(NamaAlbum(p), X.NamaAlbum) && isKalimatEqual(NamaPenyanyi(p), X.NamaPenyanyi))
            {
                return true;
            } else
            {
                p = Next(p);
            }
        }

        return false;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
// Bedanya sama yang address : Elemennya harus dialokasi terlebih dahulu
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLinked (ListLinier *L, infoType X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address p = AlokasiLinked(X);

    if (p != Nil)
    {
        InsertFirstLinked(L, p);
    }
}

void InsVLastLinked (ListLinier *L, infoType X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListLinier di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address p = AlokasiLinked(X);

    if (p != Nil)
    {
        InsertLastLinked(L, p);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLinked (ListLinier *L, infoType *X)
/* I.S. ListLinier L tidak kosong  */
/* F.S. Elemen pertama ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address p;
    DelFirstLinked(L, &p);
    *X = Info(p);
    DealokasiLinked(&p);
}

void DelVLastLinked (ListLinier *L, infoType *X)
/* I.S. ListLinier tidak kosong */
/* F.S. Elemen terakhir ListLinier dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address p;
    DelLastLinked(L, &p);
    *X = Info(p);
    DealokasiLinked(&p);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLinked (ListLinier *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfterLinked (ListLinier *L, address P, address Prec)
/* I.S. Prec pastilah elemen ListLinier dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLastLinked (ListLinier *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address p = First(*L);

    if (IsEmptyLinked(*L))
    {
        InsertFirstLinked(L, P);
    } else
    {
        while (Next(p) != Nil)
        {
            p = Next(p);
        }

        // Next(p) = Nil, artinya p sudah menunjuk ke elemen terakhir ListLinier L
        Next(p) = P;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLinked (ListLinier *L, address *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen pertama ListLinier sebelum penghapusan */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(*P);
}

void DelPLinked (Kalimat namaPlaylist, ListLinier *L, int idLagu) // ubah remove lagu dr playListLinier
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListLinier beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari ListLinier dan di-dealokasi */
/* Jika tidak ada elemen ListLinier dengan info(P)=X, maka ListLinier tetap */
/* ListLinier mungkin menjadi kosong karena penghapusan */
{
    address prev = First(*L);
    address p = Next(prev);
    int counter = 1;

    while (p != Nil && counter < idLagu)
    {
        prev = p;
        p = Next(p);
        counter += 1;
    }

    if (p != Nil)   // X ada
    {   
        printf("\n%sLagu %s\"%s\" %soleh %s\"%s\" %stelah dihapus dari playlist %s\"%s\"!\n", JudulLagu(p).TabLine, NamaPenyanyi(p).TabLine, namaPlaylist.TabLine);
        if (p == First(*L))
        {
            DelFirstLinked(L, &p);
        } 
        else
        {
            DelAfterLinked(L, &p, prev);
        }

        DealokasiLinked(&p);
    }
    else
    {
        printf("\n%sERROR: %sTidak ada lagu dengan urutan %d di playlist \"%s\"!\n", idLagu, namaPlaylist.TabLine);
    }
}
// {
//     address p = First(*L);
//     address prev = Nil;

//     while (p != Nil && !isKalimatEqual(JudulLagu(p), X.JudulLagu) && !isKalimatEqual(NamaAlbum(p), X.NamaAlbum) && !isKalimatEqual(NamaPenyanyi(p), X.NamaPenyanyi))
//     {
//         prev = p;
//         p = Next(p);
//     }

//     if (p != Nil)   // X ada
//     {
//         if (p == First(*L))
//         {
//             DelFirst(L, &p);
//         } else
//         {
//             DelAfter(L, &p, prev);
//         }
//     }

//     Dealokasi(&p);
// }

void DelLastLinked (ListLinier *L, address *P)
/* I.S. ListLinier tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListLinier sebelum penghapusan  */
/*      Elemen ListLinier berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    *P = First(*L);

    if (Next(*P) == Nil)
    {
        First(*L) = Nil;
    } else
    {
        address prev = *P;
        
        while (Next(Next(prev)) != Nil)
        {
            prev = Next(prev);
        }

        // Next(*P) = Nil
        DelAfterLinked(L, P, prev);
    }
}

void DelAfterLinked (ListLinier *L, address *Pdel, address Prec)
/* I.S. ListLinier tidak kosong. Prec adalah anggota ListLinier  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListLinier yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN ListLinier ******************/
void PrintInfoLinked (ListLinier L)
/* I.S. ListLinier mungkin kosong */
/* F.S. Jika ListLinier tidak kosong, iai ListLinier dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListLinier kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    if (!IsEmptyLinked(L))
    {
        address p = First(L);

        while (p != Nil)
        {
            printf("{%s, %s, %s}", NamaPenyanyi(p).TabLine, NamaAlbum(p).TabLine, JudulLagu(p).TabLine);
            p = Next(p);
            if (p != Nil)
            {
                printf(",");
            }
        }
    }

    printf("]\n");
}

int NbElmtLinked (ListLinier L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    address p = First(L);

    while (p != Nil)
    {
        count += 1;
        p = Next(p);
    }

    return count;
}