#include "mesinkalimat.h"
#include <stdio.h>

int main(){
    printf("Testing mesin kalimat, please input words: ");
    STARTKALIMATINPUT();
    printf("Ini kalimat input anda: %s\n", InputLine.TabLine);
    printf("Panjang input anda adalah %d", InputLine.Length);    



}