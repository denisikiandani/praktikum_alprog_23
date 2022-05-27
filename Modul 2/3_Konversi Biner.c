#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

void judul();
void reset();
int input();
int input_biner();
int desimalKeBiner();
int binerKeDesimal();
int angka, hasil, pilihan, biner, desimal, sisabagi, hasilbagi;

int main(){
    system("COLOR 70");
	judul();
	printf("\n\n\t\t\t\t\tJenis Konversi :\n\n\t\t\t\t\t1. Desimal ke Biner\n\n\t\t\t\t\t2. Biner ke Desimal\n");
	printf("\n\n\t\t\t\t\tMasukkan Pilihan : ");
	scanf("%d", &pilihan);
	if (pilihan == 1){
		system("cls");
		judul();
		printf("\n\n\t\t\t\t\t1. Desimal ke Biner");
		printf("\n\n\t\t\t\t\tMasukkan Angka : ");
		desimal = input();
		hasil = desimalKeBiner(angka);
	}else if (pilihan == 2){
		system("cls");
		judul();
		printf("\n\n\t\t\t\t\t2. Biner ke Desimal");
		printf("\n\n\t\t\t\t\tMasukkan Angka Biner   : ");
		biner = input_biner();
		hasil = binerKeDesimal(angka);
	}else {
		printf("\n\n\t\t\t\t\tInvalid Input");
		sleep(2);
		system("cls");
		main();
	}
	printf("\n\n\t\t\t\t\tHasil Konversi\t : %d\n\n", hasil);
	reset();
	return 0;
}

//Fungsi untuk menampilkan judul
void judul(){
	printf("\n\t\t\t\t\t   PRATIKUM ALPROG MODUL 2 NO. 3  ");
	printf("\n\t\t\t\t\t	     KELOMPOK 23			  ");
	printf("\n\t\t\t\t\t+================================+");
    printf("\n\t\t\t\t\t|        Program Konversi        |");
    printf("\n\t\t\t\t\t|       Biner dan  Desimal       |");
    printf("\n\t\t\t\t\t+================================+");
}

//Meminta input untuk mengulangi program
void reset(){
	int ulang;
	printf("\n\t\t\t\t\tIngin Mengulangi? [y / n]  ");
	ulang = getch();
	if (ulang == 'y'|| ulang == 'Y'){
		system("cls");
		main();
	}else if (ulang == 'n' || ulang == 'N'){
		system ("cls");
		return;
	}else {
		system("cls");
		judul();
		printf ("\n\t\t\t\t\tInvalid Input\n");
		reset();
	}
}

//Fungsi untuk meminta input hanya angka
int input(){
    char ch;
    char * data;
    int cek = 0;
    data = (char *) malloc(sizeof(char));

    while ((ch = getch()) != 13){
        if ((ch >= '0' && ch <= '9')){
            printf("%c", ch);
            data[cek] = ch;
            cek++;
        }
    }
    data[cek] = '\0';
    return atoi(data);
}

//Fungsi untuk meminta input hanya angka 1 dan 0
int input_biner(){
    char ch;
    char * data;
    int cek = 0;
    data = (char *) malloc(sizeof(char));

    while ((ch = getch()) != 13){
        if (ch == '0' || ch == '1'){
            printf("%c", ch);
            data[cek] = ch;
            cek++;
        }
    }
    data[cek] = '\0';
    return atoi(data);
}

//Menghitung konversi dari desimal ke biner
int desimalKeBiner(int angka){
	int biner = 0;
	int bobot = 1;
	angka = desimal;
	if (angka != 0 && angka != 1){
		while (desimal != 0){
			sisabagi = desimal % 2;
			biner = biner + sisabagi * bobot;
			desimal = desimal / 2;
			bobot = bobot * 10;
		}
	}else {
		biner = angka;
	}
	return biner;
}

//Menghitung konversi dari biner ke desimal
int binerKeDesimal(int angka){
	int desimal = 0;
	int bobot = 1;
	angka = biner;
	while (biner != 0){
		sisabagi = biner % 10;
		desimal = desimal + sisabagi * bobot;
		biner = biner / 10;
		bobot = bobot * 2;
	}
	return desimal;
}
