#ifndef MAPSETLIST_H
#define MAPSETLIST_H
#include <stdio.h>
#include "./MesinKalimat/mesinkalimat.h"
#include "boolean.h"

/* MODUL MapAlbum
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1

#define AlbumMax 100
#define Undefined -999

// typedef int bool;
typedef int idAlbum;

// 5
typedef struct
{   
  Kalimat JudulLagu[20];
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
	ListAlbum ListAlbum; // array of ListAlbum yang dimiliki penyanyi
} MapAlbum;

// 1
typedef struct {
	MapAlbum PenyanyiAlbum[20];
	int NEff;
} ListPenyanyi;

#endif