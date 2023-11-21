#include "../adt.h"
#include "../ADT/songalbumsinger.h"
#include <stdio.h>
#include <stdlib.h>


// gcc ../ADT/boolean.h ../ADT/List/list.c ../ADT/songalbumsinger.c ../ADT/ListLinier/listlinier.c ../ADT/MAP/map.c ../ADT/MesinKalimat/mesinkalimat.c ../ADT/MesinKarakter/mesinkarakter.c ../ADT/Playlist/playlist.c ../ADT/MesinKata/mesinkata.c ../ADT/Queue/queue.c ../ADT/Set/set.c ../ADT/Stack/stack.c start.c -o start 

/*Fungsi Utama*/
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

            for (int i = 0; i < loopRecordQ; i++) // Record Queue
            {  
                ADVRECORD();
                Kalimat NamaPenyanyi = CLine;
                ADVRECORD();
                Kalimat NamaAlbum = CLine;
                ADVRECORD();
                Kalimat NamaLagu = CLine;

                enqueueLagu(NamaLagu, NamaAlbum, NamaPenyanyi);
            }

            ADVKALIMAT();
            int loopRecordR = atoi(CLine.TabLine);

            for (int i = 0; i < loopRecordR; i++) // Record Riwayat
            {
                ADVRECORD();
                Kalimat NamaPenyanyi = CLine;
                ADVRECORD();
                Kalimat NamaAlbum = CLine;
                ADVRECORD();
                Kalimat NamaLagu = CLine;

                PushRiwayatLagu(NamaLagu, NamaAlbum, NamaPenyanyi);
            }


            ADVKALIMAT();
            int loopRecordP = atoi(CLine.TabLine); // Jumlah Playlist

            for (int i = 0; i < loopRecordP; i++) // Loop Playlist
            {

                ADVSATUKATA();
                int LaguPlaylist = atoi(CLine.TabLine);

                ADVKALIMAT();

                for (int j = 0; j < LaguPlaylist; j++)
                {   
                    infoType Data;

                    ADVRECORD();
                    Data.NamaPenyanyi = CLine;

                    ADVRECORD();
                    Data.NamaAlbum = CLine;

                    ADVRECORD();

                    InsVLast(&playlist, Data);

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

    /*Global Variable*/
    ListPenyanyi Penyanyi;
    MapAlbum Album;
    SetLagu Song;
    Playlist playlist;
    Queue queue;

    /*Pembuatan Kosong*/
    CreateEmptyListPenyanyi(&Penyanyi);
    // CreateEmptyMap(&Album);
    // CreateEmptySet(&Song);


    /*Pembuatan List Linier Playlist*/
    CreateEmptyPlaylist(&playlist);
    CreateQueue(&queue);
    
    boolean masuksesi = false, stopsesi = false;

    /*Masuk Ke Command Utama*/
    while(!stopsesi){

        readInput();

        if (IsKataSama(currentWord.TabWord, "LOAD")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                ADV();
                char path[120] = "../../save/"; 
                for(int i = 0; i< currentWord.Length; i++){
                    path[i + 11] = currentWord.TabWord[i]; 
                }
                Load(&Penyanyi, path);
                masuksesi = true;
            }           
        } 
    }
    return 0;
}