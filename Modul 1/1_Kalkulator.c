#include <stdio.h>
#include <stdlib.h>

/*Program Kalkulator*/

int validInteger(int *var);
void reVldInteger(int *var, char *nama);
float validFloat(float *var);
void reVldFloat(float *var, char *nama);
void rangeVldInt(int *var, int range1, int range2, char *nama);
void pilihanSubProgram(int pilihanOperator);

int main(){
    int pilihanOperator;
    int inputUlang;

    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 1------------");
    printf("\n\t\t\t-------------------KELOMPOK 23-------------------");
    printf("\n\t\t\t\t================================");
    printf("\n\t\t\t\tProgram 1.1 Kalkulator Sederhana");
    printf("\n\t\t\t\t================================\n\n");

    printf("\t\t\tPilihan Menu Operasi: \n");
    printf("\t\t\t1. Pertambahan (+)  \t|| kode = 1\n");
    printf("\t\t\t2. Pengurangan (-)  \t|| kode = 2\n");
    printf("\t\t\t3. Perkalian (x)    \t|| kode = 3\n");
    printf("\t\t\t4. Pembagian (/)    \t|| kode = 4\n");
    printf("\t\t\t5. Modulus (%%)      \t|| kode = 5\n");
    printf("\t\t\t6. KELUAR           \t|| kode = 6\n\n");
    reVldInteger(&pilihanOperator, "Masukkan Pilihan Menu: ");

    switch(pilihanOperator){
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
            pilihanSubProgram(pilihanOperator);
            break;
       case 6:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
       default:
            printf("\n\t\t\tMaaf Pilihan Operasi Tidak Tersedia\n\n");
            rangeVldInt(&inputUlang,0,1,"\t\t\tIngin Input Ulang? \t [ 1(iya) / 0(tidak) ] : ");
            if(inputUlang == 1){
                main();
            }else{
                printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            }
            break;
    }
    return 0;
}

//validasi menerima input int
int validInteger(int *var){
    char buff[1024];
    char cekChar;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &cekChar) == 1) {
            return 1;
        }
    }
    return 0;
}

//validasi ulang int
void reVldInteger(int *var, char *inputString){
    while(1){
        printf("%s", inputString);
        fflush(stdin);
        if(validInteger(var)){
            break;
        }
        printf("\t\t\t Input salah! Hanya Masukkan Angka.\n");
    }
}

//validasi menerima input float
float validFloat(float *var){
    char buff[1024];
    char cekChar;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%f %c", var, &cekChar) == 1) {
            return 1;
        }
    }
    return 0;
}

//validasi ulang float
void reVldFloat(float *var, char *inputString){
    while(1){
        printf("%s",inputString);
        fflush(stdin);
        if(validFloat(var)){
            break;
        }
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}

//range input integer
void rangeVldInt(int *var, int range1, int range2, char *nama){
    while(1){
        reVldInteger(var, nama);
        fflush(stdin);
        if(*var >= range1  && *var <= range2)
            break;
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}

void pilihanSubProgram(int pilihanOperator){
    float hasil;
    float bil_1, bil_2;
    int inputUlang;

    system ("cls");
    if(pilihanOperator == 1){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t|	     OPERASI PERTAMBAHAN 	        |\n");
        printf("\n\t\t\t|===============================================|\n");

        reVldFloat(&bil_1, "\n\t\t\tMasukkan Bilangan Pertama: ");
        reVldFloat(&bil_2, "\t\t\tMasukkan Bilangan Kedua: ");
        hasil = bil_1 + bil_2;
    }else if(pilihanOperator == 2){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t|	     OPERASI PENGURANGAN 	        |\n");
        printf("\n\t\t\t|===============================================|\n");

        reVldFloat(&bil_1, "\n\t\t\tMasukkan Bilangan Pertama: ");
        reVldFloat(&bil_2, "\t\t\tMasukkan Bilangan Kedua: ");
        hasil = bil_1 - bil_2;
    }else if(pilihanOperator == 3){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t|	        OPERASI PERKALIAN    	        |\n");
        printf("\n\t\t\t|===============================================|\n");

        reVldFloat(&bil_1, "\n\t\t\tMasukkan Bilangan Pertama: ");
        reVldFloat(&bil_2, "\t\t\tMasukkan Bilangan Kedua: ");
        hasil = bil_1 * bil_2;
    }else if(pilihanOperator == 4){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t|	        OPERASI PEMBAGIAN 	        |\n");
        printf("\n\t\t\t|===============================================|\n");

        reVldFloat(&bil_1, "\n\t\t\tMasukkan Bilangan Pertama: ");
        reVldFloat(&bil_2, "\t\t\tMasukkan Bilangan Kedua: ");
        hasil = bil_1 / bil_2;
    }else if(pilihanOperator == 5){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t|	        OPERASI MODULUS 	        |\n");
        printf("\n\t\t\t|===============================================|\n");

        reVldFloat(&bil_1, "\n\t\t\tMasukkan Bilangan Pertama: ");
        reVldFloat(&bil_2, "\t\t\tMasukkan Bilangan Kedua: ");
        hasil = fmod(bil_1,bil_2);
    }

    printf("\n\t\t\t\t\t  Hasil = %.2f\n", hasil);
    printf("\t\t\t\t  ==========================\n");

    rangeVldInt(&inputUlang,0,1,"\n\t\t\tIngin Menghitung Lagi \t [ 1(iya) / 0(tidak) ] : ");
    if (inputUlang == 1){
        pilihanSubProgram(pilihanOperator);
    }else{
        main();
    }
}
