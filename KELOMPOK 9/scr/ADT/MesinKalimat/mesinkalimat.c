#include <stdio.h>
#include "mesinkalimat.h"

boolean EndKalimat;
Kalimat CLine;
Kalimat CInput;
Kalimat currentCharommand;

void Ignoreblanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void IgnoreNewline()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}

void IgnoreTitikKoma()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == ';')
    {
        ADV();
    }
}

void SalinInput() {
    ResetInput();  
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != EOF))
    {
        CInput.TabLine[i] = currentChar;
        i+= 1;
        ADV();
    }
    CInput.Length = i;
}

void SalinKalimat() {
    ResetKalimat();  
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != SEMICOLON) && (currentChar != EOF))
    {
        CLine.TabLine[i] = currentChar;
        // printf("%c", currentChar);
        i+= 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinSatuKata() {
    ResetKalimat();  
    int i = 0;
    while ((currentChar != ' ') && (currentChar != MARK))
    {
        CLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    CLine.Length = i;
}

void SalinRecord() {
    ResetKalimat();  
    int i = 0;
    while ((currentChar != MARK) && (currentChar != NEWLINE))
    {
        CLine.TabLine[i] = currentChar;
        i += 1;
        ADV();
    }
    CLine.Length = i;
}

void STARTKALIMATINPUT() {
    START();
    IgnoreNewline();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinInput();
    }
}

void STARTCOMMAND() {
    START();
    IgnoreNewline();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}

void SalinCommand() {
    ResetCommand();  // Reset array
    int i = 0;
    while ((currentChar != ' ') && (currentChar != ';') && (currentChar != EOF))
    {
        currentCharommand.TabLine[i] = currentChar;
        // printf("%c\n", currentChar);
        i+= 1;
        ADV();
    }
    currentCharommand.Length = i;
}

void ADVCOMMAND(){
    Ignoreblanks();
    if (currentChar == ';'){
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinCommand();
    }
}



void STARTKALIMATFILE(char filename[]) {
    STARTFILE(filename);
    IgnoreNewline();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVKALIMAT(){
    IgnoreNewline();
    Ignoreblanks();
    if (currentChar == MARK2) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinKalimat();
    }
}

void ADVSATUKATA() {
    Ignoreblanks();
    IgnoreNewline();
    if (currentChar == ' ') {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinSatuKata();
    }
}

void ADVRECORD() {
    Ignoreblanks();
    IgnoreNewline();
    IgnoreTitikKoma();
    if (currentChar == ';' || currentChar == NEWLINE) {
        EndKalimat = true;
    } else {
        EndKalimat = false;
        SalinRecord();
    }
}

void copyKalimat (Kalimat k1, Kalimat *k2){
    k2->Length=k1.Length;
    for (int i=0;i<=k1.Length;i++){
        k2->TabLine[i] = k1.TabLine[i];
    }
}

void ResetKalimat() {
    for (int i = 0; i < sizeof(CLine.TabLine); i++) {
        CLine.TabLine[i] = '\0';
        CLine.Length = 0;
    }
}

void ResetInput() {
    for (int i = 0; i < sizeof(CInput.TabLine); i++) {
        CInput.TabLine[i] = '\0';
        CInput.Length = 0;
    }
}

void ResetCommand() {
    for (int i = 0; i < sizeof(currentCharommand.TabLine); i++) {
        currentCharommand.TabLine[i] = '\0';
        currentCharommand.Length = 0;
    }
}

boolean isKalimatEqual(Kalimat K1, Kalimat K2) 
{   
    boolean equal = true;
    if (K1.Length == K2.Length)
    {
        int i = 0;
        while (i < K1.Length && equal)
        {
            if (K1.TabLine[i] != K2.TabLine[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

int LengthKalimat(char * S2){
    int i = 0;

    while (S2[i] != '\0'){
        i++;
    }

    return i;
}


