#include "songalbumsinger.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyListPenyanyi(ListPenyanyi *LP){
	(*LP).NEff = 0;
	(*LP).PenyanyiAlbum[0].ListAlbums.NEff = 0;
	(*LP).PenyanyiAlbum[0].ListAlbums.AlbumLagu[0].IsiLagu.Count = 0;
}

void AddPenyanyi(ListPenyanyi * LP, Kalimat NamaPenyanyi)
{	
	int indeksPenyanyi = (*LP).NEff;
	(*LP).PenyanyiAlbum[indeksPenyanyi].NamaPenyanyi = NamaPenyanyi;
	(*LP).NEff ++; 
}

void AddAlbum(ListPenyanyi * LP, Kalimat Album)
{
	int indeksPenyanyi = (*LP).NEff - 1; 
	int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.NEff - 1; 
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.AlbumLagu[indeksAlbum].NamaAlbum = Album; 
	(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.NEff ++; 
}

void AddLagu(ListPenyanyi * LP, Kalimat NamaLagu)
{
int indeksPenyanyi = (*LP).NEff - 1;
int indeksAlbum = (*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.NEff - 1;
(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.AlbumLagu[indeksAlbum].IsiLagu.JudulLagu[(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.AlbumLagu[indeksAlbum].IsiLagu.Count] = NamaLagu;
(*LP).PenyanyiAlbum[indeksPenyanyi].ListAlbums.AlbumLagu[indeksAlbum].IsiLagu.Count ++;
}