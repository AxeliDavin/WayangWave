#include "listlinier.h"
#include <stdio.h>

// gcc listlinier.c listlinierDriver.c ../MesinKarakter/mesinkarakter.c ../MesinKata/mesinkata.c ../MesinKalimat/mesinkalimat.c -o listlinier

int main(){
    ListLinier lagu;
    Kalimat S = charToKalimat("halo");
    Kalimat A = charToKalimat("halo2");
    Kalimat C = charToKalimat("halo3");
    Kalimat W = charToKalimat("halo4");
    Kalimat E = charToKalimat("halo5");
    Kalimat R = charToKalimat("halo6");
    Kalimat WW = charToKalimat("halo7");
    Kalimat EE = charToKalimat("halo8");
    Kalimat RR = charToKalimat("halo9");
    infoType X, K, L;
    X.JudulLagu = S;
    X.NamaAlbum = A;
    X.NamaPenyanyi = C;
    K.JudulLagu = W;
    K.NamaAlbum = E;
    K.NamaPenyanyi = R;
    L.JudulLagu = WW;
    L.NamaAlbum = EE;
    L.NamaPenyanyi = RR;
    address J, H, G;
    Kalimat kal;
    int count = 3;
    CreateEmptyLinked(&lagu);

    if (IsEmptyLinked(lagu)){
        printf("Kosong\n"); //Tes Isempty dan create empty
    }

    address P = AlokasiLinked(X);

    DealokasiLinked(&P);

    InsVFirstLinked(&lagu, X);
    PrintInfoLinked(lagu);

    InsVLastLinked(&lagu, K);
    PrintInfoLinked(lagu);

    InsVFirstLinked(&lagu, L);
    PrintInfoLinked(lagu);

    InsVFirstLinked(&lagu, L);
    PrintInfoLinked(lagu);

    DelFirstLinked(&lagu, &J);
    PrintInfoLinked(lagu);

    DelLastLinked(&lagu, &H);
    PrintInfoLinked(lagu);

    // DelPLinked(kal, &lagu, count);
    // PrintInfoLinked(lagu);

    int hasil = NbElmtLinked(lagu);
    printf("hasil %d\n", hasil);
}

