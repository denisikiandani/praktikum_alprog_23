#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklarasi variabel global
typedef char biodata[500];
typedef struct{
    biodata Nama;
    biodata NIM;
}mahasiswa;

int jumlahAlphabet[256];
int jumlahHuruf;
int checkNumeric;
void input_mahasiswaData(mahasiswa mhs);
void cari_mahasiswaData(mahasiswa mhs);
int validasiInt(int *var);
int clearBuffer();

//main program
int main(){
    system("COLOR 70");
    system ("cls");
    mahasiswa mhs;
    char update;
    int pilihan;

	printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 4------------");
    printf("\n\t\t\t-------------------KELOMPOK 23------------------");
    printf("\n\t\t\t==============================================");
    printf("\n\t\t\t      Program 4.4 Program Data Mahasiswa      ");
    printf("\n\t\t\t==============================================\n");
    printf("\t\t\t=              1. Input Data                  =\n");
    printf("\t\t\t=              2. Cari Data                   =\n");
    printf("\t\t\t=              3. Tampilkan Data              =\n");
    printf("\t\t\t=              4. Keluar                      =\n");
    printf("\t\t\t===============================================\n");
    printf("\nMasukkan pilihan   : ");

    if(validasiInt(&pilihan) != 1){
        printf("\n\t\t\tInput salah! Input Harus Berapa Angka 1 sd 4.\nSilahkan coba lagi.\n");
        system("pause");
        main();
    }

    switch(pilihan){
        case 1:
            input_mahasiswaData(mhs);
            break;
        case 2:
            cari_mahasiswaData(mhs);
            break;
        case 3:
            print_mahasiswaData(mhs);
            break;
        case 4:
            printf("Tekan ENTER Untuk Keluar \n");
            exit(0);
            break;
        default:
            printf("Input Salah\n");
            system("pause");
            system("cls");
            main();
    }

    return 0;

}

//mendapatkan nilai input
int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

//fungsi untuk nenginput data mahasiswa
void input_mahasiswaData(mahasiswa mhs){
    system("cls");

    int alphabet = 0, length, digit = 0, history = 0, i;
    char pilih, check;
    char code;

    biodata noInduk, nama;

    //inisiasi data
    const char *dataNim = "";
    const char *dataInduk = "";
    const char *dataNama = "";

    printf("\t\t\t===============================================\n");
    printf("\t\t\t==          MENU INPUT DATA MAHASISWA        ==\n");
    printf("\t\t\t===============================================\n");
    printf("\nMasukan NIM Mahasiswa    : ");

    if (fgets(mhs.NIM,sizeof(mhs.NIM),stdin) != NULL){
        char *ptr = strchr(mhs.NIM, '\n');
        if (ptr)
        {
            *ptr  = '\0';
        }
    }


    length = strlen (mhs.NIM);

    // validasi NIM hanya angka
    for (i=0;i<length; i++) {
        //menghitung NIM
        if (isalpha(mhs.NIM[i]) != 0)
            alphabet++;
    }
    if(alphabet > 0) {
        printf ("Masukkan NIM yang benar!\n");
        printf ("ERROR: NIM Harus ANGKA bukan alphabet!\n");
        system("pause");
        input_mahasiswaData(mhs);
    }
    fflush(stdin);

    // validasi NIM minimal 1 karakter
    if(length <= 1) {
        printf ("Masukkan NIM dengan benar!\n");
        printf("ERROR: NIM yang dimasukan harus lebih dari 1 angka!\n");
        input_mahasiswaData(mhs);
    } else {
        // validasi NIM tidak boleh ada spasi
        if(strchr(mhs.NIM, ' ')) {
            printf ("Masukkan NIM yang benar!\n");
            printf ("ERROR: input NIM tidak boleh ada spasis\n");
            input_mahasiswaData(mhs);
        }

    }
    fflush(stdin);

    printf("Masukan Nama Mahasiswa   : ");
    gets(mhs.Nama);

    length = strlen(mhs.Nama);

    //menghitung nama
    for (i=0;i<length; i++) {
        if (isdigit(mhs.Nama[i]) != 0)
            digit++;
    }
    // validasi nama mahasiswa tidak menrima input angka
    if(digit > 0) {
        printf ("Masukkan Nama yang benar!\n");
        printf ("ERROR: Nama tidak boleh ada angka!\n");
        input_mahasiswaData(mhs);
    }
    fflush(stdin);

    // validasi Nama minimal 1 karakter
    if(length <= 1) {
        printf ("Masukkan Nama dengan benar!\n");
        printf("ERROR: Nama yang dimasukan kosong atau kurang dari 4 angka!\n");
        input_mahasiswaData(mhs);
    }
    fflush(stdin);
    printf("===============================================\n");

    //mengecek data pada file
    FILE *out=fopen("data.mahasiswa.txt","r");
    history = 0;
    if(!out){
        printf("\nDATA BELUM ADA\n");
    }else{
        if(get_size("data.mahasiswa.txt") == 0) {
            history = 0;
        } else {
            while(!feof(out)){
                fflush(stdin);
                fscanf(out,"%s # %[^#] #\n",&noInduk,&nama);
                const char *dataNim = mhs.NIM;
                const char *dataInduk = noInduk;
                if(strcmp(dataNim,dataInduk)==0){
                    history = history + 1; //cek data
                }
            }
        }
        fclose(out);
    }
    if(history > 0){
        printf("\n\nDATA SUDAH ADA");
        history = 0;
    }
    else{
        printf("\nDATA BERHASIL DIMASUKKAN");
        FILE *in=fopen("data.mahasiswa.txt","a");
        const char *dataNim = mhs.NIM;
        const char *dataNama = mhs.Nama;
        fprintf(in,"%s # %s # \n",dataNim,dataNama);
        fclose(in);
    }

    //mengulang program
    printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.");
    do{
        printf("\n(y/n): ");
        if(((scanf("%c%c", &pilih, &check)) != 2 || check != '\n') && clearBuffer()){
            printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
        }
        else{
            if(pilih == 'Y' || pilih == 'y'){
                system("cls");
                input_mahasiswaData(mhs);
            }
            else if(pilih == 'N' || pilih == 'n'){
                system("cls");
                main();
            }
            else{
                printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
           }
        }
    }while(1);

}

//fungsi untuk mencari data mahasiswa
void cari_mahasiswaData(mahasiswa mhs){
    system("cls");

    int history;
    char code, y, Y, n, N;
    char pilih, check;

    biodata data;
    printf("\t\t\t===============================================\n");
    printf("\t\t\t==          MENU CARI DATA MAHASISWA         ==\n");
    printf("\t\t\t===============================================\n");
    printf("\nMasukan NIM Mahasiswa    : ");
    scanf("%s",&data);
    fflush(stdin);
    printf("\n\t\t\t===============================================\n");

    FILE *in=fopen("data.mahasiswa.txt","r");
    history = 0;
    if(in==NULL){
        printf("\n\t\t\t\tData Tidak Ditemukan");
    }else{
        while(!feof(in)){
            fflush(stdin);
            fscanf(in,"%s # %[^#] #\n",&mhs.NIM,&mhs.Nama);
            if(strcmp(mhs.NIM,data)==0){
                printf("\t\t\tNIM       : %s\n",mhs.NIM);
                printf("\t\t\tNama      : %s\n",mhs.Nama);
                history = history + 1;
                }
        }
        fclose(in);
        if(history == 0){
            printf("\nData Tidak Ditemukan");
        }
        history = 0;
    }

    //mengulang program
    printf("\n\nApakah Anda Ingin Mengulang Program?\nMasukkan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.");
    do{
        printf("\n(y/n): ");
        if(((scanf("%c%c", &pilih, &check)) != 2 || check != '\n') && clearBuffer()){
            printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
        }
        else{
            if(pilih == 'Y' || pilih == 'y'){
                system("cls");
                cari_mahasiswaData(mhs);
            }
            else if(pilih == 'N' || pilih == 'n'){
                system("cls");
                main();
            }
            else{
                printf("Input Salah! Tekan Y Untuk Mengulang dan N Untuk Kembali ke Menu Utama.\n");
           }
        }
    }while(1);

}

//fungsi untuk menampilkan data mahasiswa
void print_mahasiswaData(mahasiswa mhs){
    int no=1;
	system("cls");

    printf("\t\t\t===============================================\n");
    printf("\t\t\t==             DATA MAHASISWA                ==\n");
    printf("\t\t\t===============================================\n");

	FILE *in=fopen("data.mahasiswa.txt","r");
    if(in==NULL){
        printf("\n\nData Tidak Tersedia");
    }else{
        while(!feof(in)){
            fflush(stdin);
            fscanf(in,"%s # %[^#] #\n",&mhs.NIM,&mhs.Nama);
            printf("\t\t\t%d.  NIM       : %s\n",no,mhs.NIM); no++;
            printf("\t\t\t    Nama      : %s\n",mhs.Nama);
            printf("\t\t\t===============================================\n");
        }
        fclose(in);
    }
        printf("\nAnda Akan Kembali ke Menu Utama\n");
        system("pause");
        system("cls");
        main();

}

//fungsi untuk validasi input integer
int validasiInt(int *var){
	char buff[1024];
	char cek;

	if (fgets(buff, sizeof(buff), stdin) !=NULL) {
		if (sscanf(buff, "%d %c", var, &cek) ==1){
			return 1;
		}
	}
	return 0;
}

//fungsi untuk membersihkan buffer
int clearBuffer(){

    while(getchar() != '\n');

    return 1;
}
