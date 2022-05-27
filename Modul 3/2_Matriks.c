#include <stdio.h>
#include <stdlib.h>

int validasi();
void inputAngkaMatriks();
void inputAngkaMatriksPenjumlahan();
void inputAngkaMatriksTranspose();
void inputAngkaMatriksPerkalian();
void printMatriks(int matriks[10][10], int baris, int kolom);
void penjumlahan();
void perkalian();
void transpose(int matriks[10][10], int baris, int kolom);
void reinput();
void pilihan();

int matriksA[10][10], matriksB[10][10], matriksC[10][10], barisKolom[5][5];

//validasi integer
int validasi()
{
    int pilihan;
    if (scanf("%d", &pilihan) != 1)
    {
        printf("Hanya masukkan angka!");
        printf("\nMasukan Pilihan Ulang : ");
        fflush(stdin);
        validasi();
    }
    return pilihan;
}

//input angka
void inputAngkaMatriks(pilihan)
{
    int i, j;

    //elemen matriks pertama
    printf("\n\t\t\t+-----------------------------------------+");
    printf("\n\t\t\t|              Matriks Pertama            |");
    printf("\n\t\t\t+-----------------------------------------+");
    printf("\n\t\t\tMasukkan jumlah baris matriks pertama : ");
    barisKolom[0][0] = validasi();
    printf("\n\t\t\tMasukkan jumlah kolom matriks pertama : ");
    barisKolom[0][1] = validasi();

    printf("\n\t\t\tMasukan elemen Matriks pertama\n");
    for(i= 0; i < barisKolom[0][0]; i++){
        for(j = 0; j < barisKolom[0][1]; j++){
            printf("\t\t\t\tElemen baris [%d] kolom [%d] : ", i+1, j+1);
            matriksA[i][j] = validasi();
        }
    }

    if(pilihan == 1 || pilihan == 2)
    {
        //elemen matriks kedua
        printf("\n\t\t\t+-----------------------------------------+");
        printf("\n\t\t\t|                Matriks Kedua            |");
        printf("\n\t\t\t+-----------------------------------------+");
        do{
            //jumlah baris harus sama dengan matriks pertama
            printf("\n\n\t\t\tMasukkan jumlah baris matriks kedua : ");
            barisKolom[1][0] = validasi();
            if(barisKolom[0][0] == barisKolom[1][0])
                break;
            else
                printf("\t\t\tJumlah baris harus sama dengan matriks pertama\n\n");
        }while(1);

        //jumlah kolom pada penjumlahan matriks harus sama
        if(pilihan == 1)
        {
            do{
                printf("\n\t\t\tMasukkan jumlah kolom matriks kedua : ");
                barisKolom[1][1] = validasi();
                if(barisKolom[0][1] == barisKolom[1][1])
                    break;
                else
                    printf("\t\t\tJumlah kolom harus sama dengan matriks pertama\n\n");
            }while(1);
        }
        //pada perkalian jumlah kolom tidak harus sama
        else if(pilihan == 2)
        {
            printf("\n\t\t\tMasukkan jumlah kolom matriks kedua : ");
            barisKolom[1][1] = validasi();
        }

        printf("\n\t\t\tMasukan elemen Matriks kedua\n");
        for(i= 0; i < barisKolom[1][0]; i++){
            for(j = 0; j < barisKolom[1][1]; j++){
                printf("\t\t\t\tElemen baris [%d] kolom [%d] : ", i+1, j+1);
                matriksB[i][j] = validasi();
            }
        }
    }
}

//penjumlahan matriks
void penjumlahan()
{
    int i,j;

    for (i=0; i<barisKolom[0][0]; i++){
        for (j=0; j<barisKolom[0][1]; j++){
            matriksC[i][j]= matriksA[i][j] + matriksB[i][j];
        }
    }
}

//perkalian matriks
void perkalian()
{
    int i,j,k;
    int sum = 0;

    for (i=0; i<barisKolom[0][0]; i++){
        for (j=0; j<barisKolom[1][1]; j++){
            for (k=0; k<barisKolom[1][0]; k++){
                sum += matriksA[i][k] * matriksB[k][j];
            }
            matriksC[i][j] = sum;
            sum = 0;
        }
    }
}

//transpose matriks
void transpose(int matriks[10][10], int baris, int kolom)
{
    int i,j;
    int matriks_transpose[10][10];

	for (i=0; i<kolom; i++)
 	{
  		for(j=0; j<baris; j++)
  		{
   			matriks_transpose[i][j]=matriks[j][i];
  		}
 	}

	printf("\t\t\t\t\tMatriks\n");
 	for(i=0; i<baris; i++)
 	{
  		printf("\t\t\t\t\t");
		for(j=0;j<kolom;j++)
  		{
   			printf("%3d",matriks[i][j]);
  		}
  		printf("\n");
 	}

    printf("\t\t\t\t\tmatriks transpose\n");
    for(i=0;i<kolom;i++)
    {
        printf("\t\t\t\t\t");
		for(j=0;j<baris;j++)
        {
            printf("%d ", matriks_transpose[i][j]);
        }
        printf("\n");
    }
}

//mencetak matriks
void printMatriks(int matriks[10][10], int baris, int kolom)
{
    int i,j;

    for(i=0; i<baris; i++){
        printf("\t\t\t\t\t| ");
        for(j=0; j<kolom; j++){
            printf("\t\t\t\t\%d ", matriks[i][j]);
        }
         printf("|\n");
    }
    printf("\n");
}

//pilihan aksi setelah menjalankan program
void reinput()
{
    int pilihanTindakan;

    printf("\n\n\t\t\tApakah Anda ingin melakukan operasi ulang?");
    printf("\n\t\t\t1. Ya");
    printf("\n\t\t\t2. Tidak");
    printf("\n\t\t\tMasukkan nomor pilihan Anda : ");
    pilihanTindakan = validasi();

    if(pilihanTindakan == 1){
        main();
    }
    else if(pilihanTindakan == 2){
        printf("terima kasih");
        exit(0);
    }
    else{
        printf("Masukkan angka dari 1-3!");
        reinput();
    }
}


int main()
{
    system("COLOR 70");
    system("cls");
    int pilihan;

    //pilihan operasi matriks
    printf("\t\t\t\t\t+---------------------------------------+\n");
    printf("\t\t\t\t\t+             KELOMPOK 23 ALPROG        +\n");
    printf("\t\t\t\t\t|              PILIHAN OPERASI          |\n");
    printf("\t\t\t\t\t+---------------------------------------|\n");
    printf("\t\t\t\t\t|    [1] Penjumlahan                    |\n");
    printf("\t\t\t\t\t|    [2] Perkalian                      |\n");
    printf("\t\t\t\t\t|    [3] Transpose                      |\n");
    printf("\t\t\t\t\t|    [4] Exit                           |\n");
    printf("\t\t\t\t\t+---------------------------------------+\n\n");

    printf("\t\t\t\t\tMasukkan nomor urut dari pilihan anda : ");
    pilihan = validasi();

    if(pilihan==1){
        //penjumlahan
        system("cls");
        printf("\t\t\t+-----------------------------------------+\n");
        printf("\t\t\t|         Operasi Penjumlahan Matriks     |\n");
        printf("\t\t\t+-----------------------------------------+\n");

        inputAngkaMatriks(1);
        penjumlahan();

        printf("\n\t\t\tMatirks A :\n");
        printMatriks(matriksA, barisKolom[0][0], barisKolom[0][1]);
        printf("\n\t\t\tMatirks B :\n");
        printMatriks(matriksB, barisKolom[1][0], barisKolom[1][1]);
        printf("\n\t\t\tHasil Penjumlahan :\n");
        printMatriks(matriksC, barisKolom[0][0], barisKolom[0][1]);

        reinput();
    }
    else if(pilihan==2){
        //perkalian
        system("cls");

        inputAngkaMatriks(2);
        perkalian();

        printf("\n\t\t\tMatirks A :\n");
        printMatriks(matriksA, barisKolom[0][0], barisKolom[0][1]);
        printf("\n\t\t\tMatirks B :\n");
        printMatriks(matriksB, barisKolom[1][0], barisKolom[1][1]);
        printf("\n\t\t\tHasil Perkalian :\n");
        printMatriks(matriksC, barisKolom[0][0], barisKolom[0][1]);

        reinput();
    }
    else if(pilihan==3){
        //transpose
        system("cls");

        inputAngkaMatriks(3);

        printf("\n\t\t\tMatirks A :\n");
        transpose(matriksA, barisKolom[0][0], barisKolom[0][1]);

        reinput();
    }
    else if(pilihan==4)
    {
        exit(0);
    }
    return(0);
}
