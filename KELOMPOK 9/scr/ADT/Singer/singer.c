#include "singer.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMapSinger(Singer *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElMap */
/* Ciri Map kosong : NEff bernilai NilMap */
{
    M->NEff = NilMap;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMapSinger(Singer M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : NEff bernilai NilMap */
{
    return M.NEff == NilMap;
}

boolean IsFullMapSinger(Singer M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : NEff bernilai MaxElMap */
{
    return M.NEff == MaxElMap;
}

/* ********** Operator Dasar Map ********* */
valtypeSinger ValueSinger(Singer M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, tidak mengembalikan apa-apa */
{
    address idx = 0, iterator;

    while (idx < M.NEff) {
        if (isKalimatEqual(M.PenyanyiAlbum[idx].NamaPenyanyi,k)) return M.PenyanyiAlbum[idx].isiAlbum;
        idx++;
    }

    return;
}

void InsertMapSinger(Singer *M, keytype k, valtypeSinger v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberMapSinger(*M, k)) return;

    M->PenyanyiAlbum[M->NEff].NamaPenyanyi = k;
    M->PenyanyiAlbum[M->NEff].isiAlbum = v;
    M->NEff++;
}

void DeleteMapSinger(Singer *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (!IsMemberMapSinger(*M, k)) return;

    boolean found = false;
    address idx = 0, iterator;

    while (idx < M->NEff) {
        if (isKalimatEqual(M->PenyanyiAlbum[idx].NamaPenyanyi,k)) break;
        idx++;
    }

    for (iterator = (idx + 1); iterator < M->NEff; iterator++) {
        M->PenyanyiAlbum[iterator - 1].NamaPenyanyi = M->PenyanyiAlbum[iterator].NamaPenyanyi;
        M->PenyanyiAlbum[iterator - 1].isiAlbum = M->PenyanyiAlbum[iterator].isiAlbum;
    }

    M->NEff--;
}

boolean IsMemberMapSinger(Singer M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    address idx = 0, iterator;
    
    while (idx < M.NEff) {
        if (isKalimatEqual(M.PenyanyiAlbum[idx].NamaPenyanyi,k)) return true;
        idx++;
    }
    
    return false;
}