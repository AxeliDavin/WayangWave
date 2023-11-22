#include "../adt.h"
#include <stdio.h>
#include <stdlib.h>


// gcc ../ADT/boolean.h ../ADT/List/list.c ../ADT/SongAlbumSinger/songalbumsinger.c ../ADT/ListLinier/listlinier.c ../ADT/MAP/map.c ../ADT/MesinKalimat/mesinkalimat.c ../ADT/MesinKarakter/mesinkarakter.c ../ADT/Playlist/playlist.c ../ADT/MesinKata/mesinkata.c ../ADT/Queue/queue.c ../ADT/Set/set.c ../ADT/Stack/stack.c ../ADT/Song.h start.c -o start 

/*Fungsi Utama*/
void Start(ListPenyanyi *LP, char path[])
{

    // ListPenyanyi LP;
    // CreateEmptyListPenyanyi(&LP);
    // char path[120] = "../save/config.txt";
    
    STARTKALIMATFILE(path);

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
        // ADVKALIMAT();
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

        if(IsKataSama(currentWord.TabWord, "START")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                Start(&Penyanyi, "../../save/config.txt");
                masuksesi = true;
                printf("%d\n", Penyanyi.NEff);
                printf("%d\n", Album.NEff);
                printf("%d\n", Penyanyi.NEff);
            }
        } 
    }
    return 0;
}