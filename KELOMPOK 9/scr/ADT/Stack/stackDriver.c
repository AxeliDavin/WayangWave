#include "stack.h"
#include <stdio.h>

int main(){
    Stack lagu;
    CreateEmptyStack(&lagu); // Cek fungsi CreateEmptyStack
    if (IsEmptyStack(lagu))
    {
        printf("True Empty\n");  // Print jika stack lagu kosong
    }
    
    contentStack tes;
    CurrentSong tesp;
    for (int i = 0; i < MaxElStack; i++){
        Push(&lagu, tes); //Cek fungsi push
    }

    if (IsFullStack(lagu))
    {
        printf("True Full\n");  // Print jika stack lagu penuh
    }

    Pop(&lagu, &tesp); //Cek fungsi Pop

    printf("%d\n", lagu.IDXTOP);
}

