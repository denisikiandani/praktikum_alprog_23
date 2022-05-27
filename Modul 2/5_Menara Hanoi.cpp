#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void Rekursif();
int towerRekursif(int cakram); 
void Iteratif();
int clean();

void urutanHanoi(int jumlahCakram,char dari, char bantu, char ke){
	
	if(jumlahCakram>0){
      urutanHanoi(jumlahCakram-1, dari, ke, bantu);
      printf("\t\t\t> Memindahkan cakram %d dari %c ke %c\n",jumlahCakram, dari, ke);
      urutanHanoi(jumlahCakram-1, bantu, dari, ke);
 	}
}

int welcome(){
      //deklarasi string 
      char x[]="\t\t\t\t==================================================\n";
      char y[]="\t\t\t\t==================================================\n";
      char z[]="\t\t\t\t||\t   Praktikum ALPROG MODUL 2 \t\t||\n";
      char o[]="\t\t\t\t||\t\t KELOMPOK 23 \t\t\t||\n";
      char p[]="\t\t\t\t||\t Soal Modul 2 No. 5 Praktikum ALPROG \t||\n";
      char q[]="\t\t\t\t||\t Dengan metode rekursif dan iteratif \t||\n";
      char r[]="\t\t\t\t==================================================\n";
      char s[]="\t\t\t\t==================================================\n";
      
	  //deklarasi variabel bertipe integer
      int a,b,i,n;
     
      //perulangan 10x untuk memunculkan string x sebanyak 10x
      for(i=0; i<10; i++){
            //clear screen
            system("cls");
            //perulangan untuk menimbulkan jeda waktu
            for(a=0; a<99999;a++){
                  for(b=0; b<999; b++){
                  }
            }
            //mencetak string x
            printf("%s",x);
            printf("%s",y);
            printf("%s",z);
            printf("%s",o);
            printf("%s",p);
            printf("%s",q);
            printf("%s",r);
            printf("%s",s);
            //perulangan untuk menimbulkan jeda waktu
            for(a=0; a<99999;a++){
                  for(b=0; b<999; b++){
                  }
            }
      }
}

int thanks(){
      //deklarasi string 
      char w[]="\n\n\n\n\n\n\n\n\n\n";
      char x[]="\t\t\t\t==================================================\n";
      char y[]="\t\t\t\t==================================================\n";
      char z[]="\t\t\t\t||\t   Anda Keluar Dari Program Ini \t||\n";
      char o[]="\t\t\t\t||\t Silahkan Kembali Bila Anda Perlu \t||\n";
      char p[]="\t\t\t\t||\t\t Terimakasih \t\t\t||\n";
      char r[]="\t\t\t\t==================================================\n";
      char s[]="\t\t\t\t==================================================\n";
      
	  //deklarasi variabel bertipe integer
      int a,b,i,n;
     
      //perulangan 10x untuk memunculkan string x sebanyak 10x
      for(i=0; i<10; i++){
            //clear screen
            system("cls");
            //perulangan untuk menimbulkan jeda waktu
            for(a=0; a<99999;a++){
                  for(b=0; b<999; b++){
                  }
            }
            //mencetak string x
            printf("%s",w);
            printf("%s",x);
            printf("%s",y);
            printf("%s",z);
            printf("%s",o);
            printf("%s",p);
            printf("%s",r);
            printf("%s",s);
            //perulangan untuk menimbulkan jeda waktu
            for(a=0; a<99999;a++){
                  for(b=0; b<999; b++){
                  }
            }
      }
}

int main(){
	system("COLOR 70");
	char pilih, Check; // variabel pilihan untuk menampung hasil pilihan menu oleh user. variabel enterCheck untuk validasi inputan
	system("cls"); // clear screen
	welcome();
	
    printf("\n\t\t\t Menu : ");
    printf("\n\n\t\t\t 1. Rekursif");
    printf("\n\t\t\t 2. Iteratif");
    printf("\n\t\t\t 3. Keluar");
	printf("\n\t\t\t=================================================");
	
	do{
		printf("\n\t\t\tTentukan pilihan Anda: ");
		if(((scanf(" %c%c", &pilih, &Check)) != 2 || Check != '\n') && clean()){ // meminta inputan pilihan menu dari user sekaligus divalidasi
			printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka dari 1 hingga 3\n\n"); // menampilkan error apabila inputan salah
		}
		else{
			if(pilih == '1'){ // apabila user memilih pilihan 1 (Rekursif)
				Rekursif(); // memanggil prosedur Rekursif
				break; // keluar dari perulangan
			}
			else if(pilih == '2'){ // apabila user memilih pilihan 2 (Iteratif) maka
				Iteratif(); // memanggil prosedur Iteratif
				break; // keluar dari perulangan
			}
			else if(pilih == '3'){ // apabila user memilih pilihan 3 (Tutup Program) maka 
				system("cls");
				thanks();
				break; // keluar dari perulangan
			}
			else{
				printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka dari 1 hingga 3\n\n"); // menampilkan error apabila inputan salah	
				
			}
		}
	}while(1);
	
	return 0; // menutup program
}

void Rekursif(){
	char dari,bantu,ke;
	char pilih, Check; // variabel pilih untuk menampung hasil pilihan menu oleh user. variabel Check untuk validasi inputan
	int jumlahCakram; // variabel jumlahCakram untuk menampung jumlah cakram dari tower hanoi
	   
	system("cls"); // clear screen
	
	do{
		printf("\n\t\t\tMasukkan jumlah cakram: ");
		if(((scanf("%d%c", &jumlahCakram, &Check)) != 2 || Check != '\n') && clean()){ // meminta inputan jumlah cakram dari user sekaligus divalidasi
			printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka lebih dari 0\n"); // menampilkan error apabila inputan salah
		}
		else{
			if(jumlahCakram <= 0){ // apabila jumlah cakram yang diinputkan lebih kecil dari 0 maka
				printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka lebih dari 0\n"); // menampilkan error apabila inputan salah
			}
			else{ // selain itu maka
				break; // keluar dari perulangan
			}
		}
	}while(1);
	
	urutanHanoi(jumlahCakram,'X','Y','Z');
	printf("\n\t\t\tLangkah terkecil untuk memindahkan  %d cakram yaitu: %d", jumlahCakram, towerRekursif(jumlahCakram)); // memanggil fungsi towerRekursif dan sekaligus menampilkan hasilnya
	printf("\n\t\t\t=======================================================");
	printf("\n\n\t\t\tApakah Anda ingin menghitung langkah terkecil tower hanoi ulang?\n\n\t\t\tTekan Y untuk mengulang,\n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program.");
	do{
		printf("\n\n\t\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilih, &Check)) != 2 || Check != '\n') && clean()){ // meminta inputan pilihan untuk mengulang program atau tidak sekaligus divalidasi
			printf("\n\t\t\tPilihan yang anda masukan salah! \n\n\t\t\tTekan Y untuk mengulang, \n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program."); // menampilkan error apabila inputan salah
		}
		else{
			if(pilih == 'Y' || pilih == 'y'){ // apabila ingin mengulang maka
				Rekursif(); // panggil lagi prosedur Rekursif
				break; // keluar dari perulangan
			}
			else if(pilih == 'N' || pilih == 'n'){ // apabila ingin kembali maka
				main(); // kembali lagi ke menu awal 
				break; // keluar dari perulangan
			}
			else if(pilih == 'K' || pilih == 'k'){ // apabila ingin menutup program maka
				thanks();
				break; // keluar dari perulangan
			}
			else{ // selain dari itu maka
				printf("\n\t\t\tPilihan yang anda masukan salah! \n\n\t\t\tTekan Y untuk mengulang, \n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program.");// menampilkan error apabila inputan salah
			}
		}
	}while(1);
}

int towerRekursif(int cakram){
	if(cakram == 1){ // apabila jumlah cakram sama dengan 1 maka
		return 1; // mengembalikan nilai 1
	}
	else{ // apabila tidak maka
		return 2 * towerRekursif(cakram - 1) +1; // mengembalikan nilai dari hasil perhitungan tersebut
	}
}

void Iteratif(){
	char dari,bantu,ke;
	char pilih, Check; // variabel pilih untuk menampung hasil pilihan menu oleh user. variabel Check untuk validasi inputan
	int jumlahCakram, i, temp=1;
	/* mendeklarasikan beberapa variabel dengan tipe data integer:
	   variabel jumlahCakram => untuk menampung jumlah cakram dari tower hanoi
	   variabel i => untuk menampung nilai iterasi pada perulangan for 
	   variabel temp => untuk menampung nilai langkah minimal yang diperlukan secara sementara dan diinisialisasi dengan nilai 1 */
	   
	system("cls"); // clear screen
	
	do{
		printf("\n\t\t\tMasukkan jumlah cakram: ");
		if(((scanf("%d%c", &jumlahCakram, &Check)) != 2 || Check != '\n') && clean()){ // meminta inputan jumlah cakram dari user sekaligus divalidasi
			printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka lebih dari 0\n"); // menampilkan error apabila inputan salah
		}
		else{
			if(jumlahCakram <= 0){ // apabila jumlah cakram yang diinputkan lebih kecil dari 0 maka
				printf("\n\t\t\tPilihan yang anda masukan salah! Mohon hanya memasukkan angka lebih dari 0\n"); // menampilkan error apabila inputan salah
			}
			else{ // selain itu maka
				break; // keluar dari perulangan
			}
		}
	}while(1);
	
	for(i=0; i<jumlahCakram; i++){ // melakukan perulangan sebanyak jumlah cakram
		temp = 2 * temp; // memperbaharui nilai variabel temp dengan nilai variabel temp sebelumnya dikali 2
		if(i == jumlahCakram - 1){ // apabila nilai iterasi sama dengan nilai jumlah cakram dikurangi 1 maka
			temp = temp - 1; // memperbaharui nilai variabel temp dengan nilai variabel temp sebelumnya dikurangi 1
		}
	}
	urutanHanoi(jumlahCakram,'X','Y','Z');
	printf("\n\t\t\tLangkah terkecil untuk memindahkan %d cakram yaitu: %d", jumlahCakram, temp); // tampilkan hasil
	printf("\n\t\t\t=======================================================");
    printf("\n\n\t\t\tApakah Anda ingin menghitung langkah minimum tower hanoi ulang?\n\n\t\t\tTekan Y untuk mengulang,\n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program.");
	do{
		printf("\n\n\t\t\tMasukkan pilihan: ");
		if(((scanf(" %c%c", &pilih, &Check)) != 2 || Check != '\n') && clean()){ // meminta inputan pilihan untuk mengulang program atau tidak sekaligus divalidasi
			printf("\n\t\t\tPilihan yang anda masukan salah! \n\n\t\t\tTekan Y untuk mengulang, \n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program."); // menampilkan error apabila inputan salah
		}
		else{
			if(pilih == 'Y' || pilih == 'y'){ // apabila ingin mengulang maka
				Iteratif(); // panggil lagi prosedur towerHanoiIteratif
				break; // keluar dari perulangan
			}
			else if(pilih == 'N' || pilih == 'n'){ // apabila ingin kembali maka
				main(); // kembali lagi ke menu awal 
				break; // keluar dari perulangan
			}
			else if(pilih == 'K' || pilih == 'k'){ // apabila ingin menutup program maka
				thanks();
				break; // keluar dari perulangan
			}
			else{ // selain dari itu maka
				printf("\n\t\t\tPilihan yang anda masukan salah! \n\n\t\t\tTekan Y untuk mengulang, \n\t\t\tN untuk kembali ke menu,\n\t\t\tK untuk menutup program.");// menampilkan error apabila inputan salah
			}
		}
	}while(1);
}

int clean(){
	while(getchar() != '\n'); // apabila saat validasi inputan dilakukan terdapat kesalahan inputan,
	// maka fungsi ini akan membersihkan kesalahan inputan tersebut agar variabel dapat menampung inputan yang baru
	return 1;
}

