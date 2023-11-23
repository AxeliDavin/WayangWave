#ifndef __PLAY_H__
#define __PLAY_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>

#include "./SongAlbumSinger/songalbumsinger.h"
#include "./MesinKalimat/mesinkalimat.h"

#define Nil NULL

typedef struct {
	Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
    int idxPlaylist;
} dataLagu;

typedef dataLagu CurrentSong;

/* *** Konstruktor/Kreator *** */
void CreateEmptyCurrentSong(CurrentSong *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah current song S kosong */
/* Ciri current song kosong : JudulLagu bernilai Undefined */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsPlaying(CurrentSong S);
/* Mengirim true jika Set S kosong*/
/* Ciri  kosong : count berNilSetai NilSet */

#endif