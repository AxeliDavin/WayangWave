#ifndef __PLAY_H__
#define __PLAY_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>

#include "./SongAlbumSinger/songalbumsinger.h"
#include "./MesinKalimat/mesinkalimat.h"

typedef struct {
	Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
    int idxPlaylist;
} dataLagu;

typedef dataLagu CurrentSong;

#endif