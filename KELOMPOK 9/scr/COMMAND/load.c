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
CurrentSong Lagu;
/*LOAD*/
void Load(ListPenyanyi * LP, char filename[])
{

    STARTKALIMATFILE(filename);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int loop = atoi(FileLine.TabLine);
    if (loop > 0)
    {

        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            int album = atoi(FileLine.TabLine);
            
            NEXTLINE();
            
            AddPenyanyi(LP, FileLine);
            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(FileLine.TabLine);

            NEXTLINE();

            AddAlbum(LP, FileLine);

            for (int k = 0; k < lagu; k++)
            {
                NEXTLINE();

                AddLagu(LP, FileLine);
            }
            }
        }
        NEXTLINE();
        Lagu.NamaPenyanyi = FileLine;
        ADVRECORD();
        Lagu.NamaAlbum = FileLine;
        ADVRECORD();
        Lagu.JudulLagu = FileLine;
        NEXTLINE();

            int loopRecordQ = atoi(FileLine.TabLine);
            for (int i = 0; i < loopRecordQ; i++) // Queue
            {  contentQueue lagu;
                ADVRECORD();
                lagu.NamaPenyanyi = FileLine;
                ADVRECORD();
                lagu.NamaAlbum = FileLine;
                ADVRECORD();
                lagu.JudulLagu = FileLine;

                enqueue(&antre, lagu);
            }

            NEXTLINE();
            int loopRecordR = atoi(FileLine.TabLine);
            for (int i = 0; i < loopRecordR; i++) // History input
            {
                contentStack song;
                ADVRECORD();
                song.NamaPenyanyi = FileLine;
                ADVRECORD();
                song.NamaAlbum = FileLine;
                ADVRECORD();
                song.JudulLagu = FileLine;

                Push(&History, song);
            }


            NEXTLINE();
            int loopRecordP = atoi(FileLine.TabLine); // Jumlah Playlist
            for (int i = 0; i < loopRecordP; i++) // Loop Playlist
            {

                ADVSATUKATA();
                int LaguPlaylist = atoi(FileLine.TabLine);
                printf("%d\n", LaguPlaylist);
                for (int j = 0; j < LaguPlaylist; j++)
                {   
                    printf("p: %d\n", j);
                    infoType Songss;

                    ADVRECORD();
                    Songss.NamaPenyanyi = FileLine;

                    ADVRECORD();
                    Songss.NamaAlbum = FileLine;
                    printf("d: %d\n", j);
                    ADVRECORD();
                    Songss.JudulLagu = FileLine;
                    printf("d: %d\n", j);
                    InsVLastLinked(Playlists.lagu2, Songss);
                    printf("d: %d\n", j);
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