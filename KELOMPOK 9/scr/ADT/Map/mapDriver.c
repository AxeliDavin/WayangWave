#include "map.h"

int main(){
    Map M;
    CreateEmptyMap(&M);

    if (IsEmptyMap(M))
    {
        printf("Iya kosong\n");
    }
    
    if (!IsFullMap(M))
    {
        printf("Map belum penuh :(\n");
    }
    
    // Masukin nilai Map
    InsertMap(&M, 1, 20);
    InsertMap(&M, 3, 50);

    printf("Nilai dari keytype 1 adalah %d\n", ValueMap(M, 1));

    if (IsMemberMap(M, 1))
    {
        printf("Ada cuy\n");
    }

    // Hapus nilai map
    DeleteMap(&M, 1);
    if (IsMemberMap(M, 1))
    {
        printf("Ada cuy\n");
    }else{
        printf("Buset dah ilang\n");
    }
}