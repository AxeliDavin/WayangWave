
// playlist.h
/* File : playlist.h */
/* ADT Playlist menggunakan list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah pointer to char */

#ifndef playlist_H
#define playlist_H

/* Kamus Umum */
#define INITIAL_CAPACITY 100
#define Nil NULL

/*Definisi Struktur Data*/
typedef char *infotype;
typedef char *name;

typedef struct tElmtlist *address;
typedef struct {
    infotype lagu;
    infotype album;
    infotype penyanyi;
} content;

typedef struct tElmtlist { 
	content infoLagu;
	address next;
} ElmtList;

typedef struct {
    name namaPlaylist;
	address First;
} Playlist;

typedef struct {
    Playlist *A; // Ukuran Alokasi saat ini
    int capacity; //Elemen List
    int nEff; // Jumlah Elemen Efektif
} ListPlaylist

#endif