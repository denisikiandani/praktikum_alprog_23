#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int validasiINT(int *var);
void input_validasiINT(int *var, char *inputString);
void range_validasiINT(int *var, int range1, int range2, char *inputString);
void insertionSort(int arr[], int size_n);
void bubbleSort(int arr[], int size_n);
int pivot(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void menuSort();
void waktu_sort(int i);
void menuSearch();
double sequentialSearch(int angka[], int size, int angkaDicari);
double binarySearch(int angka[], int terkecil, int terbesar, int angkaDicari);
void waktu_search(int i);


int main(){
    system("COLOR 70");
    int inputUlang;
    int menu;

    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 3-------------");
    printf("\n\t\t\t-------------------KELOMPOK 23-------------------");
    printf("\n\t\t\t\t================================");
    printf("\n\t\t\t\tProgram 3.1 Menghitung Waktu Proses ");
    printf("\n\t\t\t\tAlgoritma Pencarian dan Pengurutan") ;
    printf("\n\t\t\t+===============================================+");
    printf("\n\t\t\t| Menu Program : \t\t\t\t|");
    printf("\n\t\t\t| [1] Sorting \t\t\t\t\t|");
    printf("\n\t\t\t| [2] Searching \t\t\t\t|");
    printf("\n\t\t\t| [3] KELUAR Program\t\t\t\t|");
    printf("\n\t\t\t+===============================================+\n");
    input_validasiINT(&menu, "\nPilihlah MENU: ");

    if(menu == 1){
        menuSort();
    }else if(menu == 2){
        menuSearch();
    }else if(menu == 3){
        printf("\n\t\t\t\t   Tekan ENTER untuk keluar!\n");
    }else{
        printf("\n\t\t\tMaaf Pilihan Operasi Tidak Tersedia\n\n");
        range_validasiINT(&inputUlang,0,1,"\t\t\tIngin Input Ulang? \t [ 1(iya) / 0(tidak) ] : ");
        if(inputUlang == 1){
            main();
        }else{
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
        }
    }

    return 0;
}

int validasiINT(int *var){
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

void input_validasiINT(int *var, char *inputString){
    while(1){
        printf("%s", inputString);
        if(validasiINT(var)){
            break;
        }
        printf("\t\t\t Input salah! Hanya Masukkan Angka.\n");
    }
}


void range_validasiINT(int *var, int range1, int range2, char *inputString){
    while(1){
        input_validasiINT(var, inputString);
        if(*var >= range1  && *var <= range2){
            break;
        }
        printf("\t\t\t Pilihan Menu Tidak Tersedia! Silahkan coba lagi.\n");
    }
}

void insertionSort(int arr[], int size_n){
    int i, bil_key, j;
    for(i = 1; i < size_n; i++) {
        bil_key = arr[i];
        j = i - 1;

        //pindahkan posisi elemen array 1 indeks di depan
        while(j >= 0 && arr[j] > bil_key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = bil_key;
    }
}

void bubbleSort(int arr[], int size_n){
    int i, j, temp_bil;

    for (i = 0; i < size_n - 1; i++){
        //perbandingan dua data dan untuk swap value
        for (j = 0; j < size_n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp_bil = arr[j];
                arr[j] = arr[j + 1];
                arr[i + 1] = temp_bil;
            }
        }
    }
}

//titik acuan untuk quick sort
int pivot(int arr[], int low, int high){
    int p = arr[high];
    int temp;
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++){
        if (arr[j] <= p){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

//metode quick sort
void quickSort(int arr[], int low, int high){
    int p = pivot(arr, low, high);

    if (low < high){
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void menuSort(){
    system("cls");

    int subMenuSort;
    printf("\n\t\t----------------SORTING---------------");
    printf("\n\t\t======================================");
    printf("\n\t\tJumlah Data:                          ");
    printf("\n\t\t           [1]. 1000 Data               ");
    printf("\n\t\t           [2]. 16000 Data              ");
    printf("\n\t\t           [3]. 64000 Data              ");
    printf("\n\t\t           [4]. KEMBALI                 ");
    printf("\n\t\t======================================");
    range_validasiINT(&subMenuSort,1,4,"\nMasukkan MENU Jumlah Data: ");

    switch(subMenuSort){
        case 1:
            waktu_sort(1000);
            break;
        case 2:
            waktu_sort(16000);
            break;
        case 3:
            waktu_sort(64000);
            break;
        case 4:
            main();
            break;
    }
}

void waktu_sort(int i){
    clock_t start, end;
    double waktu_sorting[3];
    int size;
    int inputUlang;
    int angka[i], temp[i];
    int subMenuScalling;
    size = i;
    srand((unsigned) time(NULL));

    do{
        system("cls");
        printf("\n\t\t----------------SCALLING---------------");
        printf("\n\t\t======================================");
        printf("\n\t\tRange Data:                          ");
        printf("\n\t\t           [1]. 0 - 100               ");
        printf("\n\t\t           [2]. 0 - 1000              ");
        printf("\n\t\t           [3]. LIMITLESS              ");
        printf("\n\t\t           [4]. KEMBALI                 ");
        printf("\n\t\t======================================");
        range_validasiINT(&subMenuScalling, 1, 4, "\nMasukkan Menu Scalling: ");
        system("cls");
        if(subMenuScalling == 1){
            for(i = 0; i < size; i++){
                angka[i] = rand() % 100 + 1;
                temp[i] = angka[i];
            }
        }else if(subMenuScalling == 2){
            for(i = 0; i < size; i++){
                angka[i] = rand() % 1000 + 1;
                temp[i] = angka[i];
            }
        }else if(subMenuScalling == 3){
            for(i = 0; i < size; i++){
                angka[i] = rand();
                temp[i] = angka[i];
            }
        }else{
            menuSort();
        }

        do{
            system("cls");
            start = clock();
            insertionSort(temp, size);
            end = clock();

            waktu_sorting[0] = (double)(end - start) / CLOCKS_PER_SEC;

            for(i=0; i<size; i++){
            //printf(" %d,", temp[i]);
                temp[i] = angka[i];
            }

            start = clock();
            bubbleSort(temp, size);
            end = clock();

            waktu_sorting[1] = (double)(end - start) / CLOCKS_PER_SEC;

            for(i=0; i<size; i++){
            //printf(" dan %d.", temp[i]);
                temp[i] = angka[i];
            }

            start = clock();
            quickSort(temp, 0, size-1);
            end = clock();

            waktu_sorting[2] = (double)(end - start) / CLOCKS_PER_SEC;

            for(i=0; i<size; i++){
            //printf(" dan %d.", temp[i]);
                temp[i] = angka[i];
            }

            printf("\n\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t\t\t    HASIL SORTING 	        \n");
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\n\t\t\tInsertion Sort     : %f s", waktu_sorting[0]);
            printf("\n\t\t\tBubble Sort        : %f s", waktu_sorting[1]);
            printf("\n\t\t\tQuick Sort         : %f s", waktu_sorting[2]);

            if(waktu_sorting[0] == waktu_sorting[1] && waktu_sorting[0] == waktu_sorting[2]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|            Kecepatannya Setara!           |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_sorting[0] == waktu_sorting[1]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|    Insertion dan Bubble Sort Setara!      |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_sorting[1] == waktu_sorting[2]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|     Insertion dan Quick Sort Setara!      |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_sorting[0] < waktu_sorting[1] && waktu_sorting[0] < waktu_sorting[2]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|      Insertion Sort Paling Cepat!         |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_sorting[1] < waktu_sorting[0] && waktu_sorting[1] < waktu_sorting[2]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|         Bubble Sort Paling Cepat!         |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_sorting[2] < waktu_sorting[0] && waktu_sorting[2] < waktu_sorting[1]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|          Quick Sort Paling Cepat!         |");
                printf("\n\t\t\t+-------------------------------------------+");
            }

            printf("\n\n\t\t\t1. Hitung Kembali");
            printf("\n\t\t\t2. KEMBALI");
            printf("\n\t\t\t3. MENU Sort");
            printf("\n\t\t\t4. MENU Utama");
            printf("\n\t\t\t5. KELUAR Program");
            printf("\n\t\t\t==================================\n");
            range_validasiINT(&inputUlang, 1,4, "\n\n\t\t\t Pilih : ");

            if(inputUlang == 3){
                menuSort();
            }else if(inputUlang == 4){
                main();
            }else if(inputUlang == 5){
                printf("\n\t\t\t\t   Tekan ENTER untuk keluar!\n");
                break;
            }
        }while(inputUlang == 1);
    }while(inputUlang == 2);
}

double sequentialSearch(int angka[], int size, int angkaDicari){
    clock_t waktu;
    double waktu_dibutuhkan;
    int i, counter=0;

    waktu = clock();
    for(i=0; i<size; i++){
        //printf(" dan %d.", angka[i]);
        if(angka[i] == angkaDicari){
            counter++;
        }
    }
    waktu = clock() - waktu;
    waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

    if(counter == 0){
        printf("Tidak Ada Angka Yang Sesuai!");
    }else{
        int indexAngkaDicari[counter];
        counter = 0;

        for(i=0; i<size; i++){
            if(angka[i] == angkaDicari){
                indexAngkaDicari[counter] = i;
                counter++;
            }
        }
        waktu = clock() - waktu;
        waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;
        printf("Angka Ditemukan Pada Index:");
        for(i=0; i<counter; i++){
            if(i == 0 && i == counter - 1 ){
                printf(" %d.", indexAngkaDicari[i]);
            }
            else{
                if(i == counter - 1 ){
                    printf(" dan %d.", indexAngkaDicari[i]);
                }
                else{
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }
    return waktu_dibutuhkan;
}


double binarySearch(int angka[], int terkecil, int terbesar, int angkaDicari){
    clock_t waktu;
    double waktu_dibutuhkan;
    int i, counter=0;

    waktu = clock();
    while(terkecil <= terbesar){
        int tengah = terkecil + (terbesar - terkecil) / 2;

        if(angka[tengah] == angkaDicari){
            counter++;
            for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
                counter++;
            }
            for(i = tengah - 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
                counter++;
            }
            break;
        }else if(angka[tengah] > angkaDicari){
            terbesar = tengah - 1;
        }else{
            terkecil = tengah + 1;
        }
    }

    if(counter == 0){
        printf("Tidak Ada Angka Yang Sesuai!");
    }else{
        int indexAngkaDicari[counter];
        counter = 0;

        while(terkecil <= terbesar){
            int tengah = terkecil + (terbesar - terkecil) / 2;

            if(angka[tengah] == angkaDicari){
                indexAngkaDicari[counter] = tengah;
                counter++;
                for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                for(i = tengah - 1; i > 0 && angka[i] == angkaDicari; i--){
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                break;
            }else if(angka[tengah] > angkaDicari){
                terbesar = tengah - 1;
            }else{
                terkecil = tengah + 1;
            }
        }

        printf("Angka Ditemukan Pada Index:");
        bubbleSort(indexAngkaDicari, counter);
        for(i=0; i<counter; i++){
            if(i == 0 && i == counter - 1 ){
                printf(" %d.", indexAngkaDicari[i]);
            }else{
                if(i == counter - 1 ){
                    printf(" dan %d.", indexAngkaDicari[i]);
                }else{
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }
    waktu = clock() - waktu;
    waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;
    return waktu_dibutuhkan;
}


void menuSearch(){
    system("cls");

    int subMenuSearch;
    printf("\n\t\t----------------SEARCHING---------------");
    printf("\n\t\t======================================");
    printf("\n\t\tJumlah Data:                          ");
    printf("\n\t\t           [1]. 1000 Data               ");
    printf("\n\t\t           [2]. 16000 Data              ");
    printf("\n\t\t           [3]. 64000 Data              ");
    printf("\n\t\t           [4]. KEMBALI                 ");
    printf("\n\t\t======================================");
    range_validasiINT(&subMenuSearch,1,4,"\nMasukkan MENU Jumlah Data: ");

    switch(subMenuSearch){
        case 1:
            waktu_search(1000);
            break;
        case 2:
            waktu_search(16000);
            break;
        case 3:
            waktu_search(64000);
            break;
        case 4:
            main();
            break;
    }
}

void waktu_search(int i){
    int angkaDicari;
    int angka[i], temp[i];
    int size = i;
    int inputUlang;
    int subMenuScalling;
    double waktu_searching[2];
    srand((unsigned) time(NULL));

    do{
        system("cls");
        printf("\n\t\t----------------SCALLING---------------");
        printf("\n\t\t======================================");
        printf("\n\t\tRange Data:                          ");
        printf("\n\t\t           [1]. 0 - 100               ");
        printf("\n\t\t           [2]. 0 - 1000              ");
        printf("\n\t\t           [3]. LIMITLESS              ");
        printf("\n\t\t           [4]. KEMBALI                 ");
        printf("\n\t\t======================================");
        range_validasiINT(&subMenuScalling, 1, 4, "\nMasukkan Menu Scalling: ");
        system("cls");
        if(subMenuScalling == 1){
            for(i = 0; i < size; i++){
                angka[i] = rand() % 100 + 1;
                temp[i] = angka[i];
            }
        }else if(subMenuScalling == 2){
            for(i = 0; i < size; i++){
                angka[i] = rand() % 1000 + 1;
                temp[i] = angka[i];
            }
        }else if(subMenuScalling == 3){
            for(i = 0; i < size; i++){
                angka[i] = rand();
                temp[i] = angka[i];
            }
        }else{
            menuSearch();
        }

        do{
            system("cls");
            fflush(stdin);
            quickSort(angka, 0, size-1);
            range_validasiINT(&angkaDicari,1,100000,"\n\t\t\tMasukan Angka Yang Dicari: ");

            system("cls");
            printf("\n\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t\t           HASIL SERACHING 	        \n");
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\tAngka Yang DICARI = %d", angkaDicari);

            printf("\n\n\t\t\t");
            waktu_searching[0] = sequentialSearch(angka, size, angkaDicari);
            printf("\n\t\t\tSequential Search   : %f s", waktu_searching[0]);

            printf("\n\n\t\t\t");
            waktu_searching[1] = binarySearch(angka, 0, size-1, angkaDicari);
            printf("\n\t\t\tBinary Search       : %f s", waktu_searching[1]);

            printf("\n\n\t\t\tWaktu Tercepat : ");

            if(waktu_searching[0] < waktu_searching[1]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|      Sequential Search Paling Cepat!      |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else if(waktu_searching[1] < waktu_searching[0]){
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|        Binary Search Paling Cepat!        |");
                printf("\n\t\t\t+-------------------------------------------+");
            }else{
                printf("\n");
                printf("\n\t\t\t+-------------------------------------------+");
                printf("\n\t\t\t|         TIDAK ADA DATA DITEMUKAN          |");
                printf("\n\t\t\t+-------------------------------------------+");
            }

            printf("\n\n\t\t\t1. Hitung Kembali");
            printf("\n\t\t\t2. KEMBALI");
            printf("\n\t\t\t3. MENU Search");
            printf("\n\t\t\t4. MENU Utama");
            printf("\n\t\t\t5. KELUAR Program");
            printf("\n\t\t\t==================================\n");
            range_validasiINT(&inputUlang, 1,4, "\n\n\t\t\t Pilih : ");

            if(inputUlang == 3){
                menuSearch();
            }else if(inputUlang == 4){
                main();
            }else if(inputUlang == 5){
                printf("\n\t\t\t\t   Tekan ENTER untuk keluar!\n");
                break;
            }
        }while(inputUlang == 1);
    }while(inputUlang == 2);
}
