#include "../adt.h"
#include "../ADT/songalbumsinger.h"
#include <stdio.h>
#include <stdlib.h>


// gcc ../ADT/boolean.h ../ADT/List/list.c ../ADT/songalbumsinger.c ../ADT/ListLinier/listlinier.c ../ADT/MAP/map.c ../ADT/MesinKalimat/mesinkalimat.c ../ADT/MesinKarakter/mesinkarakter.c ../ADT/Playlist/playlist.c ../ADT/MesinKata/mesinkata.c ../ADT/Queue/queue.c ../ADT/Set/set.c ../ADT/Stack/stack.c start.c -o start 

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

    printf("%d\n", atoi(CLine.TabLine));
    int loop = atoi(CLine.TabLine);

    printf("%d\n", loop);
    if (loop > 0)
    {

        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            int album = atoi(CLine.TabLine);
            printf("2\n");
            ADVKALIMAT();
            
            AddPenyanyi(LP, CLine);

            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(CLine.TabLine);
            printf("3\n");
            ADVKALIMAT();

            AddAlbum(LP, CLine);

            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();
                printf("4\n");
                AddLagu(LP, CLine);
            }
            }
        }
        ADVKALIMAT();
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
                Start(&Penyanyi, "../save/config.txt");
                masuksesi = true;
            }
        } 
    }
    return 0;
}