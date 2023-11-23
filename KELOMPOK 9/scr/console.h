#include "adt.h"

/*Tempat Command*/

void readCommand();
/*Fungsi Utama*/

void Start(ListPenyanyi *LP, char path[]);
/*Pertama kali memulai WayangWave*/

// void Load(ListPenyanyi * LP, char filename[]);

void listDefault();

void listPlaylist();

void playSong();

void playPlaylist();

// void songQueue();

// void playlistQueue();

// void swapQueue();

// void removeQueue();

// void clearQueue();

void createPlaylist();

void addSongToPlaylist();

void swapPlaylist();

void removePlaylist();

void deletePlaylist();

void Status();

void Save(ListPenyanyi * LP, char filename[]);

void Quit();

void helpBeforeStart();

void helpAfterStart();