#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyPlaylist(Playlist *x){
    (*x).A = (ListLinier *)malloc(INITIAL_CAPACITY * sizeof(ListLinier));
    (*x).namaPlaylist = (Kalimat *)malloc(INITIAL_CAPACITY * sizeof(Kalimat));
    (*x).capacity = INITIAL_CAPACITY;
    (*x).nEff = 0;
}