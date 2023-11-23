#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyPlaylist(Playlist *x){
    (*x).lagu2 = (ListLinier *)malloc(INITIAL_CAPACITY * sizeof(ListLinier));
    // (*x).namaPlaylist = (Kalimat *)malloc(INITIAL_CAPACITY * sizeof(Kalimat));
    (*x).namaPlaylist = createKalimat();
    (*x).capacity = INITIAL_CAPACITY;
    (*x).nEff = 0;
}

Playlist valuePlaylist(ListPlaylist daftarPlaylist, int idx){
    playlistaddress P = First(daftarPlaylist.A);

    for (int i = 1; i < idx; i++)
    {
        P = Next(P);
    }

    return P->detail;
}

Songs laguPlaylist(Playlist a, int idx){
    address P = a.lagu2->First;

    for (int i = 1; i < idx; i++)
    {
        P = P->next;
    }

    return P->info;
}