#include <stdlib.h>
#include <stdio.h>
#include "console.h"

void Start(){
    List *Penyanyi;
    Map *Album;
    Set *Song;
    char *file;
    STARTWORD(file);

    int jlhPenyanyi = WordToInt(currentWord);

    (*Penyanyi).neff = jlhPenyanyi; // Banyak Penyanyi
    (*Album).Count = 0;
    (*Song).Count = 0;

    int count1 = 0, count2 = 0, keymaker = 0;

    // Masukkan penyanyi (Loop semua penyanyi)
    for (int i = 0; i < (*Penyanyi).neff; i++){
        // Banyak Album → [2] BLACKPINK
        ADVWORD();
        int jlhalbum = WordToInt(takeword(currentWord,1));
        (*Album).Count += jlhalbum;
        
        // Masukkan nama penyanyi ke ListPenyanyi → 2 [BLACKPINK]
        valuetype namaP = WordTostring(takekata(currentWord));
        (*Penyanyi).A[i] = namaP;
        // Masukkan Album (Loop semua album per setiap artist)
        for (int j = count1; j < (*Album).Count; j+){
        // Masukkan banyak lagu dalam suatu album ke MapAlbum
        // [4] BORN PINK
            ADVWORD();
            int jlhlagu = WordToInt(takeword(currentWord,1));
            (*Song).Count+=jlhlagu;
            // Ambil nama album 4 [BORN PINK]
            valuetype namaA = WordToString(takekata(currentWord));
                
            // Masukkan data ke Album
            AlbumElements[count1].keyAlbum = keymaker;
            keymaker++;
            (*Album).Elements[count1].IdPenyanyi = it1;
            (*Album).Elements[count1].valueAlbum = namaA;
            count1++;
            // Masukkan lagu (loop lagu per setiap album)
            for (int k = count2; k < Songcount; k++){
                ADVWORD( );
                // Ambil nama lagu
                valuetype namaL = WordTostring(currentWord);
                // Masukkan ke Song
                (*Song).Elements[count2].Idalbum = count1;
                (*Song).Elements[count2].namalagu = namaL;
                count2++ ;
            }
        }
    }
}