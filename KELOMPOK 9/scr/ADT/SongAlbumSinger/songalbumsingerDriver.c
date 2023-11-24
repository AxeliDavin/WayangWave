#include "songalbumsinger.h"
#include <stdio.h>

int main(){
    ListPenyanyi Singer;
    Kalimat NamaPenyanyi, NamaAlbum, JudulLagu;

    printf("masukkan nama penyanyi Anda: \n");
    STARTKALIMATINPUT();
    NamaPenyanyi = InputLine;
    AddPenyanyi (&Singer, NamaPenyanyi);
    printf("masukkan nama album penyanyinya: \n");
    STARTKALIMATINPUT();
    NamaAlbum = InputLine;
    AddAlbum(&Singer, NamaAlbum);

    printf("masukkan nama lagunya; \n");
    STARTKALIMATINPUT();
    JudulLagu = InputLine;
    AddLagu(&Singer, JudulLagu);

    printf("banyak penyanyi Anda %d", Singer.NEff);
}