#include <stdlib.h>
#include <stdio.h>
#include "console.h"

/*Global Variable*/
List singer, album, song;
List playlist;
Queue queue;

/*Tempat Command*/

/*Fungsi Utama*/
void readCommand(){

    /*Pembuatan List*/
    MakeList(&singer);
    MakeList(&album);
    MakeList(&song);
    MakeList(&playlist);

    /*Pembuatan Queue*/
    CreateQueue(&queue);
    
    boolean masuksesi = false, stopsesi = false;

    /*Masuk Ke Command Utama*/
    while(!stopsesi){

        readInput();

        if(IsKataSama(currentWord.TabWord, "START")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                masuksesi = true;
                Start();
            }
        } 
        
        else if (IsKataSama(currentWord.TabWord, "LOAD")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                masuksesi = true;
                Load();
            }           
        } 
        
        else if (IsKataSama(currentWord.TabWord, "LIST")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "DEFAULT")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    listDefault();
                }               
            } else if (IsKataSama(currentWord.TabWord, "PLAYLIST")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    listPlaylist();
                } 
            } 
        } 

        else if (IsKataSama(currentWord.TabWord, "PLAY")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "SONG")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    playSong();
                }               
            } else if (IsKataSama(currentWord.TabWord, "PLAYLIST")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    playPlaylist();
                } 
            } 
        } 

            else if (IsKataSama(currentWord.TabWord, "QUEUE")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "SONG")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    songQueue();
                } 
            } else if (IsKataSama(currentWord.TabWord, "PLAYLIST")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    playlistQueue();
                } 
            } else if (IsKataSama(currentWord.TabWord, "SWAP")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    swapQueue();
                } 
            } else if (IsKataSama(currentWord.TabWord, "REMOVE")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    removeQueue();
                } 
            } else if (IsKataSama(currentWord.TabWord, "CLEAR")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    clearQueue();
                } 
            }
        }
                
        else if (IsKataSama(currentWord.TabWord, "PLAYLIST")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "CREATE")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    createPlaylist();
                } 
            } else if (IsKataSama(currentWord.TabWord, "ADD")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    addPlaylist();
                } 
            } else if (IsKataSama(currentWord.TabWord, "SWAP")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    swapPlaylist();
                } 
            } else if (IsKataSama(currentWord.TabWord, "REMOVE")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    removePlaylist();
                } 
            } else if (IsKataSama(currentWord.TabWord, "DELETE")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    deletePlaylist();
                } 
            }
        }

        else if (IsKataSama(currentWord.TabWord, "QUIT")){
            if (!masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
            } else {
                masuksesi = true;
                Quit();
            }           
        }

        else if (IsKataSama(currentWord.TabWord, "HELP")){
            if (!masuksesi){
                helpBeforeStart();
            } else {
                masuksesi = true;
                helpAfterStart();
            }           
        }

        else {
            printf("Command tidak diketahui!\n"); /*Tidak ada di list command*/
        }

    }
}

/*START*/
void Start(){
    char filename[256];

    FILE *file = fopen("../save/config.txt", "r");

    int nSinger;
    fscanf(file, "%d", &nSinger);
    for (int i=0; i<nSinger; i++){
        int nAlbum;
        char singertemp;
        fscanf(file, "%d %255s", &nAlbum, &singertemp);
        InsertLast(&singer, singertemp);
        
        for (int j=0; j<nAlbum; j++){
            int nSong;
            char albumtemp;
            fscanf(file, "%d %255s", &nSong, &albumtemp);
            InsertLast(&album, albumtemp);

            for (int k=0; k<nSong; k++){
                char songtemp;
                fscanf(file, "%255s", &songtemp);
                InsertLast(&song, songtemp);
            }
        }
    }
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.");
}

/*LOAD*/
void Load()
{   char filename[256];
    printf("filename: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.");
        return;
    }
    int nSinger;
    fscanf(file, "%d", &nSinger);
    for (int i=0; i<nSinger; i++){// baca line 2 BLACKPINK
        int nAlbum;
        char singertemp;
        fscanf(file, "%d %255s", &nAlbum, &singertemp);
        InsertLast(&singer, singertemp);
        
        for (int j=0; j<nAlbum; j++){// BACA LINE 4 BORNPINK 
            int nSong;
            char albumtemp;
            fscanf(file, "%d %255s", &nSong, &albumtemp);
            InsertLast(&album, albumtemp);

            for (int k=0; k<nSong; k++){
                char songtemp;
                fscanf(file, "%255s", &songtemp);
                InsertLast(&song, songtemp);
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.");
}


// FUNGSI LIST
// Command : LIST DEFAULT
void listDefault(){
    printf("Daftar penyanyi :\n");

    for (int i = 0; i < Length(singer); i++)
    {
        printf("   %d. %s\n", i+1, Get(singer, i));
    }
    
    char lookAlbum;
    printf("Ingin melihat album yang ada?(Y/N): ");
    scanf("%c", &lookAlbum);
    if (lookAlbum == 'Y')
    {
        char chosenSinger[256];
        printf("Pilih penyanyi untuk melihat album mereka: ");
        scanf("%255s", &chosenSinger);

        int chosenSingerIdx;
        // Cek apakah nama penyanyi valid
        chosenSingerIdx = IndexOf(singer, chosenSinger);
        if (chosenSinger == InvalidIdx) {
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenSinger);
            return;
        }

        // Nampilin daftar album yang dimiliki penyanyi
        printf("Daftar Album oleh %s :\n", chosenSinger);
        for (int i = 0; i < Length(album); i++) {
            if (IsEqual(chosenSinger, Get(album, i))) {
                printf("   %d. %s\n", i+1, Get(album, i));
            }
        }

        char lookSong;
        printf("Ingin melihat lagu yang ada?(Y/N): ");
        scanf("%c", &lookSong);

        if (lookSong == 'Y')
        {
            char chosenAlbum[256];
            printf("Pilih penyanyi untuk melihat album mereka: ");
            scanf("%255s", &chosenAlbum);

            int chosenAlbumIdx;
            // Cek apakah nama album valid
            chosenAlbumIdx = IndexOf(album, chosenAlbum);
            if (chosenAlbum == InvalidIdx) {
                printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenSinger);
                return;
            }

            // Nampilin daftar lagu yang di dalam album
            printf("Daftar Lagu di %s :\n", chosenAlbum);
            for (int i = 0; i < Length(song); i++) {
                if (IsEqual(chosenAlbum, Get(song, i))) {
                    printf("   %d. %s\n", i+1, Get(song, i));
                }
            }
        }
        else if(lookSong == 'N'){
            return;
        }
        else{
            printf("Input tidak valid\n");
        }  
    }else if(lookAlbum == 'N'){
        return;
    }else{
        printf("Input tidak valid\n");
    }
}

// Command : LIST PLAYLIST
void listPlaylist(){
    printf("Daftar playlist yang kamu miliki: ");
    if (Length(playlist) > 0)
    {
        for (int i = 0; i < Length(playlist); i++)
        {
            printf("   %d. %s\n", i+1, Get(playlist, i));
        }        
    }else{
        printf("Kamu tidak memiliki playlist.");
    }
}


// FUNGSI PLAY
// Command: PLAY SONG
void playSong(){
    printf("Daftar Penyanyi: \n");
    for (int i = 0; i < Length(singer); i++)
    {
        printf("   %d. %s", i+1, Get(singer, i));
    }

    char chosenSinger[256];
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    scanf("%255s", &chosenSinger);

    int chosenSingerIdx;
    // Cek apakah nama penyanyi valid
    chosenSingerIdx = IndexOf(singer, chosenSinger);
    if (chosenSinger == InvalidIdx) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenSinger);
        return;
    }

    // Nampilin daftar album yang dimiliki penyanyi
    printf("Daftar Album oleh %s :\n", chosenSinger);
    for (int i = 0; i < Length(album); i++) {
        if (IsEqual(chosenSinger, Get(album, i))) {
            printf("   %d. %s\n", i+1, Get(album, i));
        }
    }

    char chosenAlbum[256];
    printf("Masukkan Nama Album yang dipilih: ");
    scanf("%255s", &chosenAlbum);

    int chosenAlbumIdx;
    // Cek apakah nama album valid
    chosenAlbumIdx = IndexOf(album, chosenAlbum);
    if (chosenAlbum == InvalidIdx) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenSinger);
        return;
    }

    // Nampilin daftar lagu yang di dalam album
    printf("Daftar Lagu di %s :\n", chosenAlbum);
    for (int i = 0; i < Length(song); i++) {
        if (IsEqual(chosenAlbum, Get(song, i))) {
            printf("   %d. %s\n", i+1, Get(song, i));
        }
    }

    int chosenSongIdx;
    printf("Masukkan ID Lagu yang dipilih: ");
    scanf("%d", &chosenSongIdx);

    printf("Memutar lagu \"%s\" oleh \"%s\".", Get(song, chosenSongIdx), Get(singer, chosenSingerIdx));
}

// Command : PLAY PLAYLIST
void playPlaylist(){
    int chosenPlaylistIdx;
    printf("Masukkan ID Playlist: ");
    scanf("%d", &chosenPlaylistIdx);

    printf("Memutar playlist \"%s\".", Get(playlist, chosenPlaylistIdx));
}

// FUNGSI QUEUE

// Command: QUEUE SONG
void songQueue() {
    // Belum ada penanganan inputan tidak valid. Butuh ga ya?
    // Menampilkan list daftar penyanyi
    printf("Daftar Penyanyi :\n");
    for (int i=0; i<Length(singer); i++) {
        printf("%s\n", Get(singer, i));
    }

    // Menerima inputan nama penyanyi
    char singerName[256];
    printf("Masukkan Nama Penyanyi: ");
    scanf("%255s\n", singerName);

    // Menampilkan list daftar album
    printf("Daftar Album oleh %s :\n", singerName);
    for (int i=0; i<Length(album); i++) {
        if (IsIdxEff(album, i) && Search(album, singerName)) {
            printf("%s\n", Get(album, i));
        }
    }

    // Menerima inputan nama album
    char albumTitle[256];
    printf("Masukkan Nama Album yang dipilih : ");
    scanf("%255s\n", albumTitle);

    // Menampilkan list lagu dalam album
    printf("Daftar Lagu Album %s oleh %s : \n", albumTitle, singerName);
    for (int i=0; i<Length(song); i++) {
        if (IsIdxEff(song, i) && Search(song, singerName)) {
            printf("%d. %s\n", i + 1, Get(song, i));
        }
    }

    // Menerima inputan ID Lagu
    int songIndex;
    printf("Masukkan ID Lagu yang dipilih : ");
    scanf("%d", &songIndex);

    // Nambahin lagu ke queue
    ElTypeQueue songToAdd = Get(song, songIndex-1);
    enqueue(&queue,songToAdd);
    printf("Berhasil menambahkan lagu “%s” oleh “%s” ke queue.", songToAdd, singerName);
}

// Command: QUEUE PLAYLIST
void playlistQueue() {

    // Menerima inputan ID Playlist
    int playlistIndex;
    printf("Masukkan ID Playlist ");
    scanf("%d", &playlistIndex);

    // Menambahkan lagu dalam playlist ke dalam queue
    
    ElTypeList playlistToAdd = Get(playlist, playlistIndex-1);

    // ini masih salah btww, masih clueless how to add the songs in the playlist meanwhile the eltypelist is int?! nanti coba nanya ke temen dulu yzzz
    enqueue(&queue,playlistToAdd);
    printf("Berhasil menambahkan playlist “%s” ke queue.", playlistToAdd);
}


// Command: QUEUE SWAP <x> <y>
void queueSwap() {
    ADV();
    int x = WordToInt(&currentWord);
    ADV();
    int y = WordToInt(&currentWord);

    if ((x >= 1 && x <= length(queue)) && (y >= 1 && y <= length(queue))) {
        // Mencari lagu dalam queue yang akan ditukar urutannya
        ElTypeQueue temp[256] = queue.buffer[x];
        queue.buffer[x] = queue.buffer[y];
        queue.buffer[y] = temp;
        printf("Lagu %s berhasil ditukar dengan %s\n", queue.buffer[x], queue.buffer[y]);
    }
    else {
        if ((x < 1 || x > length(queue)) && y >= 1 && y <= length(queue)) {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else if (x >= 1 && x <= length(queue) && (y < 1 || y > length(queue))) {
            printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y) ;
        }
        else if ((x < 1 || x > length(queue)) && (y < 1 || y > length(queue))){
            printf("Lagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", x, y);
        }
    }
}

// Command: QUEUE REMOVE <id>
void queueRemove() {
    ADV();
    int id = WordToInt(&currentWord);
    if (id >= 1 && id <= length(queue)) { 
        Queue temp;
        ElTypeQueue val;
        CreateQueue(&temp);
        for (int i=0; i < length(queue); i++) {
            dequeue(&queue, &val);
            if (i != id-1) {
                enqueue(&temp, val); 
            }
        }
        while (!isEmptyQueue(temp)){
            dequeue(&temp, &val);
            enqueue(&queue, val);
            }    
        
        // masih kurang nge-print judul lagu dan nama artis di sini
    }
    else {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
    }
}

// Command: QUEUE CLEAR
void queueClear() {
    CreateQueue(&queue);
    printf("Queue berhasil dikosongkan.\n");
}

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
    singerIndex = -1;
    for (int i = 0; i < Length(singer); i++) {
        if (Search(singer, singerName)) {
            singerIndex = i;
            break;
        }
    }

    if (!IsIdxEff(singer, singerIndex) || !Search(singer, singerName)) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", singerName);
        return;
    }

    // Nampilin daftar album + nerima input nama album
    printf("Daftar Album oleh %s :\n", singerName);
    for (int i = 0; i < Length(album); i++) {
        if (IsIdxEff(album, i) && Search(album, singerName)) {
            printf("%s\n", Get(album, i));
        }
    }

    char albumTitle[256];
    int albumIndex;

    printf("Masukkan Judul Album yang dipilih : ");
    scanf("%255s", albumTitle);

    // Cek apakah nama album valid
    albumIndex = -1;
    for (int i = 0; i < Length(album); i++) {
        if (IsIdxEff(album, i) && Search(album, albumTitle)) {
            albumIndex = i;
            break;
        }
    }

    if (!IsIdxEff(album, albumIndex) || !Search(album, albumTitle)) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", albumTitle);
        return;
    }

    // Nampilin daftar lagu + nerima input lagu
    printf("Daftar Lagu Album %s oleh %s : \n", albumTitle, singerName);
    for (int i = 0; i < Length(song); i++) {
        if (IsIdxEff(song, i) && Search(song, singerName)) {
            printf("%d. %s\n", i + 1, Get(song, i));
        }
    }

    int songIndex;

    // Pengecekan indeks lagu yang valid
    if (Length(song) == 0) {
        printf("Tidak ada lagu dalam daftar. Silakan coba lagi.\n");
        return;
    }

    printf("Masukkan ID Lagu yang dipilih : ");
    scanf("%d", &songIndex);

    // Pengecekan apakah indeks lagu valid
    if (!IsIdxEff(song, songIndex - 1) || !Search(song, singerName) || !Search(song, albumTitle)) {
        printf("ID Lagu tidak valid. Silakan coba lagi.\n");
        return;
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
*/
void swapPlaylist() {
    // Penerimaan id, x, dan y melalui command
    ADV();
    int id = WordToInt(&currentWord);
    ADV();
    int x = WordToInt(&currentWord);
    ADV();
    int y = WordToInt(&currentWord);

    if (IsIdxValid(playlist, id)) {
        // Mencari elemen playlist yang akan dituker lagu-lagunya
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
void removePlaylist() {
    // Nerima id dan n dari melalui command
    ADV();
    int id = WordToInt(&currentWord);
    ADV();
    int n = WordToInt(&currentWord);    

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

/*SAVE*/
void Save(){

}

/*QUIT*/
void Quit() {
    char Input;
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    scanf(" %c", &Input);

    // Cek apakah pengguna ingin save atau tidak
    if (Input == 'Y' || Input == 'y') {
        Save();
        printf("// memanggil save\n");
    }

    printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
    exit(0);
}

/*HELP*/
void helpBeforeStart() {
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. START -> Untuk masuk sesi baru\n");
    printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
}
    
void helpAfterStart() {
    printf("=====[ Menu Help WayangWave ]=====\n");
    printf("1. LIST DEFAULT -> Untuk menampilkan daftar penyanyi\n");
    printf("2. LIST PLAYLIST -> Untuk manampilkan daftar playlist pengguna\n");
    printf("3. PLAY SONG -> untuk memutar lagu sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("4. PLAY PLAYLIST -> untuk memutar lagu sesuai dengan id playlist yang dipilih\n");
    printf("5. QUEUE SONG -> untuk menambahkan lagu ke queue sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("6. QUEUE PLAYLIST -> untuk menambahkan lagu ke queue sesuai dengan id playlist yang dipilih\n");
    printf("7. QUEUE SWAP <idlagu1> <idlagu2> -> untuk menukar urutan lagu pada queue\n");
    printf("8. QUEUE REMOVE <idlagu> -> untuk menghapus lagu pada queue \n");
    printf("9. QUEUE CLEAR -> untuk menghapus semua lagu pada queue\n");
    printf("10. SONG NEXT -> untuk memutar lagu selanjutnya pada queue\n");
    printf("11. SONG PREVIOUS -> untuk memutar lagu sebelumnya dari riwayat\n");
    printf("12. PLAYLIST CREATE -> untuk membuat playlist baru\n");
    printf("13. PLAYLIST ADD -> untuk menambahkan lagu kedalam playlist sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("14. PLAYLIST SWAP <idplaylist> <idlagu1> <idlagu2> -> untuk menukar lagu pada playlist\n");
    printf("15. PLAYLIST REMOVE <idplaylist> <idlagu> -> untuk menghapus lagu dari playlist\n");
    printf("16. PLAYLIST DELETE -> untuk menghapus playlist sesuai dengan id playlist yang dipilih\n");
    printf("17. STATUS -> untuk menampilkan lagu yang sedang diputar beserta queue dan playlist lagu\n");
    printf("18. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("19. QUIT -> Untuk keluar dari sesi\n");
}
