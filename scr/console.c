#include <stdlib.h>
#include <stdio.h>
#include "console.h"

/*Tempat Command*/

void STARTC(){ //namanya STARTC karena START udah ada di mesinkar
    
    printf ("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    readInput();
}

List singer, album, song;

void load()
{   char filename[256];
    printf("filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.");
        return 1;
    }
    int nSinger;
    fscanf(file, "%d", &nSinger);
    Makelist(&singer);
    for (int i=0; i<nSinger; i++){// baca line 2 BLACKPINK
        int nAlbum;
        char singertemp;
        fscanf(file, "%d %255s", &nAlbum, &singertemp);
        InsertLast(&singer, singertemp);

        Makelist(&album);
        
        for (int j=0; j<nAlbum; j++){// BACA LINE 4 BORNPINK 
            int nSong;
            char albumtemp;
            fscanf(file, "%d %255s", &nSong, &albumtemp);
            InsertLast(&album, albumtemp);

            MakeList(&song);

            for (int k=0; k<nSong; k++){
                char songtemp;
                fscanf(file, "%255s", &songtemp);
                InsertLast(&song, songtemp);
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.");
}


void ListDefault(){
    load();
    printf("Daftar penyanyi :\n");

    for (int i = 0; i < Length(singer); i++)
    {
        printf("   %d. %c\n", i+1, Get(singer, i));
    }
    
    char lookalbum;
    scanf("Ingin melihat album yang ada?(Y/N): %c", &lookalbum);
    if (lookalbum == 'Y')
    {
        char chosenalbum;
        scanf("Pilih penyanyi untuk melihat album mereka: %c", &chosenalbum);

    }
    

}

void ListPlaylist(){
    
}


List playlist; // Global variable for list of playlists

/**
 * Command: PLAYLIST CREATE
*/
void createPlaylist() {
    char playlistName[256];
    printf("Masukkan nama playlist yang ingin dibuat : ");
    scanf("%255s", playlistName);

    List newPlaylist = MakeList();
    InsertLast(&playlist, playlistName);
}

/**
 * Command: PLAYLIST ADD SONG
*/
void addPlaylist() {
    // Nampilin daftar penyanyi + nerima input nama penyanyi
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < Length(singer); i++) {
        printf("%s\n", Get(singer, i));
    }

    char singerName[256];
    int singerIndex;

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    scanf("%255s", singerName);

    // Cek apakah nama penyanyi valid
    singerIndex = IndexOf(singer, singerName);
    if (singerIndex == InvalidIdx) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", singerName);
        return;
    }

    // Nampilin daftar album + nerima input nama album
    printf("Daftar Album oleh %s :\n", singerName);
    for (int i = 0; i < Length(album); i++) {
        if (IsEqual(singerName, Get(album, i))) {
            printf("%s\n", Get(album, i));
        }
    }

    char albumTitle[256];
    int albumIndex;

    printf("Masukkan Judul Album yang dipilih : ");
    scanf("%255s", albumTitle);

    // Cek apakah nama album valid
    albumIndex = IndexOf(album, albumTitle);
    if (albumIndex == InvalidIdx || !IsEqual(singerName, Get(album, albumIndex))) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", albumTitle);
        return;
    }

    // Nampilin nama lagu + nerima input lagu
    printf("Daftar Lagu Album %s oleh %s : \n", albumTitle, singerName);
    for (int i = 0; i < Length(song); i++) {
        if (IsEqual(singerName, Get(song, i)) && IsEqual(albumTitle, Get(album, i))) {
            printf("%d. %s\n", i + 1, Get(song, i));
        }
    }

    int songIndex;

    printf("Masukkan ID Lagu yang dipilih : ");
    scanf("%d", &songIndex);

    // Nampilin daftar playlist + nerima input daftar playlist (sebenernya bisa pake listPlaylist)
    printf("Daftar Playlist Pengguna : \n");
    for (int i = 0; i < Length(playlist); i++) {
        printf("%d. %s\n", i + 1, Get(playlist, i));
    }

    int playlistIndex;

    printf("Masukkan ID Playlist yang dipilih : ");
    scanf("%d", &playlistIndex);

    // Nambahin lagu ke playlist
    ElTypeList songToAdd = Get(song, songIndex - 1);
    InsertLast(Get(playlist, playlistIndex - 1), songToAdd);
    printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", songToAdd, albumTitle, singerName, Get(playlist, playlistIndex - 1));
}

/**
 * command: PLAYLIST SWAP <id> <x> <y>
 * Untuk sekarang diasumsikan id x dan y diterima dari command global PLAYLIST SWAP
*/
void swapPlaylist(int id, int x, int y) {
    if (IsIdxValid(playlist, id)) {
        // Mencari elemen playlist yang akan dimasukan lagu
        List *selectedPlaylist = Get(playlist, id - 1);

        // Cek apakah x dan y valid
        if (IsIdxEff(*selectedPlaylist, x) && IsIdxEff(*selectedPlaylist, y)) {
            // Tukar lagu:
            ElTypeList temp = Get(*selectedPlaylist, x - 1);
            SetList(selectedPlaylist, x - 1, Get(*selectedPlaylist, y - 1));
            SetList(selectedPlaylist, y - 1, temp);

            printf("Berhasil menukar lagu dengan nama \"%s\" dengan \"%s\" di playlist \"%s\"\n",
                   Get(*selectedPlaylist, x - 1), Get(*selectedPlaylist, y - 1), Get(playlist, id - 1));
        } else {
            printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n", (x > y) ? y : x, Get(playlist, id - 1));
        }
    } else {
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
    }
}

/**
 * Command: PLAYLIST REMOVE <id> <n>
 * Untuk sekarang diasumsikan id n diterima dari command global PLAYLIST REMOVE
 * 
*/
void removePlaylist(int id, int n) {
    // Check indeks playlist valid or no
    if (IsIdxValid(playlist, id)) {
        // Akses indeks playlist
        List *selectedPlaylist = Get(playlist, id - 1);

        // Cek indeks lagu dalam playlist valiid or no
        if (IsIdxEff(*selectedPlaylist, n)) {
            // Akses indeks lagu di dalam playlist
            ElTypeList removedSong = Get(*selectedPlaylist, n - 1);

            // Hapus elemen lagu dari playlist
            DeleteAt(selectedPlaylist, n - 1);

            printf("Lagu \"%s\" telah dihapus dari playlist \"%s\"!\n", removedSong, Get(playlist, id - 1));
        } else {
            printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"!\n", n, Get(playlist, id - 1));
        }
    } else {
        printf("Tidak ada playlist dengan playlist ID %d.\n", id);
    }
}

/**
 * Command: PLAYLIST DELETE
 * Untuk nampilin daftar playlist sebenernya bisa pake fungsi/command listPlaylist (dibuat Ammar)
*/
void deletePlaylist() {
    // Nampilin daftar playlist + nerima input id playlist
    printf("Daftar Playlist Pengguna : \n");
    for (int i = FirstIdx(playlist); i <= LastIdx(playlist); i++) {
        printf("%s\n", Get(playlist, i));
    }

    int playlistId;
    printf("\nMasukkan ID Playlist yang dipilih : ");
    scanf("%d", &playlistId);

    // Cek apakah id valid or no
    if (IsIdxValid(playlist, playlistId)) {
        // Dapetin nama playlistnya
        ElTypeList deletedPlaylistTitle = Get(playlist, playlistId - 1);

        // Ngapus elemen list dari list of playlists
        DeleteAt(&playlist, playlistId - 1);

        printf("\nPlaylist ID %d dengan judul \"%s\" berhasil dihapus.\n", playlistId, deletedPlaylistTitle);
    } else {
        printf("\nTidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", playlistId);
    }
}









