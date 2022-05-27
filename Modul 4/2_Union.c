#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> //untuk fungsi sleep()
//
int panjangSisi;

typedef struct {
    int panjang, luasPermukaan, volume;
}kubusStruct;

typedef union{
    int panjang, luasPermukaan, volume;
}kubusUnion;


//fungsi validasi integer
int validasiint(int *var){
	char buff[1024];
    char x;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &x) == 1) {
        return 1;
        }
    }
 return 0;
}




//fungsi untuk mengulangi program
int ulangi(){
    char pilihan[2];
    printf("\n\tApakah anda ingin mengulang program ini? (y/t) \n");
    scanf("%s",&pilihan);
    if(strcmpi(pilihan,"y")==0){
        system("cls");
        return 1;
    }else if(strcmpi(pilihan,"t")==0){
        system("cls");
        main();
    }else{
        printf("\tSilahkan Masukkan Pilihan Yang Benar!! ");
        ulangi();
    }
    return 0;
}


void KubusStruct(){
    system("cls");
    printf("\t\t+=====================+\n");
    printf("\t\t| KUBUS DENGAN STRUCT |\n");
    printf("\t\t+=====================+\n\n");
    printf("\tMasukkan Panjang Sisi Kubus : ");
    if(validasiint(&panjangSisi) != 1){
        system("cls");
        fflush(stdin);
        printf("\n\tInput salah! Input Harus Berupa Angka.\nSilahkan coba lagi.\n");
        KubusStruct();
    }
    printf("\n");

    kubusStruct structs = {.panjang = panjangSisi,
                           .luasPermukaan = 6 * panjangSisi * panjangSisi,
                           .volume = panjangSisi * panjangSisi * panjangSisi};

    printf("\tPanjang Sisi   : %d\n", structs.panjang);
    printf("\tLuas Permukaan : %d\n", structs.luasPermukaan);
    printf("\tVolume         : %d\n\n", structs.volume);
    printf("\tUkuran Memory pada Kubus Struct : %d\n\n", sizeof(structs));

    switch (ulangi()){
        case 1:
            KubusStruct;
            break;
    }

}

void KubusUnion(){
    system("cls");
    printf("\t\t+====================+\n");
    printf("\t\t| KUBUS DENGAN UNION |\n");
    printf("\t\t+====================+\n\n");
    printf("\tMasukkan Panjang Sisi Kubus : ");
    if(validasiint(&panjangSisi) != 1){
        system("cls");
        fflush(stdin);
        printf("\n\tInput salah! Input Harus Berupa Angka \n\tSilahkan coba lagi.\n");
        KubusUnion();
    }
    printf("\n");

    kubusUnion unions[3];
    unions[0].panjang = panjangSisi;
    unions[1].luasPermukaan = 6 * panjangSisi * panjangSisi;
    unions[2].volume = panjangSisi * panjangSisi * panjangSisi;

    printf("\tPanjang Sisi   : %d\n", unions[0]);
    printf("\tLuas Permukaan : %d\n", unions[1]);
    printf("\tVolume Kubus   : %d\n\n", unions[2]);
    printf("\tUkuran Memory pada Kubus Union  : %d\n\n", sizeof(unions[0]));

    switch (ulangi()){
        case 1:
            KubusUnion;
            break;
    }
}

int main(){
    system("COLOR 70");
	int pilihan;
    system("cls");
    printf("\t+=====================================================+\n");
    printf("\t|==|       PROGRAM KUBUS DENGAN STRUCT & UNION      |==|\n");
    printf("\t|==|                   KELOMPOK 23                  |==|\n");
    printf("\t+=====================================================+\n\n");

    printf("\t\t\t+==========================+\n");
    printf("\t\t\t|        MAIN  MENU        |\n");
    printf("\t\t\t+==========================+\n");
    printf("\t\t\t| 1. Kubus Dengan Struct   |\n");
    printf("\t\t\t| 2. Kubus Dengan Union    |\n");
    printf("\t\t\t| 3. Tutup Program         |\n");
    printf("\t\t\t+==========================+\n\n");
	printf("\n\tMasukkan pilihan anda : ");

    if(validasiint(&pilihan) != 1){
	system("cls");
	fflush(stdin);
    printf("\n\tInput salah! Input Harus Berupa Angka 1-3.\n\tSilahkan coba lagi.\n");
    main();
    }

    //system("cls");

    switch(pilihan){
        case 1 :
            KubusStruct();
			break;
        case 2 :
            KubusUnion();
            break;
        case 3 :
            printf("\n");
            printf("\t+===============================================+\n");
            printf("\t|                 Terima  Kasih                 |\n");
            printf("\t+===============================================+\n\n");
            exit(1);
        default:
        printf("\n\tInput salah! Input Harus Berupa Angka 1-3.\n\tSilahkan coba lagi.\n");
        sleep(2);
        main();

    }

    return 0;
}
