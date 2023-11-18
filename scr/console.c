#include <stdlib.h>
#include <stdio.h>
#include "console.h"

/*Tempat Command*/

void STARTC(){ //namanya STARTC karena START udah ada di mesinkar
    
    printf ("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    readInput();
}

List singer, album, song;

void load()
{   char filename[256];
    printf("filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.");
        return 1;
    }
    int nSinger;
    fscanf(file, "%d", &nSinger);
    Makelist(&singer);
    for (int i=0; i<nSinger; i++){// baca line 2 BLACKPINK
        int nAlbum;
        char singertemp;
        fscanf(file, "%d %255s", &nAlbum, &singertemp);
        InsertLast(&singer, singertemp);

        Makelist(&album);
        
        for (int j=0; j<nAlbum; j++){// BACA LINE 4 BORNPINK 
            int nSong;
            char albumtemp;
            fscanf(file, "%d %255s", &nSong, &albumtemp);
            InsertLast(&album, albumtemp);

            MakeList(&song);

            for (int k=0; k<nSong; k++){
                char songtemp;
                fscanf(file, "%255s", &songtemp);
                InsertLast(&song, songtemp);
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.");
}


void ListDefault(){
    load();
    printf("Daftar penyanyi :\n");

    for (int i = 0; i < Length(singer); i++)
    {
        printf("   %d. %c\n", i+1, Get(singer, i));
    }
    
    char lookalbum;
    scanf("Ingin melihat album yang ada?(Y/N): %c", &lookalbum);
    if (lookalbum == 'Y')
    {
        char chosenalbum;
        scanf("Pilih penyanyi untuk melihat album mereka: %c", &chosenalbum);

    }
    

}


List playlist; // Global variable for list of playlists

void createPlaylist() {
    char playlistName[256];
    printf("Masukkan nama playlist yang ingin dibuat : ");
    scanf("%255s", playlistName);

    List newPlaylist = MakeList();
    InsertLast(&playlist, playlistName);
}

