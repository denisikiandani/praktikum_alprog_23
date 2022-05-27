#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


typedef struct{
    char nama[200];
    int total_jamkerja;
    int jam_lembur;
    int jam_pokok;
    int gaji_pokok;
    int gaji_lembur;
    int total_gaji;

} Gaji;


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


void repeatint(int *var){

 while(1){

  if(validasiint(var))

   break;

   printf("\t\t\t\tInputan tidak valid\nInputkan Ulang \t:");
 }
}

void kembali(){
    char pil[2];
    printf("\n\t\t\t\tApakah anda ingin mengulang program ini? (y/t) \n");
    scanf("%s",&pil);
    if(strcmpi(pil,"y")==0){
        system("cls");
        main();
    }else if(strcmpi(pil,"t")==0){
        printf("\n");
        printf("\t+===============================================+\n");
        printf("\t|                 Terima  Kasih                 |\n");
        printf("\t+===============================================+\n\n");
        exit(1);
    }else{
        printf("\t\t\t\tSilahkan Masukkan Pilihan Yang Benar!! ");
        kembali();
    }
getch();
}

int main(){
    system("COLOR 70");
    Gaji g;
    g.total_jamkerja=0;
    g.jam_lembur=0;
    g.jam_pokok=0;
    g.gaji_pokok=0;
    g.gaji_lembur=0;
    g.total_gaji=0;

     printf("\t\t\t\t|==============================================|\n"
        "\t\t\t\t|========== PROGRAM MENGHITUNG GAJI ===========|\n"
        "\t\t\t\t|==============  KELOMPOK 23  =================|\n"
        "\t\t\t\t|============= MODUL 4 NOMOR 1    =============|\n"
        "\t\t\t\t|==============================================|\n\n");
    printf("\t\t\t\tMasukan Nama Anda: ");
    scanf("%s",&g.nama);
    printf("\t\t\t\tMasukan Jam Kerja Anda:");
    repeatint(&g.total_jamkerja);

    if(g.total_jamkerja>8){
        g.jam_pokok=8;
        g.jam_lembur=g.total_jamkerja-8;
        g.gaji_pokok=8*10625;
        g.gaji_lembur=(g.jam_lembur*85000);

    }else{
        g.gaji_pokok=10625*g.total_jamkerja;
        g.jam_pokok=g.total_jamkerja;

    }

      g.total_gaji = g.gaji_lembur + g.gaji_pokok;

    printf("\n\t\t\t\tJumlah Jam Kerja Anda 	:%d \n",g.total_jamkerja);
    printf("\t\t\t\tJumlah Jam Kerja Pokok  :%d \n",g.jam_pokok);
    printf("\t\t\t\tJumlah Jam Kerja Lembur :%d \n",g.jam_lembur);
    printf("\t\t\t\tJumlah Gaji Pokok       :%d \n",g.gaji_pokok);
    printf("\t\t\t\tJumlah Gaji Lembur      :%d \n",g.gaji_lembur);
    printf("\t\t\t\tJumlah Total Gaji Anda  :%d \n",g.total_gaji);

    kembali();
    }
