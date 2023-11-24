#include "Song.h"
#include <stdio.h>
#include "../boolean.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyCurrentSong(CurrentSong *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah current song S kosong */
/* Ciri current song kosong : JudulLagu bernilai Undefined */
{
    S->JudulLagu = createKalimat();
    S->NamaAlbum = createKalimat();
    S->NamaPenyanyi = createKalimat();
    S->idxPlaylist = NilSong;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsPlaying(CurrentSong S)
/* Mengirim true jika Set S kosong*/
/* Ciri  kosong : count berNilSetai NilSet */
{
    boolean search = false;
    if (!IsKalimatEmpty(S.JudulLagu) )
    {
        search = true;
    }
    return search;
}

void copyToCurrentSong(Songs S, int idx, CurrentSong *S2){
    S2->idxPlaylist = idx;
    copyKalimat(S.JudulLagu, &S2->JudulLagu);
    copyKalimat(S.NamaAlbum, &S2->NamaAlbum);
    copyKalimat(S.NamaPenyanyi, &S2->NamaPenyanyi);
}