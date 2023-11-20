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

int Length(List L) {
	int i = 0;
	while (L.A[i] != Mark) {
		i += 1;
	}
	return i;
}

ElTypeList Get(List L, IdxType i) {
	return L.A[i];
}

void SetList(List *L, IdxType i, ElTypeList v) {
	(*L).A[i] = v;
}

IdxType FirstIdx(List L) {
    return 0;
}

IdxType LastIdx(List L) {
	int i = FirstIdx(L);
	while ((i < MaxElList) && (L.A[i+1] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValid (List L, IdxType i) {
	return (0 <= i) && (MaxElList >= i);
}

boolean IsIdxEff (List L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

boolean SearchList(List L, ElTypeList X) {
	int i = FirstIdx(L);
	int j = LastIdx(L);
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
	IdxType i = LastIdx(*L);
	while (i >= 0) {
		SetList(L, i+1, Get(*L, i));
		i--;
	}
	SetList(L, 0, X);
}

void InsertAt(List *L, ElTypeList X, IdxType i) {
    IdxType j = LastIdx(*L);
	while (i <= j) {
		SetList(L, j+1, Get(*L, j));
        j--;
	}
	SetList(L, i, X);
}

void InsertLastList(List *L, ElTypeList X) {
    if (IsEmptyList(*L)) {
        InsertFirstList(L, X);
    } else {
        (*L).A[LastIdx(*L) + 1] = X;
    }
}

void DeleteFirst(List *L) {
	int i = FirstIdx(*L);
	while (i < LastIdx(*L)) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
    (*L).A[i] = Mark;
}

void DeleteAt(List *L, IdxType i) {
	int j = LastIdx(*L);
	while (i <= j) {
		(*L).A[i] = (*L).A[i+1];
        i++;
	}
}

void DeleteLast(List *L) {
	(*L).A[LastIdx(*L)] = Mark;
}

List Concat(List L1, List L2) {
	List L3;
	MakeList(&L3);
	int i = FirstIdx(L1);
	int j = FirstIdx(L2);
	int idx = 0;
	while (i <= LastIdx(L1)) {
		L3.A[idx] = L1.A[i];
        idx++;
        i++;
	}
	while (j <= LastIdx(L2)) {
		L3.A[idx] = L2.A[j];
        idx++;
        j++;
	}

    return L3;
}