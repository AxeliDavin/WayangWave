#include <stdio.h>
#include "mesinkata.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    // printf("STARTWORD");
    if (EOP)
    {
        endWord = true;
        // printf("STARTWORD2");    

    }
    else
    {
        endWord = false;
        // printf("STARTWORD3");
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    // printf("COPYWORD");
    while (currentChar != BLANK && currentChar != MARK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
            // printf("COPYWORD2");
            // printf("%s\n",currentWord.TabWord);
            // currentWord.TabWord[currentWord.Length] = '\0';
            ADV();
        }
        else
            break;
    }
    // int i = 0;
    // while (currentChar != ';' && !EOP){
    //     currentWord.TabWord[i] = currentChar;
    //     ADV();
    //     i++;
    // }
    // currentWord.Length = i;
    // currentWord.TabWord[i] = '\0';
}

boolean isEndWord() {
    return endWord;
}

boolean IsKataSama(Word k1, char *k2){
    boolean sama = true;
    // printf("length : %d\n", k1.Length);
    printf("lengthcw : %d\n", currentWord.Length);
    for(int i=0; i <= currentWord.Length; i++){
        if (k2[i] != currentWord.TabWord[i+1]) sama = false;
        printf("%c %c\n", k2[i], currentWord.TabWord[i+1]);
        printf("i = %d\n", i);
    }
    return sama;
}

void readInput(){
    printf(">> ");
    STARTWORD();
    while ((getchar()) != '\n');
}