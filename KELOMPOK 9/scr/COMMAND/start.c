#include "../adt.h"
#include <stdio.h>
#include <stdlib.h>


// gcc ../ADT/boolean.h ../ADT/List/list.c ../ADT/SongAlbumSinger/songalbumsinger.c ../ADT/ListLinier/listlinier.c ../ADT/MAP/map.c ../ADT/MesinKalimat/mesinkalimat.c ../ADT/MesinKarakter/mesinkarakter.c ../ADT/Playlist/playlist.c ../ADT/MesinKata/mesinkata.c ../ADT/Queue/queue.c ../ADT/Set/set.c ../ADT/Stack/stack.c ../ADT/Song.h start.c -o start

Stack History;
Queue antre;
Playlist Playlists;
ListPenyanyi Penyanyi;
MapAlbum Album;
SetLagu Song;
CurrentSong Lagu;
/*Fungsi Utama*/
void Start(ListPenyanyi *LP, char path[])
{

    STARTKALIMATFILE(path);

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

        if(IsKataSama(currentWord.TabWord, "START")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                printf("kata 1: %s\n", currentWord.TabWord);
                Start(&Penyanyi, "../../save/config.txt");
                masuksesi = true;
            }
        } 
        else {
            printf("kata 2: %s\n", currentWord.TabWord);
            printf("Command tidak diketahui!\n"); /*Tidak ada di list command*/
        }
    }
    return 0;
}