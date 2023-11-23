#include "Song.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyCurrentSong(CurrentSong *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah current song S kosong */
/* Ciri current song kosong : JudulLagu bernilai Undefined */
{
    S->JudulLagu = createKalimat();
    S->NamaAlbum = createKalimat();
    S->NamaPenyanyi = createKalimat();
    S->idxPlaylist = Nil;
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