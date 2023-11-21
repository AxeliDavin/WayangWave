#include "../adt.h"

Playlist playlist;

/*LOAD*/
void LOADFILE(ListPenyanyi * LP, char filename[])
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

            int loopRecordQ = atoi(CLine.TabLine);

            for (int i = 0; i < loopRecordQ; i++) // Record Queue
            {  
                ADVRECORD();
                Kalimat NamaPenyanyi = CLine;
                ADVRECORD();
                Kalimat NamaAlbum = CLine;
                ADVRECORD();
                Kalimat NamaLagu = CLine;

                enqueueLagu(NamaLagu, NamaAlbum, NamaPenyanyi);
            }

            ADVKALIMAT();
            int loopRecordR = atoi(CLine.TabLine);

            for (int i = 0; i < loopRecordR; i++) // Record Riwayat
            {
                ADVRECORD();
                Kalimat NamaPenyanyi = CLine;
                ADVRECORD();
                Kalimat NamaAlbum = CLine;
                ADVRECORD();
                Kalimat NamaLagu = CLine;

                PushRiwayatLagu(NamaLagu, NamaAlbum, NamaPenyanyi);
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