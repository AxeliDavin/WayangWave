// playlist.h
/* File : playlist.h */
/* ADT Playlist menggunakan list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah pointer to char */

#ifndef playlist_H
#define playlist_H

#include <stdio.h>
#include "../MesinKalimat/mesinkalimat.h"
#include "../Listlinier/listlinier.h"

/* Kamus Umum */
#define INITIAL_CAPACITY 100
#define Nil NULL

/*Definisi Struktur Data*/
typedef Kalimat infotype;

typedef struct tElmtplaylist *playlistaddress;
// typedef struct {
//     infotype lagu;
//     infotype album;
//     infotype penyanyi;
// } contents;

typedef struct {
    int nEff;
    int capacity;
    Kalimat *namaPlaylist;
    ListLinier *lagu2;
} Playlist;

typedef struct tElmtplaylist { 
	// contents infoLagu;
    // infotype namaPlaylist;
    Playlist detail;
	playlistaddress next;
} ElmtPlayList;

// typedef struct {
//     Kalimat namaPlaylist;
// 	playlistaddress First;
// } Isi;

typedef struct {
	playlistaddress First;
} Isi;

typedef struct {
    Isi A; // Ukuran Alokasi saat ini
    int capacity; //Elemen List
    int nEff; // Jumlah Elemen Efektif
} ListPlaylist;

#define InfoPL(P) (P)->namaPlaylist
#define NextPL(P) (P)->next
#define FirstPL(L) ((L).First)

void CreateEmptyPlaylist(Playlist *x);

Playlist valuePlaylist(ListPlaylist daftarPlaylist, int idx);

Songs laguPlaylist(Playlist a, int idx);

#endif