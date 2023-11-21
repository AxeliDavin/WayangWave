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
    START();
    IgnoreBlanks();
    if (EOP)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
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
    while (currentChar != BLANK && currentChar != ';')
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
    return endWord;
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
    while ((getchar()) != '\n');
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

char WordToString(Word *w)
{
    char* str = malloc(sizeof(char) * ((*w).Length + 1));
    strncpy(str, (*w).TabWord, (*w).Length);
    str[(*w).Length] = '\0'; // Null-terminate the string
    return str;
}   

char takeword(Word *currentWord, int n) {
    STARTWORD(*currentWord);

    char line[256];
    char *word = malloc(256 * sizeof(char));
    while (fgets(line, sizeof(line), currentWord)) {
        int count = 0;
        char *token = strtok(line, " \n");
        while (token != NULL) {
            count++;
            if (count == n) {
                strncpy(word, token, 256 - 1);
                word[256 - 1] = '\0'; // Ensure null-termination
                break;
            }
            token = strtok(NULL, " \n");
        }
    }
    return word;
}

char takekalimat(Word *currentWord) {

    char *sentence = malloc(256 * sizeof(char));

    sentence[0] = '\0'; // Initialize an empty string
    char line[256];
    while (fgets(line, sizeof(line), currentWord)) {
        strcat(sentence, line);
    }
}