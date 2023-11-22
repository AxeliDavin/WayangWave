#include "lagu.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptySetLagu(SetLagu *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count berNilSetai NilSet */
{
    S->Count = NilSet;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySetLagu(SetLagu S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count berNilSetai NilSet */
{
    return S.Count == NilSet;
}

boolean IsFullSetLagu(SetLagu S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count berNilSetai MaxElSet */
{
    return S.Count == MaxElSet;
}

/* ********** Operator Dasar Set ********* */
void InsertLagu(SetLagu *S, Kalimat Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMemberSetLagu(*S, Elmt))
    {
        return;
    }
    S->JudulLagu[S->Count] = Elmt;
    S->Count++;
}

void DeleteLagu(SetLagu *S, Kalimat Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    setaddress idx = 0, iterator;
    if (!IsMemberSetLagu(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (isKalimatEqual(S->JudulLagu[idx],Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->JudulLagu[iterator - 1] = S->JudulLagu[iterator];
    }
    S->Count--;
}

boolean IsMemberSetLagu(SetLagu S, Kalimat Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    setaddress idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (isKalimatEqual(S.JudulLagu[idx],Elmt))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}