#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "ADT/boolean.h"
#include "ADT/list.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

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
    List singer;
    Makelist(&singer);
    for (int i=0; i<nSinger; i++){// baca line 2 BLACKPINK
        int nAlbum;
        char singertemp;
        fscanf(file, "%d %255s", &nAlbum, &singertemp);
        InsertLast(&singer, singertemp);

        List album;
        Makelist(&album);
        
        for (int j=0; j<nAlbum; j++){// BACA LINE 4 BORNPINK 
            int nSong;
            char albumtemp;
            fscanf(file, "%d %255s", &nSong, &albumtemp);
            InsertLast(&album, albumtemp);

            List song;
            MakeList(&song);

            for (int k=0; k<nSong; k++){
                char songtemp;
                fscanf(file, "%255s", &albumtemp);
                InsertLast(&song, songtemp);
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.");
}
