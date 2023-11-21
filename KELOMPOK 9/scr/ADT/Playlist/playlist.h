
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
typedef Kalimat infotype;
typedef char *name;

typedef struct tElmtplaylist *playlistaddress;
typedef struct {
    infotype lagu;
    infotype album;
    infotype penyanyi;
} contents;

typedef struct tElmtplaylist { 
	contents infoLagu;
	playlistaddress next;
} ElmtPlayList;

typedef struct {
    name namaPlaylist;
	playlistaddress First;
} Playlist;

typedef struct {
    Playlist *A; // Ukuran Alokasi saat ini
    int capacity; //Elemen List
    int nEff; // Jumlah Elemen Efektif
} ListPlaylist;

void CreateEmptyPlaylist(Playlist *x);

#endif