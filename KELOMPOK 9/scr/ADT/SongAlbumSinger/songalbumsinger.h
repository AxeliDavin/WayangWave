#ifndef MAPSETLIST_H
#define MAPSETLIST_H
#include <stdio.h>
#include "../MesinKalimat/mesinkalimat.h"
#include "../boolean.h"

/* MODUL MapAlbum
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1

#define AlbumMax 10
#define Undefined -99

// typedef int bool;
typedef int idAlbum;

// 5
typedef struct
{   
  Kalimat JudulLagu[15];
  int Count;
} SetLagu;

// 4
typedef struct {
	Kalimat NamaAlbum;
	SetLagu IsiLagu; // set Lagu dari suatu album
} MapLagu;

// 3
typedef struct
{
	MapLagu AlbumLagu[10];
	int NEff;
} ListAlbum;

// 2
typedef struct {
	Kalimat NamaPenyanyi;
	ListAlbum ListAlbums; // array of ListAlbum yang dimiliki penyanyi
} MapAlbum;

// 1
typedef struct {
	MapAlbum PenyanyiAlbum[10];
	int NEff;
} ListPenyanyi;

void CreateEmptyListPenyanyi(ListPenyanyi *LP);

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi);

void AddAlbum(ListPenyanyi * LP, Kalimat Album);

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu);

MapAlbum SearchListAlbum(ListPenyanyi *LP, Kalimat Penyanyi);

MapLagu SearchListLagu(ListPenyanyi *LP, Kalimat Penyanyi, Kalimat Album);

#endif