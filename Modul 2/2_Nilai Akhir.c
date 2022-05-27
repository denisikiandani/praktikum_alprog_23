#include <stdio.h>		//menjalankan fungsi basic bahasa c
#include <unistd.h>		//menjalankan fungsi sleep()
#include <conio.h>		//menjalankan fungsi getch()
#include <stdlib.h>		//menjalankan fungsi system()

void judul();
void invalid();
void reset();
float input();
float angka;

int main(){
    system("COLOR 70");
    float kehadiran, nilai_tugas1, nilai_tugas2, nilai_tugas3;
	float nilai_quiz, nilai_uts, nilai_uas, total;
	float n_rataan_tugas, n_rataan_quiz, n_rataan_uts, n_rataan_uas;
	char nilai_huruf[3];
	int ulangi;

    //Mengecek jumlah kehadiran
    do{
        judul();
        printf("\n\n\t\t\t\t\tMasukkan Jumlah Kehadiran : ");
        kehadiran = input();
        if ((kehadiran > 15 || (kehadiran < 0))){
            printf("\n\n\t\t\t\t\tJumlah Kehadiran Tidak Sesuai");
            printf("\n\t\t\t\t\tMohon Input Angka 0-15\n");
            sleep(3);
            system("cls");
            ulangi =1 ;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);


    //Menginput nilai tugas 1
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai Tugas 1 : ");
        nilai_tugas1 = input();
        if (nilai_tugas1 < 0 || nilai_tugas1 > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);


    //Menginput nilai tugas 2
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai Tugas 2 : ");
        nilai_tugas2 = input();
        if (nilai_tugas2 < 0 || nilai_tugas2 > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);


    //Menginput nilai tugas 3
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai Tugas 3 : ");
        nilai_tugas3 = input();
        if (nilai_tugas3 < 0 || nilai_tugas3 > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);

	//Input nilai quiz
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai Quiz : ");
        nilai_quiz = input();
        if (nilai_quiz < 0 || nilai_quiz > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);

    //Menginput nilai UTS
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai UTS : ");
        nilai_uts = input();
        if (nilai_uts < 0 || nilai_uts > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);


    //Menginput nilai UAS
    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai UAS : ");
        nilai_uas = input();
        if (nilai_uas < 0 || nilai_uas > 100){
            invalid();
            ulangi = 1;
        }else {
            ulangi = 0;
        }
    }while (ulangi == 1);

    //Menghitung bobot nilai kehadiran
    kehadiran = kehadiran / 3;
    //Menghitung bobot nilai tugas
    n_rataan_tugas = (nilai_tugas1+nilai_tugas2+nilai_tugas3) / 3 * 0.2;
    //Menghitung bobot nilai quiz
    n_rataan_quiz = nilai_quiz * 0.15;
    //Menghitung bobot nilai UTS
    n_rataan_uts = nilai_uts * 0.3;
    //Menghitung bobot nilai UAS
    n_rataan_uas = nilai_uas * 0.3;
    //Menghitung total nilai
    total = kehadiran + n_rataan_tugas + n_rataan_quiz + n_rataan_uts + n_rataan_uas;

    if (total >= 0 && total <45){
        strcpy(nilai_huruf, "E");
    }else if (total >= 45 && total < 50){
        strcpy(nilai_huruf, "D");
    }else if (total >= 50 && total < 55){
        strcpy(nilai_huruf, "D+");
    }else if (total >= 55 && total < 60){
        strcpy(nilai_huruf, "C");
    }else if (total >= 60 && total < 65){
        strcpy(nilai_huruf, "C+");
    }else if (total >= 65 && total < 75){
        strcpy(nilai_huruf, "B");
    }else if (total >= 75 && total < 80){
        strcpy(nilai_huruf, "B+");
    }else if (total >= 80 && total <= 100){
        strcpy(nilai_huruf, "A");
    }

    //Menampilkan nilai angka dan nilai huruf
    printf("\n\n\t\t\t\t\tNilai Akhir = %2.f", total);
	printf("\n\t\t\t\t\tNilai Huruf = %s", nilai_huruf);

	printf("\n\n\t\t\t\t\t	\>>> Terima Kasih <<<\n");
	reset();
	return 0;
}

//Fungsi untuk meminta input validasi hanya angka dan (.)
float input(){
    char ch;
    char * data;
    int cek = 0;
    data = (char *) malloc(sizeof(char));

    while ((ch = getch()) != 13){
        if ((ch >= '0' && ch <= '9')|| (ch == '.')){
            printf("%c", ch);
            data[cek] = ch;
            cek++;
        }
    }
    data[cek] = '\0';
    return atof(data);
}

//Untuk menampilkan judul
void judul(){
	printf("\n\t\t\t\t\t   PRATIKUM ALPROG MODUL 2 NO. 2   ");
	printf("\n\t\t\t\t\t	     KELOMPOK 23			   ");
    printf("\n\t\t\t\t\t===================================");
    printf("\n\t\t\t\t\t|      Program Nilai Akhir        |");
    printf("\n\t\t\t\t\t===================================");
}

//Untuk menampilkan invalid input
void invalid(){
	printf("\n\n\t\t\t\t\tInvalid Input");
	printf("\n\t\t\t\t\tMohon Input Angka 0-100\n");
	sleep(3);
	system("cls");
}

//Meminta input untuk mengulangi program
void reset(){
	int ulang;
	printf("\n\t\t\t\t\tIngin Mengulangi? [y / n]  ");
	ulang = getch();
	if (ulang == 'y'|| ulang == 'Y'){
		system("cls");
		main();
	}else if (ulang == 'n'|| ulang == 'N'){
		system ("cls");
		return;
	}else {
		system("cls");
		judul();
		printf ("\n\n\t\t\t\t\tInvalid Input\n");
		reset();
	}
}
