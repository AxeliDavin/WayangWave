#include <stdlib.h>
#include <stdio.h>
#include "console.h"

/*Global Variable*/
Queue queue;
Stack History;
Queue antre;
Playlist playlist;
ListPlaylist daftarPlaylist;
ListPenyanyi Penyanyi;
MapAlbum Album;
SetLagu Song;
CurrentSong Lagu;


/*Tempat Command*/

/*Fungsi Utama*/
void readCommand(){

    /*Pembuatan Kosong*/
    CreateEmptyListPenyanyi(&Penyanyi);

    /*Pembuatan List Linier Playlist*/
    CreateEmptyPlaylist(&playlist);
    CreateQueue(&queue);
    
    boolean masuksesi = false, stopsesi = false, isPlaying = false;

    /*Masuk Ke Command Utama*/
    while(!stopsesi){

        readInput();

        if(IsKataSama(currentWord.TabWord, "START")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                Start(&Penyanyi, "../save/config.txt");
                masuksesi = true;
            }
        } 
        
        else if (IsKataSama(currentWord.TabWord, "LOAD")){
            if (masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Udah masuk sesi jadi tidak bisa dirun*/
            } else {
                ADVWORD();
                char path[50] = "../save/";
                for (int i = 0; i < currentWord.Length; i++){
                    path[i+8] = currentWord.TabWord[i];
                }
                Load(&Penyanyi, path);
                masuksesi = true;
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
            isPlaying = true;
        } 

        else if (IsKataSama(currentWord.TabWord, "QUEUE")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "SONG")){
                if (!masuksesi){
                    printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                } else {
                    songQueue();
                } 
            // } else if (IsKataSama(currentWord.TabWord, "PLAYLIST")){
            //     if (!masuksesi){
            //         printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
            //     } else {
            //         playlistQueue();
            //     } 
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

        else if(IsKataSama(currentWord.TabWord, "SONG")){
            ADVWORD();
            if (IsKataSama(currentWord.TabWord, "NEXT")){
                if (!masuksesi){
                        printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                    } else {
                        songNext();
                    } 
                } else if (IsKataSama(currentWord.TabWord, "PREVIOUS")){
                    if (!masuksesi){
                        printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
                    } else {
                        songPrevious();
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
                    addSongToPlaylist();
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

        else if (IsKataSama(currentWord.TabWord, "STATUS")){
            if (!masuksesi){
                printf("Command tidak bisa dieksekusi!\n"); /*Belom masuk sesi jadi tidak bisa dirun*/
            } else {
                masuksesi = true;
                Status();
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
            // printf("kata 2: %s\n", currentWord.TabWord);
            printf("Command tidak diketahui!\n"); /*Tidak ada di list command*/
        }
    }
}

/*START*/
void Start(ListPenyanyi *LP, char path[])
{

    STARTKALIMATFILE(path);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int loop = atoi(CLine.TabLine);
    if (loop > 0)
    {

        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            int album = atoi(CLine.TabLine);
            ADVKALIMAT();
            
            AddPenyanyi(LP, CLine);

            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(CLine.TabLine);
            ADVKALIMAT();

            AddAlbum(LP, CLine);

            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();
                AddLagu(LP, CLine);
            }
            }
        }
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    }
}


/*LOAD*/
void Load(ListPenyanyi * LP, char filename[])
{

    STARTKALIMATFILE(filename);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;

    int loop = atoi(CLine.TabLine);
    if (loop > 0)
    {

        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            int album = atoi(CLine.TabLine);
            
            ADVKALIMAT();
            
            AddPenyanyi(LP, CLine);
            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            int lagu = atoi(CLine.TabLine);

            ADVKALIMAT();

            AddAlbum(LP, CLine);

            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();

                AddLagu(LP, CLine);
            }
            }
        }
        ADVKALIMAT();
        Lagu.NamaPenyanyi = CLine;
        ADVRECORD();
        Lagu.NamaAlbum = CLine;
        ADVRECORD();
        Lagu.JudulLagu = CLine;
        ADVKALIMAT();

            int loopRecordQ = atoi(CLine.TabLine);
            for (int i = 0; i < loopRecordQ; i++) // Queue
            {  contentQueue lagu;
                ADVRECORD();
                lagu.NamaPenyanyi = CLine;
                ADVRECORD();
                lagu.NamaAlbum = CLine;
                ADVRECORD();
                lagu.JudulLagu = CLine;

                enqueue(&antre, lagu);
            }

            ADVKALIMAT();
            int loopRecordR = atoi(CLine.TabLine);
            for (int i = 0; i < loopRecordR; i++) // History input
            {
                contentStack song;
                ADVRECORD();
                song.NamaPenyanyi = CLine;
                ADVRECORD();
                song.NamaAlbum = CLine;
                ADVRECORD();
                song.JudulLagu = CLine;

                Push(&History, song);
            }


            ADVKALIMAT();
            int loopRecordP = atoi(CLine.TabLine); // Jumlah Playlist
            for (int i = 0; i < loopRecordP; i++) // Loop Playlist
            {

                ADVSATUKATA();
                int LaguPlaylist = atoi(CLine.TabLine);
                for (int j = 0; j < LaguPlaylist; j++)
                {   
                    
                    infoType Songss;

                    ADVRECORD();
                    Songss.NamaPenyanyi = CLine;

                    ADVRECORD();
                    Songss.NamaAlbum = CLine;

                    ADVRECORD();
                    Songss.JudulLagu = CLine;
                    InsVLastLinked(playlist.lagu2, Songss);
                }
            }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
    else
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}



// // FUNGSI LIST
// // Command : LIST DEFAULT
void listDefault(){
    printf("Daftar penyanyi :\n");

    for (int i = 0; i < Penyanyi.NEff; i++)
    {
        printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }
    
    printf("Ingin melihat album yang ada?(Y/N): ");
    STARTWORD();
    STARTWORD();

    // PILIH ALBUM
    if (IsKataSama(currentWord.TabWord, "Y") || IsKataSama(currentWord.TabWord, "y"))
    {

        printf("Pilih penyanyi untuk melihat album mereka: ");
        Word inputpenyanyi = takeInput();

        // Word katatemp = takeInput();
        // printf("%s", katatemp.TabWord);
        int chosenSingerIdx = InvalidIdx;
        // Cek apakah nama penyanyi valid
        for (int i = 0; i < Penyanyi.NEff; i++)
        {   

            if (isInputEqual(Penyanyi.PenyanyiAlbum[i].NamaPenyanyi, inputpenyanyi.TabWord))
            {
                chosenSingerIdx = i;
                break;
            }
            
        }
        
        // chosenSingerIdx = IndexOf(Penyanyi, chosenSinger);
        if (chosenSingerIdx == InvalidIdx) {
            printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", inputpenyanyi.TabWord);
            return;
        }

        // Nampilin daftar album yang dimiliki penyanyi
        printf("Daftar Album oleh %s :\n", inputpenyanyi.TabWord);
        int nomorAlbum = 0;        
        for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++) {
            nomorAlbum++;
            printf("   %d. %s\n", nomorAlbum, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum.TabLine);
        }

        printf("Ingin melihat lagu yang ada?(Y/N): ");
        STARTWORD();
        STARTWORD();

        // LIHAT LAGU
        if (IsKataSama(currentWord.TabWord, "Y") || IsKataSama(currentWord.TabWord, "y"))
        {

            printf("Pilih album untuk melihat lagu yang ada di album: ");
            Word inputalbum = takeInput();

            // Cek apakah nama album valid
            int chosenAlbumIdx = InvalidIdx;
            for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++)
            {
                if (isInputEqual(Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum, inputalbum.TabWord))
                {
                    chosenAlbumIdx = i;
                    break;
                }
            }

            if (chosenAlbumIdx == InvalidIdx) {
                printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", inputalbum.TabWord);
                return;
            }

            // Nampilin daftar lagu yang di dalam album
            printf("Daftar Lagu di %s :\n", inputalbum.TabWord);
            int nomorLagu = 0;
            for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.Count; i++) {
                printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[i].TabLine);
            }
        }
        else if(IsKataSama(currentWord.TabWord, "N") || IsKataSama(currentWord.TabWord, "n")){
            return;
        }
        else{
            printf("Input tidak valid\n");
        }  
    }else if(IsKataSama(currentWord.TabWord, "N") || IsKataSama(currentWord.TabWord, "n")){
        return;
    }else{
        printf("Input tidak valid\n");
    }
}

// Command : LIST PLAYLIST
void listPlaylist(){
    printf("Daftar playlist yang kamu miliki: \n");
    int nomorDaftarPlaylist = 0;
    playlistaddress P = FirstPL(daftarPlaylist.A);

    if (P == Nil)
    {
        printf("Kamu tidak memiliki playlist.\n");
        return;
    }

    while (P != Nil)
    {
        nomorDaftarPlaylist++;
        printf("   %d. %s\n", nomorDaftarPlaylist, P->detail.namaPlaylist->TabLine);
        P = NextPL(P);
    }
}


// FUNGSI PLAY
// Command: PLAY SONG
void playSong(){
    printf("Daftar Penyanyi: \n");
    for (int i = 0; i < Penyanyi.NEff; i++)
    {
        printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    // PILIH PENYANYI
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    Word chosensinger = takeInput();

    int chosenSingerIdx = InvalidIdx;
    // Cek apakah nama penyanyi valid
    for (int i = 0; i < Penyanyi.NEff; i++)
    {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[i].NamaPenyanyi, chosensinger.TabWord))
        {
            chosenSingerIdx = i;
            break;
        }
        
    }
    if (chosenSingerIdx == InvalidIdx) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", chosensinger.TabWord);
        return;
    }

    // Nampilin daftar album yang dimiliki penyanyi
    printf("Daftar Album oleh %s :\n", chosensinger.TabWord);
    int nomorAlbum = 0;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++) {
        nomorAlbum++;
        printf("   %d. %s\n", nomorAlbum, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum.TabLine);
    }


    // PILIH ALBUM

    printf("Masukkan Nama Album yang dipilih: ");
    STARTWORD();
    Word chosenalbum = takeInput();

    // Cek apakah nama album valid
    int chosenAlbumIdx = InvalidIdx;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++)
    {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum, chosenalbum.TabWord))
        {
            chosenAlbumIdx = i;
            break;
        }
    }
    
    if (chosenAlbumIdx == InvalidIdx) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenalbum.TabWord);
        return;
    }

    // Nampilin daftar lagu yang di dalam album
    printf("Daftar Lagu Album %s oleh %s :\n", chosenalbum.TabWord, chosensinger.TabWord);
    int nomorLagu = 0;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].IsiLagu.Count; i++) {
        nomorLagu++;
        printf("   %d. %s\n", nomorLagu, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[i].TabLine);
    }

    // PILIH LAGU
    int chosenSongIdx;
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTWORD();
    STARTWORD();
    chosenSongIdx = WordToInt(&currentWord);

    if (chosenSongIdx > nomorLagu)
    {
        printf("ID Lagu tidak valid\n");
        return;
    }
    
    printf("Memutar lagu \"%s\" oleh \"%s\".", Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[chosenSongIdx].TabLine, chosensinger.TabWord);
}

// Command : PLAY PLAYLIST
void playPlaylist(){
    int chosenPlaylistIdx;
    printf("Masukkan ID Playlist: ");
    STARTWORD();
    STARTWORD();
    chosenPlaylistIdx = WordToInt(&currentWord);

    printf("Memutar playlist \"%s\".\n", valuePlaylist(daftarPlaylist, chosenPlaylistIdx).namaPlaylist->TabLine);
}

// FUNGSI QUEUE
// Command: QUEUE SONG
void songQueue() {
    // Belum ada penanganan inputan tidak valid. Butuh ga ya?
    // Menampilkan list daftar penyanyi
    printf("Daftar Penyanyi :\n");
    for (int i=0; i<Penyanyi.NEff; i++) {
        printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }
    STARTWORD();
    // Menerima inputan nama penyanyi
    printf("Masukkan Nama Penyanyi: ");
    Word singername = takeInput();

    // Cek inputan nama penyanyi valid atau ga
    int idxSinger = InvalidIdx;
    for (int i=0; i<Penyanyi.NEff; i++) {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[i].NamaPenyanyi, singername.TabWord)) {
            idxSinger = i;
            break;
        }
    }

    if (idxSinger == InvalidIdx) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", singername.TabWord);
        return;
    }

    // Menampilkan list album
    
    printf("Daftar Album oleh %s :\n", singername.TabWord);
    for (int i=0; i<Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.NEff; i++) {
        printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[i].NamaAlbum.TabLine);
    }
    STARTWORD();
    // Menerima inputan nama album
    printf("Masukkan Nama Album yang dipilih : ");
    Word albumTitle = takeInput(); 

    // Cek inputan nama album valid atau ga
    int idxAlbum = InvalidIdx;
    for (int i=0; i<Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.NEff; i++) {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[i].NamaAlbum, albumTitle.TabWord)) {
            idxAlbum = i;
        }
    }

    if (idxAlbum == InvalidIdx) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", albumTitle.TabWord);
        return;
    }

    // Menampilkan list lagu dalam album
    printf("Daftar Lagu Album %s oleh %s : \n", albumTitle.TabWord, singername.TabWord);
    for (int i=0; i<Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].IsiLagu.Count; i++) {
            printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].IsiLagu.JudulLagu[i].TabLine);
        }

    // Menerima inputan ID Lagu
    int songIndex;
    printf("Masukkan ID Lagu yang dipilih : ");
    STARTWORD();
    STARTWORD();
    songIndex = WordToInt(&currentWord);

    // Cek inputan lagu valid atau ga
    if (songIndex > 0 && songIndex <= Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].IsiLagu.Count) {
        dataLagu songToAdd;
        songToAdd.JudulLagu = Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].IsiLagu.JudulLagu[songIndex-1];
        songToAdd.NamaAlbum = Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].NamaAlbum;
        songToAdd.NamaPenyanyi = Penyanyi.PenyanyiAlbum[idxSinger].NamaPenyanyi;
        songToAdd.idxPlaylist = InvalidIdx;
        enqueue(&queue, songToAdd);
        printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", Penyanyi.PenyanyiAlbum[idxSinger].ListAlbums.AlbumLagu[idxAlbum].IsiLagu.JudulLagu[songIndex-1].TabLine, singername.TabWord);
    }
    else {
        printf("Tidak ada lagu dalam daftar. Silakan coba lagi.\n");
        return;
    }
}

// Command: QUEUE PLAYLIST
void playlistQueue() {
    int chosenPlaylistIdx;
    printf("Masukkan ID Playlist: ");
    STARTWORD();
    STARTWORD();
    chosenPlaylistIdx = WordToInt(&currentWord);

    Playlist nextPlaylist = valuePlaylist(daftarPlaylist, chosenPlaylistIdx);



}


// Command: QUEUE SWAP <x> <y>
void swapQueue() {
    ADVWORD();
    int x = WordToInt(&currentWord);
    ADVWORD();
    int y = WordToInt(&currentWord);

    if ((x >= 1 && x <= length(queue)) && (y >= 1 && y <= length(queue))) {
        // Mencari lagu dalam queue yang akan ditukar urutannya
        contentQueue temp = queue.buffer[x];
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
void removeQueue() {
    ADVWORD();
    int id = WordToInt(&currentWord);
    if (id >= 1 && id <= length(queue)) { 
        Queue temp;
        contentQueue songRemoved, val;
        CreateQueue(&temp);
        for (int i=0; i < length(queue); i++) {
            dequeue(&queue, &val);
            if (i != id-1) {
                enqueue(&temp, val); 
            }
            else {
                songRemoved = val;
            }
        }
        while (!isEmptyQueue(temp)){
            dequeue(&temp, &val);
            enqueue(&queue, val);   
            }    
        
        printf("Lagu “%s” oleh “%s” telah dihapus dari queue!\n", songRemoved.JudulLagu, songRemoved.NamaPenyanyi);   
    }
    else {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
    }
}

// Command: QUEUE CLEAR
void clearQueue() {
    CreateQueue(&queue);
    printf("Queue berhasil dikosongkan.\n");
}

//COMMAND SONG
/* Command: SONG NEXT */
void songNext() {
    if (!isEmptyQueue(queue)) {

        // Masukin Lagu yang diputar sekarang ke dalam temp yang bertipe contentStack
        contentStack temp;  //contentStack ga include idPlaylist, jadi yang di history itu dianggap ga punya playlist lagi
        temp.JudulLagu = Lagu.JudulLagu;
        temp.NamaAlbum = Lagu.NamaAlbum;
        temp.NamaPenyanyi = Lagu.NamaPenyanyi;

        // Jadikan head queue jadi current song
        dequeue(&queue,&Lagu);
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.JudulLagu, Lagu.NamaPenyanyi);
    }
    else {
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.JudulLagu, Lagu.NamaPenyanyi);
    }
}

/* Command: SONG PREVIOUS */
void songPrevious() {
    if (!IsEmptyStack(History)) {
        Queue tempQ;
        contentQueue valQ;

        // Pindahin dulu semua isi queue ke tempQ
        for (int i=0; i<length(queue); i++) {
            dequeue(&queue, &valQ);
            enqueue(&tempQ, valQ);
        } // F.S. Keluar dari looping, queue is empty

        // Memasukkannya current song ke queue urutan 1 lalu masukkan elmt dari temp
        enqueue(&queue, Lagu);
        for (int i=0; i<length(tempQ); i++) {
            dequeue(&tempQ, &valQ);
            enqueue(&queue, valQ);
        }
        printf("\n"); // Print biar bisa jalan, kalo udah bisa mungkin dihapus
        CreateEmptyCurrentSong(&Lagu);  //supaya idPlaylistnya Nil
        Pop(&History,&Lagu);

        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.JudulLagu, Lagu.NamaPenyanyi);
    }
    else {
        printf("Riwayat lagu kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.JudulLagu, Lagu.NamaPenyanyi);
    }
}

// COMMAND PLAYLIST
/**
 * Command: PLAYLIST CREATE
*/
void createPlaylist() {
    Playlist daftarPutar;
    CreateEmptyPlaylist(&daftarPutar);

    printf("Masukkan nama playlist yang ingin dibuat : ");
    Word playlistname = takeInput();
    copyKalimat(charToKalimat(playlistname.TabWord), daftarPutar.namaPlaylist);
}

/**
 * Command: PLAYLIST ADD SONG
*/
void addSongToPlaylist() {
    printf("Daftar Penyanyi: \n");
    for (int i = 0; i < Penyanyi.NEff; i++)
    {
        printf("   %d. %s\n", i+1, Penyanyi.PenyanyiAlbum[i].NamaPenyanyi.TabLine);
    }

    // PILIH PENYANYI
    printf("Masukkan Nama Penyanyi yang dipilih: ");
    Word chosensinger = takeInput();

    int chosenSingerIdx = InvalidIdx;
    // Cek apakah nama penyanyi valid
    for (int i = 0; i < Penyanyi.NEff; i++)
    {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[i].NamaPenyanyi, chosensinger.TabWord))
        {
            chosenSingerIdx = i;
            break;
        }
        
    }
    if (chosenSingerIdx == InvalidIdx) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.\n", chosensinger.TabWord);
        return;
    }

    // Nampilin daftar album yang dimiliki penyanyi
    printf("Daftar Album oleh %s :\n", chosensinger.TabWord);
    int nomorAlbum = 0;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++) {
        nomorAlbum++;
        printf("   %d. %s\n", nomorAlbum, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum.TabLine);
    }


    // PILIH ALBUM
    printf("Masukkan Judul Album yang dipilih: ");

    Word chosenalbum = takeInput();

    // Cek apakah nama album valid
    int chosenAlbumIdx = InvalidIdx;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.NEff; i++)
    {
        if (isInputEqual(Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].NamaAlbum, chosenalbum.TabWord))
        {
            chosenAlbumIdx = i;
            break;
        }
    }
    
    if (chosenAlbumIdx == InvalidIdx) {
        printf("Album %s tidak ada dalam daftar. Silakan coba lagi.\n", chosenalbum.TabWord);
        return;
    }

    // Nampilin daftar lagu yang di dalam album
    printf("Daftar Lagu Album %s oleh %s :\n", chosenalbum.TabWord, chosensinger.TabWord);
    int nomorLagu = 0;
    for (int i = 0; i < Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[i].IsiLagu.Count; i++) {
        nomorLagu++;
        printf("   %d. %s\n", nomorLagu, Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[i].TabLine);
    }

    // PILIH LAGU
    int chosenSongIdx;
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTWORD();
    STARTWORD();
    chosenSongIdx = WordToInt(&currentWord);

    if (chosenSongIdx > nomorLagu)
    {
        printf("ID Lagu tidak valid\n");
        return;
    }
    
    printf("Memutar lagu \"%s\" oleh \"%s\".\n", Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[chosenSongIdx].TabLine, chosensinger.TabWord);

    printf("Daftar Playlist Pengguna: \n");
    int nomorDaftarPlaylist = 0;
    playlistaddress P = FirstPL(daftarPlaylist.A);

    while (P != Nil)
    {
        nomorDaftarPlaylist++;
        printf("   %d. %s", nomorDaftarPlaylist, P->detail.namaPlaylist->TabLine);
        P = NextPL(P);
    }
    
    int chosenPlaylistIdx;
    printf("Masukkan ID Playlist yang dipilih: ");
    STARTWORD();
    STARTWORD();
    chosenPlaylistIdx = WordToInt(&currentWord);

    playlistaddress temp = FirstPL(daftarPlaylist.A);
    for (int i = 0; i < chosenPlaylistIdx; i++)
    {
        temp = NextPL(temp);
    }
    
    printf("Lagu dengan judul \"%s\" pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s\n", Penyanyi.PenyanyiAlbum[chosenSingerIdx].ListAlbums.AlbumLagu[chosenAlbumIdx].IsiLagu.JudulLagu[chosenSongIdx].TabLine, chosenalbum.TabWord, chosensinger.TabWord, temp->detail.namaPlaylist->TabLine);
}

/**
 * command: PLAYLIST SWAP <id> <x> <y>
*/
void swapPlaylist() {
    // Penerimaan id, x, dan y melalui command
    ADVWORD();
    int id = WordToInt(&currentWord);
    ADVWORD();    
    int x = WordToInt(&currentWord);
    ADVWORD();
    int y = WordToInt(&currentWord);

    if (id > daftarPlaylist.nEff)
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
        return;
    }
    
    if (x > FirstPL(daftarPlaylist.A)->detail.nEff)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n", x, valuePlaylist(daftarPlaylist, id).namaPlaylist->TabLine);
        return;
    }    
    
    if (y> FirstPL(daftarPlaylist.A)->detail.nEff)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n", y, valuePlaylist(daftarPlaylist, id).namaPlaylist->TabLine);
        return;
    }
    
    address P = FirstPL(daftarPlaylist.A)->detail.lagu2->First;
    for (int i = 1; i < x; i++)
    {
        P = P->next;
    }    
    
    address P1 = FirstPL(daftarPlaylist.A)->detail.lagu2->First;
    for (int i = 1; i < y; i++)
    {
        P1 = P1->next;
    }

    tukarLagu(&P, &P1);

    printf("Berhasil menukar lagu dengan nama \"%s\" dengan \"%s\" di playlist \"%s\"\n", P->info.JudulLagu, P1->info.JudulLagu, valuePlaylist(daftarPlaylist, id).namaPlaylist->TabLine);
}

/**
 * Command: PLAYLIST REMOVE <id> <n>
 * Untuk sekarang diasumsikan id n diterima dari command global PLAYLIST REMOVE
 * 
*/
void removePlaylist() {
    ADVWORD();
    int id = WordToInt(&currentWord);
    ADVWORD();    
    int n = WordToInt(&currentWord);

    if (id > daftarPlaylist.nEff)
    {
        printf("Tidak ada playlist dengan ID %d\n", id);
        return;
    }
    
    if (n > FirstPL(daftarPlaylist.A)->detail.nEff)
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"\n", n, valuePlaylist(daftarPlaylist, id).namaPlaylist->TabLine);
        return;
    }   

    address P = FirstPL(daftarPlaylist.A)->detail.lagu2->First;
    address prec = Nil;
    for (int i = 1; i < n; i++)
    {
        prec = P;
        P = P->next;
    }  

    printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!\n", P->info.JudulLagu.TabLine, P->info.NamaPenyanyi.TabLine, valuePlaylist(daftarPlaylist, id));

    if (prec == Nil)
    {
        FirstPL(daftarPlaylist.A)->detail.lagu2->First = FirstPL(daftarPlaylist.A)->detail.lagu2->First->next;
    }else{
        prec->next = P->next;   
    }
}

/**
 * Command: PLAYLIST DELETE
 * Untuk nampilin daftar playlist sebenernya bisa pake fungsi/command listPlaylist (dibuat Ammar)
*/
void deletePlaylist() {
    printf("Daftar Playlist Pengguna: \n");
    int nomorDaftarPlaylist = 0;
    playlistaddress P = FirstPL(daftarPlaylist.A);

    while (P != Nil)
    {
        nomorDaftarPlaylist++;
        printf("   %d. %s", nomorDaftarPlaylist, P->detail.namaPlaylist->TabLine);
        P = NextPL(P);
    }
    
    int chosenPlaylistIdx;
    printf("Masukkan ID Playlist yang dipilih: ");
    STARTWORD();
    STARTWORD();
    chosenPlaylistIdx = WordToInt(&currentWord);

    if (chosenPlaylistIdx > daftarPlaylist.nEff)
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", chosenPlaylistIdx);
        return;
    }
    

    playlistaddress temp = FirstPL(daftarPlaylist.A);
    playlistaddress prec = Nil;
    for (int i = 0; i < chosenPlaylistIdx; i++)
    {
        prec = temp;
        temp = NextPL(temp);
    }

    printf("Playlist ID %d dengan judul \"%s\" berhasil dihapus.\n", chosenPlaylistIdx, valuePlaylist(daftarPlaylist, chosenPlaylistIdx).namaPlaylist->TabLine);

    if (prec == Nil)
    {
        FirstPL(daftarPlaylist.A) == NextPL(FirstPL(daftarPlaylist.A));
    }else{
        prec = NextPL(temp);
    }
}


/* STATUS*/

void Status() {
    boolean isPlaying = false;
    if (isPlaying) {
        if (Lagu.idxPlaylist != InvalidIdx) {
        //    printf("Current Playlist: %s", playlist[idxPlaylist]);
        }
    }
    printf("Now Playing:\n");
    if (isPlaying) {
        printf("%s - %s - %s", Lagu.NamaPenyanyi.TabLine, Lagu.NamaAlbum.TabLine, Lagu.JudulLagu.TabLine);
    }
    else {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    printf("\n");

    printf("Queue:\n");
    if (!isEmptyQueue(queue)) {
        for (int i=0; i<length(queue); i++) {
            printf("%d. %s - %s - %s\n", i+1, queue.buffer[i].NamaPenyanyi, queue.buffer[i].NamaAlbum, queue.buffer[i].JudulLagu);
        }
    }
    else {
        printf("Your queue is empty.\n");
    }
}


/*SAVE*/
void Save(ListPenyanyi * LP, char filename[])
{
    static FILE * File;
    File = fopen(filename, "w");

    fprintf(File, "%d\n", (*LP).NEff);

    for (int i = 0; i < (*LP).NEff; i++){

        fprintf(File, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbums.NEff, (*LP).PenyanyiAlbum[i].NamaPenyanyi.TabLine);

        for (int j = 0; j < (*LP).PenyanyiAlbum[i].ListAlbums.NEff; j++){
            
            fprintf(File, "%d %s\n", (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].IsiLagu.Count, (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].NamaAlbum.TabLine);
            for (int k = 0; k < (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].IsiLagu.Count; k++)
            {
                ADVKALIMAT();
                if (i == (*LP).NEff && j == (*LP).PenyanyiAlbum[i].ListAlbums.NEff && k == (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].IsiLagu.Count)
                {
                    fprintf(File, "%s", (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].IsiLagu.JudulLagu[k].TabLine);
                }
                else
                {
                    fprintf(File, "%s\n", (*LP).PenyanyiAlbum[i].ListAlbums.AlbumLagu[j].IsiLagu.JudulLagu[k].TabLine);
                }
            }
        }
    }
}

/*QUIT*/
void Quit() {
    char *Input;
    char *fname;
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    STARTWORD();
    STARTWORD();
    // printf("\n");
    // Input = currentWord.TabWord;

    // Cek apakah pengguna ingin save atau tidak
    if (IsKataSama(currentWord.TabWord, "Y") || IsKataSama(currentWord.TabWord, "y")) {
        printf("Masukkan nama file : ");
        Word fname = takeInput();
        printf("// memanggil save\n");
        Save(&Penyanyi, ("../../save/%s", fname.TabWord));
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
    printf("1. LIST\n");
    printf("   DEFAULT -> Untuk menampilkan daftar penyanyi\n");
    printf("   PLAYLIST -> Untuk manampilkan daftar playlist pengguna\n");
    printf("2. PLAY\n");
    printf("   SONG -> untuk memutar lagu sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("   PLAYLIST -> untuk memutar lagu sesuai dengan id playlist yang dipilih\n");
    printf("3. QUEUE\n");
    printf("   SONG -> untuk menambahkan lagu ke queue sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("   PLAYLIST -> untuk menambahkan lagu ke queue sesuai dengan id playlist yang dipilih\n");
    printf("   SWAP <idlagu1> <idlagu2> -> untuk menukar urutan lagu pada queue\n");
    printf("   REMOVE <idlagu> -> untuk menghapus lagu pada queue \n");
    printf("   CLEAR -> untuk menghapus semua lagu pada queue\n");
    printf("4. SONG\n");
    printf("   NEXT -> untuk memutar lagu selanjutnya pada queue\n");
    printf("   PREVIOUS -> untuk memutar lagu sebelumnya dari riwayat\n");
    printf("5. PLAYLIST\n");
    printf("   CREATE -> untuk membuat playlist baru\n");
    printf("   ADD -> untuk menambahkan lagu kedalam playlist sesuai dengan nama penyanyi, nama album, dan id lagu yang dipilih\n");
    printf("   SWAP <idplaylist> <idlagu1> <idlagu2> -> untuk menukar lagu pada playlist\n");
    printf("   REMOVE <idplaylist> <idlagu> -> untuk menghapus lagu dari playlist\n");
    printf("   DELETE -> untuk menghapus playlist sesuai dengan id playlist yang dipilih\n");
    printf("6. STATUS -> untuk menampilkan lagu yang sedang diputar beserta queue dan playlist lagu\n");
    printf("7. SAVE (filename.txt) -> Untuk menyimpan state ke dalam file\n");
    printf("8. QUIT -> Untuk keluar dari sesi\n");
}
