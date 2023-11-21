#include "../adt.h"

Playlist playlist;

/*LOAD*/
void LOADFILE(ListPenyanyi * LP, char filename[])
{

    STARTKALIMATFILE(filename);

    Kalimat NamaPenyanyi;
    Kalimat NamaAlbum;
    Kalimat NamaLagu;
    Stack History;
    Queue antre;

    CreateEmptyStack(&History);
    CreateQueue(&antre);

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

                ADVKALIMAT();

                for (int j = 0; j < LaguPlaylist; j++)
                {   
                    infoType Data;

                    ADVRECORD();
                    Data.NamaPenyanyi = CLine;

                    ADVRECORD();
                    Data.NamaAlbum = CLine;

                    ADVRECORD();

                    InsVLast(&playlist, Data);

                }
            }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        }
    else
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}