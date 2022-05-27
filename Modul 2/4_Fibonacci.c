#include <stdio.h>
#include <stdlib.h>

int validInteger(int *var);
void reVldInteger(int *var, char *nama);
float validFloat(float *var);
void reVldFloat(float *var, char *nama);
void rangeVldInt(int *var, int range1, int range2, char *nama);
void menu();
int fiboRekursif(int bilangan);
void deretFiboRekursif(int jumlah_deret);
void deretFiboIteratif(int jumlah_deret);
void printFibonacci(int pilihanMenu);

int main(){
    system("COLOR 70");
    int inputUlang;
    int pilihanMenu, jumlah_deret;

    menu();
    reVldInteger(&pilihanMenu, "Masukkan Pilihan Menu: ");
    switch (pilihanMenu){
        case 1:
        case 2:
            printFibonacci(pilihanMenu);
            break;
        case 3:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
        default:
            printf("\n\t\t\tMaaf Pilihan Menu Tidak Tersedia\n\n");
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

int validInteger(int *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}

//validasi ulang int
void reVldInteger(int *var, char *nama){
    while(1){
        printf("%s", nama);
        fflush(stdin);
        if(validInteger(var))
            break;
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

void menu(){
    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 2-------------");
    printf("\n\t\t\t-------------------KELOMPOK 23-------------------");
    printf("\n\t\t\t\t================================");
    printf("\n\t\t\t\tProgram 2.4 menampilkan deret fibonacci");
    printf("\n\t\t\t\tdengan metode rekursif dan iteratif") ;
    printf("\n\t\t\t+===============================================+");
    printf("\n\t\t\t| Menu Program : \t\t\t\t|");
    printf("\n\t\t\t| [1] Fibonacci Rekursif\t\t\t|");
    printf("\n\t\t\t| [2] Fibonacci Iteratif\t\t\t|");
    printf("\n\t\t\t| [3] KELUAR Program\t\t\t\t|");
    printf("\n\t\t\t+===============================================+\n");
}

int fiboRekursif(int bilangan){
    if (bilangan == 0 || bilangan == 1){
        return bilangan;
    }
    return fiboRekursif(bilangan - 2) + fiboRekursif(bilangan - 1);
}

void deretFiboRekursif(int jumlah_deret){
    printf("\t\t\t");
    for (int i = 0; i < jumlah_deret; i++){
        printf("%d ", fiboRekursif(i));
    }
    printf("\n");
}

void deretFiboIteratif(int jumlah_deret){
    int bilangan1 = 0, bilangan2 = 1;
    int bil_sekarang;
    printf("\t\t\t");
    for (int i = 0; i < jumlah_deret; i++){
        if (i == 0 || i == 1){
            printf("%d ", i);
        }else{
            bil_sekarang = bilangan1 + bilangan2;
            bilangan1 = bilangan2;
            bilangan2 = bil_sekarang;

            printf("%d ", bil_sekarang);
        }
    }
    printf("\n");
}

void printFibonacci(int pilihanMenu){
    int jumlah_deret;
    int inputUlang;

    system("cls");
    if(pilihanMenu == 1){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t        Program Deret Fibonacci Rekursif 	        \n");
        printf("\n\t\t\t|===============================================|\n");
        reVldInteger(&jumlah_deret, "\t\t\tMasukkan Jumlah Deret: ");
        printf("\n");
        deretFiboRekursif(jumlah_deret);
    }else if(pilihanMenu == 2){
        printf("\n\t\t\t|===============================================|\n");
        printf("\n\t\t\t        Program Deret Fibonacci Iteratif 	        \n");
        printf("\n\t\t\t|===============================================|\n");
        reVldInteger(&jumlah_deret, "\t\t\tMasukkan Jumlah Deret: ");
        printf("\n");
        deretFiboIteratif(jumlah_deret);
    }

    printf("\n\t\t\t1. Ulang Input Deret");
    printf("\n\t\t\t2. Menu Utama");
    printf("\n\t\t\t3. Akhiri Program");
    printf("\n\t\t\t==================================\n");
    rangeVldInt(&inputUlang, 1,3, "\n\n\t\t\t Pilih : ");

    switch (inputUlang){
        case 1:
            printFibonacci(pilihanMenu);
            break;
        case 2:
            main();
            break;
        case 3:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
    }
}
