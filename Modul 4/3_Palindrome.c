#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//deklarasi fungsi
void validasi (char kata[]);
void hitung(char kata[]);
void tampil(char kata[]);
int palindrom (char kata[], int size);
void ulang();
int clean();

//deklarasi variabel global
char kata[100];
typedef char cek[500];

//mendapatkan nilai input
int get_size(const char* file_name){
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size; //ukuran file
}

//program utama
int main(){
    system("COLOR 70");
    system("cls");
    int length, i, digit=0 , alphabet = 0, history = 0;
    cek temp;

    const char *inputKata = "";
    const char *cekKata = "";

    printf("\t\t\t\t===============================================\n");
    printf("\t\t\t\t==              PROGRAM PALINDROM            ==\n");
    printf("\t\t\t\t==                 KELOMPOK 23               ==\n");
    printf("\t\t\t\t===============================================\n");
    printf("Masukkan Kata\t : ");
    gets(kata);

    length = strlen(kata);
    //validasi kata hanya menerima alfabet
    for (i=0;i<length; i++){
        if (isdigit(kata[i]) != 0)
        digit++;
    }
    if(digit > 0){
        printf ("Masukkan kata yang benar!\n");
        printf ("ERROR: kata tidak boleh ada angka!\n");
        main();
    }
    fflush(stdin);

    //validasi kata kosong atau hanya 1
    if(length <= 1){
        printf ("Masukkan kata dengan benar!\n");
        printf("ERROR: kata yang dimasukan kosong atau hanya 1!\n");
        main();
    }
    fflush(stdin);

    //mengecek data dengan file
    FILE *out=fopen("kamuskata.txt","r");
    history = 0;
    if(!out){
        printf("\nDATA BELUM ADA\n");
    }
    else{
        if(get_size("kamuskata.txt") == 0){
            history = 0;
        }
        else{
            while(!feof(out)){
                fflush(stdin);
                fscanf(out,"%s, %s\n", &temp);
                const char *inputKata = kata;
                const char *cekKata = temp;
                if(strcmp(inputKata, cekKata)==0){
                    history = history + 1;
                }
            }
        }
        fclose(out);
    }
    if(history > 0){
        printf("\nDATA SUDAH ADA\nSilakan masukkan kata lain.\n");
        history = 0;
        system("pause");
        main();
    }
    else{
        printf("\nDATA BERHASIL DIMASUKKAN\n");
        FILE *in=fopen("kamuskata.txt","a");
        const char *inputKata = kata;
        fprintf(in,"%s\n",kata);
        fclose(in);
        hitung (kata);
    }

    return 0;
}

//fungsi untuk menghitung jumlah kata dan karakter
void hitung(char kata[]){
    int i,j, jumlahKarakter, temp, counter=0;

    FILE * file;
    file = fopen("kamuskata.txt", "a");
    jumlahKarakter = strlen(kata);
    fprintf(file, "%s(%d)\t : ", kata, jumlahKarakter);

    for(i=0; i<strlen(kata); i++){
        temp = 0;
        for(j=i-1; j>=0; j--){
            if(tolower(kata[j]) == tolower(kata[i])){
                temp++;
            }
        }
        if(temp == 0){
            counter++;
        }
        else{
            continue;
        }
    }

    char huruf[counter];
    int jumlahHuruf[counter];

    printf("%s(%d)\t : ", kata, jumlahKarakter);

    for(i=0; i<strlen(kata); i++){
        kata[i] = tolower(kata[i]);
    }

    for(i=0; i<strlen(kata); i++){
        counter = 0;
        temp = 0;

        for(j=i-1; j>=0; j--){
            if(kata[j] == kata[i]){
                temp++;
            }
        }

        if(temp == 0){
            for(j=i; j<strlen(kata); j++){
                if(kata[j] == kata[i]){
                    temp++;
                }
            }
            huruf[counter] = kata[i];
            jumlahHuruf[counter] = temp;
            printf("%c=%d ",huruf[counter], jumlahHuruf[counter]);
            fprintf(file, "%c=%d ", huruf[counter], jumlahHuruf[counter]);
            counter++;
        }
        else{
            continue;
        }
    }

    fclose(file);
    tampil(kata);

}

//fungsi untuk menampilkan hasil
void tampil(char kata[]){

    FILE *file;
    file = fopen("kamuskata.txt", "a");
    if(palindrom(kata, strlen(kata)) == 1){
        printf("\t : Palindrom");
        fprintf(file, "\t : Palindrom.\n");
    }
    else{
        printf("\t : Bukan Palindrom");
        fprintf(file, "\t : Bukan Palindrom.\n");
    }
    fclose(file);

    ulang();
}

//fungsi untuk menghitung palindrom
int palindrom(char kata[], int size){
    int i, status = 1;

    for(i=0; i<size; i++){
        if(kata[i] == kata[size-1-i]){
            continue;
        }
        else{
            status = 0;
            break;
        }
    }

    return status;
}

//fungsi untuk membersihkan buffer
int clean(){

    while(getchar() != '\n');

    return 1;
}

//fungsi untuk mengulang
void ulang(){
    char pilih, check;

    printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Menutup Program.");
    do{
        printf("\n(y/n): ");
        if(((scanf("%c%c", &pilih, &check)) != 2 || check != '\n') && clean()){
            printf("Inputan salah! Tekan Y untuk mengulang dan N untuk menutup program.\n");
        }
        else{
            if(pilih == 'Y' || pilih == 'y'){
                main();
                break;
            }
            else if(pilih == 'N' || pilih == 'n'){
                printf("\nTerimakasih, Sampai Jumpa!");
                exit(0);
                break;

            }
            else{
                printf("\nInputan salah! Tekan Y untuk mengulang dan N untuk menutup program.\n");
            }
        }
    }while(1);
}
