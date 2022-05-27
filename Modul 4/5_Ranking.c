 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void judul();
void inputData();
void sortingData();
int clean();
struct mahasiswa {
char nama[100];
int nilai;
};

int main(){
    system("COLOR 70");
    void judul();
    char ch, cek;
	void judul();
    printf("\n\t\t\t\t\t PRATIKUM ALPROG MODUL 4 NO. 5 ");
	printf("\n\t\t\t\t\t	  KELOMPOK 23			   ");
    printf("\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t|    PROGRAM RANKING NILAI    |");
    printf("\n\t\t\t\t\t-------------------------------");
    printf("\n\t\t\t\t\t| 1. Input Data               |");
    printf("\n\t\t\t\t\t| 2. Ranking Data             |");
    printf("\n\t\t\t\t\t| 3. Tutup Program            |");
    printf("\n\t\t\t\t\t-------------------------------\n");

do{
    printf("\n\t\t\t\t\tMasukkan pilihan: ");
    if(((scanf(" %c%c", &ch, &cek)) != 2 || cek !='\n') && clean())
    {
    printf("\n\t\t\t\t\tInputan salah! Mohon hanya memasukkan angka dari 1 hingga 3\n\n");
    }
    else{

        if(ch == '1'){
        inputData();
        break;

        }
        if(ch == '2'){
        sortingData();
        break;

        }
        else if(ch == '3'){
        system ("cls");
		exit(0);
        break;

        }
        else{
        printf("\n\t\t\t\t\tInputan salah! Masukkan angka dari 1 sampai 3\n\n");

        }
    }
}while(1);
system ("cls");
return 0;
}


void inputData(){
    char pilih, cek;
    struct mahasiswa dataMahasiswa;
    FILE *file;
    printf("\n\n\t\t\t\t\tMasukkan Nama : ");
    scanf(" %[^\n]s", &dataMahasiswa.nama);
    void judul();

    do{
        printf("\n\n\t\t\t\t\tMasukkan Nilai: ");

        if(((scanf("%d%c", &dataMahasiswa.nilai, &cek))!= 2 || cek != '\n') && clean()){
        printf("Inputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
        }

        else{
            if(dataMahasiswa.nilai < 0){
            printf("Inputan salah! Mohon hanya memasukkan angka mulai dari 0\n\n");
            }

            else{
            break;
            }
        }
    }while(1);

    file = fopen("asistenin.txt","a");
    fprintf(file,"%s\n%d\n", dataMahasiswa.nama,dataMahasiswa.nilai);
    fclose(file);
    printf("\nData berhasil disimpan\n");
    printf("\nApakah ingin menginputkan data lagi?\n Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

    do{
    printf("\nMasukkan pilihan: ");

    if(((scanf(" %c%c", &pilih, &cek)) != 2 || cek!= '\n') && clean()){
    printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.\n\n");
    }

    else{
        if(pilih == 'Y' || pilih == 'y'){
        inputData();
        break;
        }

        else if(pilih == 'N' || pilih == 'n'){
        main();
        break;
        }

        else if(pilih == 'T' || pilih == 't'){
        exit(0);
        break;
        }

        else{
        printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.\n\n");
        }
    }
}while(1);
}


void sortingData(){
    char pilih, cek, temp[100];
    int counter = 0, i, j, temp2;
    FILE *file;
    system("cls");
    file = fopen("asistenin.txt", "r");

    if(file != 0){
            while(fgets(temp, 100, file)) //proses memasukkan data ke variabel
                {
                counter++;
                fgets(temp, 100, file);
                }

        fclose(file);
        struct mahasiswa dataMahasiswa[counter];
        file = fopen("asistenin.txt", "r");

        for(i=0; i<counter; i++) //berfungsi untuk mengambil data nama dan nilai dari file asistenin
        {
            fgets(temp, 100, file);
            temp[strcspn(temp, "\n")] = '\0'; //strcspn berfungsi untuk mencari indeks dari karakter \n di tiap line
            strcpy(dataMahasiswa[i].nama, temp);
            fgets(temp, 100, file);
            temp[strcspn(temp, "\n")] = '\0';
            dataMahasiswa[i].nilai = atoi(temp); //atoi berfungsi untuk mengubah tipe data string menjadi int
        }

        fclose(file);
        for(i=0; i<counter-1; i++){
            for(j=0; j<counter-1-i; j++){
            if(dataMahasiswa[j].nilai < dataMahasiswa[j+1].nilai)
                {
                strcpy(temp,dataMahasiswa[j].nama);
                strcpy(dataMahasiswa[j].nama,dataMahasiswa[j+1].nama);
                strcpy(dataMahasiswa[j+1].nama,temp); //sorting nama

                temp2 = dataMahasiswa[j].nilai;
                dataMahasiswa[j].nilai = dataMahasiswa[j+1].nilai;
                dataMahasiswa[j+1].nilai = temp2; //sorting nilai
                }
            }
        }
        file = fopen("asistenout.txt", "w");
        fprintf(file, "Nilai Mata Kuliah Pemrograman Berorientasi Obyek\n");
        for(i=0; i<counter; i++){
        fprintf(file, "%d. %s %d\n", i+1,dataMahasiswa[i].nama, dataMahasiswa[i].nilai);
        }
        fclose(file);
        printf("Perankingan berhasil, silahkan cek file\n");
    }

    else{
        fclose(file);
        printf("Data belum tersedia, silakan masukkan data terlebih dahulu\n");
    }
    printf("\nApakah ingin mengulang perankingan?\nTekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.");

    do{
        printf("\nMasukkan pilihan: ");
        if(((scanf(" %c%c", &pilih, &cek)) != 2 || cek!= '\n') && clean()){
        printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.\n\n");
        }

        else{
            if(pilih == 'Y' || pilih == 'y'){
            sortingData();
            break;
            }

            else if(pilih == 'N' || pilih == 'n'){
            main();
            break;
            }

            else if(pilih == 'T' || pilih == 't'){
            exit(0);
            break;
            }

            else{
            printf("Inputan salah! Tekan Y untuk mengulang, N untuk kembali ke menu, dan T untuk menutup program.\n\n");
            }
        }
    }while(1);
}

int clean(){
    while(getchar() != '\n');
    return 1;
}

