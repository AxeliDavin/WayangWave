#include "queue.h"
#include <stdio.h>

int main(){
    Queue lagu;
    CreateQueue(&lagu);

    if (isEmptyQueue(lagu)){
        printf("Kosong\n"); //Validasi jika kosong
    }

    contentQueue val;
    for (int i = 0; i < CAPACITY; i++){
        enqueue(&lagu, val); //Tes enqueue
    }

    printf("%d\n", length(lagu)); //Tes length

    if (isFullQueue(lagu)){
        printf("Penuh\n");
    }

    dequeue(&lagu, &val);

    if (isFullQueue(lagu)){
        printf("Penuh\n"); //Seharusnya tidak print karena sudah didequeue
    }

    displayQueue(lagu);
}

