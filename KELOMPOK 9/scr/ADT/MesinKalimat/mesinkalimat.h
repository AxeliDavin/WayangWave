#ifndef __MESINKALIMAT_H__
#define __MESINKALIMAT_H__

#include "../boolean.h"
#include "../MesinKarakter/mesinkarakter.h"

#define NMaks 100
#define NEWLINE '\n'
#define MARK2 '\0'

typedef struct {
  char TabLine[NMaks+1];
  int Length;
} Kalimat;

/* State Mesin Kalimat */
extern boolean EndKalimat;
extern Kalimat FileLine;
extern Kalimat InputLine;
extern Kalimat Command;

Kalimat createKalimat();
boolean IsKalimatEmpty(Kalimat K);

void IgnoreNewline();
void Ignoreblanks();
void IgnoreTitikKoma();

void SalinKalimat();
void SalinSatuKata();
void SalinRecord();
void SalinCommand();

void STARTKALIMATINPUT();
void SalinInput();
void ResetInput();
void ResetCommand();
Kalimat DirectoryCommand(Kalimat file);

void STARTKALIMATFILE(char filename[]);
void STARTCOMMAND();

void NEXTLINE();
void ADVSATUKATA();
void ADVRECORD();
void ADVCOMMAND();

void copyKalimat (Kalimat k1, Kalimat *k2);
void ResetKalimat();

boolean isKalimatEqual(Kalimat K1, Kalimat K2);
int LengthKalimat(char * S2);

void displayKalimat(Kalimat K);
boolean isInputEqual(Kalimat Input, char * kata);

Kalimat charToKalimat(char *K);

void TukarKalimat(Kalimat *K1, Kalimat *K2);

#endif