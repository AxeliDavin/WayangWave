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

void IgnoreSC()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    const char temp = currentChar;
    while (temp == ';')
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
    cleanWORD();    
    START();
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == '\r' || currentChar == '\n')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void cleanWORD(){
  for(int i =0; i<currentWord.Length; i++){
    currentWord.TabWord[i] = '\0'; 
  }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    cleanWORD();
    IgnoreBlanks();
    if(currentChar == MARK || currentChar == '\r' || currentChar == '\n'){
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVWORDBlank()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (EOP)
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

void ADVWORDSC()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreSC();
    if (EOP)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
        IgnoreSC();
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
    while (currentChar != BLANK && currentChar != MARK && currentChar != '\r' && currentChar != '\n')
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

boolean isEndWord() {
    return currentChar == '\n' || currentChar == MARK;
}

boolean IsKataSama(Word *k1, char *k2){
    boolean sama = true;
    int i = 0;
    for(int i=0; i < currentWord.Length; i++){
        if (k2[i] != (*k1).TabWord[i]) sama = false;
    }
    return sama;
}

void readInput(){
    printf(">> ");
    STARTWORD();
    START();
}

Word takeInput(){
  STARTWORD();
  Word tempWord = currentWord;
  Word spasi; 
  while(!isEndWord() && !EOP){
    ADVWORD();
    SetWord(&spasi, " ");
    ConcatWord(currentWord, &spasi);
    ConcatWord(spasi, &tempWord);
  }
  return tempWord; 
}

int WordToInt(Word *word)
{
    int result = 0;
    for (int i = 0; i < word->Length; i++)
    {
        result = result * 10 + (word->TabWord[i] - '0');
    }
    return result;
}

void SetWord(Word *w, char *s){
    CleanWord(w);
    int i =0;
    while(s[i] != '\0'){
        w->TabWord[i] = s[i];
        i++;
    }
    w->Length = i;
}

void ConcatWord(Word dest, Word *target){
    for(int i =0; i< dest.Length; i++){
        target -> TabWord[i + target->Length] = dest.TabWord[i]; 
    }
    target->Length = dest.Length + target->Length;
}

void CleanWord(Word *w){
    for(int i =0; i< NMax; i++){
        w->TabWord[i] = '\0';
    }
}