#include <stdio.h>
#include "list.h"

// Konstruktor

void MakeList(List *L) {
	IdxType i;
	for (i = 0; i < MaxElList; i++) {
		(*L).A[i] = Mark;
	}
}

boolean IsEmptyList(List L) {
	return (L.A[0] == Mark);
}

int LengthList(List L) {
	int i = 0;
	while (L.A[i] != Mark) {
		i += 1;
	}
	return i;
}

ElTypeList GetList(List L, IdxType i) {
	return L.A[i];
}

void SetList(List *L, IdxType i, ElTypeList v) {
	(*L).A[i] = v;
}

IdxType FirstIdxList(List L) {
    return 0;
}

IdxType LastIdxList(List L) {
	int i = FirstIdxList(L);
	while ((i < MaxElList) && (L.A[i+1] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValidList (List L, IdxType i) {
	return (0 <= i) && (MaxElList >= i);
}

boolean IsIdxEffList (List L, IdxType i) {
	return (FirstIdxList(L) <= i) && (LastIdxList(L) >= i);
}

boolean SearchList(List L, ElTypeList X) {
	int i = FirstIdxList(L);
	int j = LastIdxList(L);
	boolean found = false;
	while ((i <= j) && !found) {
		if (L.A[i] == X) {
			found = true;
		}
		i += 1;
	}
    return found;
}

void InsertFirstList(List *L, ElTypeList X) {
	IdxType i = LastIdxList(*L);
	while (i >= 0) {
		SetList(L, i+1, GetList(*L, i));
		i--;
	}
	SetList(L, 0, X);
}

void InsertAtList(List *L, ElTypeList X, IdxType i) {
    for (int j = LengthList(*L); j > i; j--)
    {
        L->A[j] = L->A[j-1];
    }
    L->A[i] = X;
}

void InsertLastList(List *L, ElTypeList X) {
    if (IsEmptyList(*L)) {
        InsertFirstList(L, X);
    } else {
        (*L).A[LastIdxList(*L) + 1] = X;
    }
}

void DeleteFirstList(List *L) {
	int i = FirstIdxList(*L);
	while (i < LastIdxList(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i] = Mark;
}

void DeleteAtList(List *L, IdxType i) {
	int j = LastIdxList(*L);
	while (i <= j) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
}

void DeleteLastList(List *L) {
	(*L).A[LastIdxList(*L)] = Mark;
}

List Concatlist(List L1, List L2) {
	List L3;
	MakeList(&L3);
	int i = FirstIdxList(L1);
	int j = FirstIdxList(L2);
	int idx = 0;
	while (i <= LastIdxList(L1)) {
		L3.A[idx] = L1.A[i];
        idx++;
        i++;
	}
	while (j <= LastIdxList(L2)) {
		L3.A[idx] = L2.A[j];
        idx++;
        j++;
	}

    return L3;
}

void DisplayList(List L){
	printf("[");
	if (!IsEmptyList(L))
	{
		for (int i = 0; i < LastIdxList(L); i++)
		{
			printf("%d,", GetList(L, i));
		}	
		printf("%d", GetList(L, LastIdxList(L)));
	}
	printf("]\n");
}