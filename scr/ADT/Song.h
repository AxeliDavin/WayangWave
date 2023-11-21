#ifndef __PLAY_H__
#define __PLAY_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include <stdio.h>

#include "songalbumsinger.h"
#include "stack.h"
#include "queue.h"
#include "mesinkalimat.h"

typedef struct {
	Kalimat JudulLagu; 
    Kalimat NamaAlbum;
    Kalimat NamaPenyanyi;
    Kalimat NamaPlaylist;
    int status;
    int statusPL;
} CurrentSong;

typedef struct {
	Kalimat NamaUser;
    int idUser;
    int status;
} CurrentUser;

#endif