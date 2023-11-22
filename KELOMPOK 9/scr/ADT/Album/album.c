#include "album.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Album *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : count bernilai NilMap */
{
    M->Count = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Album M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai NilMap */
{
    return M.Count == NilMap;
}

boolean IsFullMap(Album M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElMap */
{
    return M.Count == MaxElMap;
}

/* ********** Operator Dasar Map ********* */
valtypeAlbum Value(Album M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, tidak mengembalikan apa-apa */
{
    address idx = 0, iterator;

    while (idx < M.Count) {
        if (isKalimatEqual(M.AlbumLagu[idx].NamaAlbum,k)) return M.AlbumLagu[idx].IsiLagu;
        idx++;
    }

    return;
}

void InsertMap(Album *M, keytype k, valtypeAlbum v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberMap(*M, k)) return;

    M->AlbumLagu[M->Count].NamaAlbum = k;
    M->AlbumLagu[M->Count].IsiLagu = v;
    M->Count++;
}

void DeleteMap(Album *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (!IsMemberMap(*M, k)) return;

    boolean found = false;
    address idx = 0, iterator;

    while (idx < M->Count) {
        if (isKalimatEqual(M->AlbumLagu[idx].NamaAlbum,k)) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->AlbumLagu[iterator - 1].NamaAlbum = M->AlbumLagu[iterator].NamaAlbum;
        M->AlbumLagu[iterator - 1].IsiLagu = M->AlbumLagu[iterator].IsiLagu;
    }

    M->Count--;
}

boolean IsMemberMap(Album M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    address idx = 0, iterator;
    
    while (idx < M.Count) {
        if (isKalimatEqual(M.AlbumLagu[idx].NamaAlbum,k)) return true;
        idx++;
    }
    
    return false;
}