#include "../adt.h"
#include <stdio.h>
#include <stdlib.h>


// gcc ../ADT/boolean.h ../ADT/List/list.c ../ADT/SongAlbumSinger/songalbumsinger.c ../ADT/ListLinier/listlinier.c ../ADT/MAP/map.c ../ADT/MesinKalimat/mesinkalimat.c ../ADT/MesinKarakter/mesinkarakter.c ../ADT/Playlist/playlist.c ../ADT/MesinKata/mesinkata.c ../ADT/Queue/queue.c ../ADT/Set/set.c ../ADT/Stack/stack.c ../ADT/Song.h load.c -o load 

Stack History;
Queue antre;
Playlist Playlists;
ListPenyanyi Penyanyi;
MapAlbum Album;
SetLagu Song;
Playlist Playlists;
/*LOAD*/
void Load(ListPenyanyi * LP, char filename[])
{

    STARTKALIMATFILE(filename);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int loop = atoi(CLine.TabLine);

    if (loop > 0)
    {

        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            int album = atoi(CLine.TabLine);
            
            ADVKALIMAT();
            
            AddPenyanyi(LP, CLine);

            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(CLine.TabLine);

            ADVKALIMAT();

            AddAlbum(LP, CLine);

            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();

                AddLagu(LP, CLine);
            }
            }
        }

        ADVKALIMAT();

            int loopRecordQ = atoi(CLine.TabLine);

            for (int i = 0; i < loopRecordQ; i++) // Queue
            {  contentQueue lagu;
                ADVRECORD();
                lagu.NamaPenyanyi = CLine;
                ADVRECORD();
                lagu.NamaAlbum = CLine;
                ADVRECORD();
                lagu.JudulLagu = CLine;

                enqueue(&antre, lagu);
            }

            ADVKALIMAT();
            int loopRecordR = atoi(CLine.TabLine);

            for (int i = 0; i < loopRecordR; i++) // History input
            {
                contentStack song;
                ADVRECORD();
                song.NamaPenyanyi = CLine;
                ADVRECORD();
                song.NamaAlbum = CLine;
                ADVRECORD();
                song.JudulLagu = CLine;

                Push(&History, song);
            }


            ADVKALIMAT();
            int loopRecordP = atoi(CLine.TabLine); // Jumlah Playlist

            for (int i = 0; i < loopRecordP; i++) // Loop Playlist
            {

                ADVSATUKATA();
                int LaguPlaylist = atoi(CLine.TabLine);

                for (int j = 0; j < LaguPlaylist; j++)
                {   
                    
                    infoType Songs;

                    ADVRECORD();
                    Songs.NamaPenyanyi = CLine;

                    ADVRECORD();
                    Songs.NamaAlbum = CLine;

                    ADVRECORD();
                    Songs.JudulLagu = CLine;
                    InsVLast(Playlists.A, Songs);
                }
            }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
    else
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}

int main(){



    CreateEmptyStack(&History);
    CreateQueue(&antre);
    CreateEmptyPlaylist(&Playlists);

    /*Pembuatan Kosong*/
    CreateEmptyListPenyanyi(&Penyanyi);
    // CreateEmptyMap(&Album);
    // CreateEmptySet(&Song);
    
    boolean masuksesi = false, stopsesi = false;

    /*Masuk Ke Command Utama*/
    while(!stopsesi){

        readInput();

        if (IsKataSama(currentWord.TabWord, "LOAD")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                ADVWORD();
                char path[50] = "../../save/";
                for (int i = 0; i < currentWord.Length; i++){
                    path[i+11] = currentWord.TabWord[i];
                }
                Load(&Penyanyi, path);
                masuksesi = true;
            }           
        } 
    }
    return 0;
}