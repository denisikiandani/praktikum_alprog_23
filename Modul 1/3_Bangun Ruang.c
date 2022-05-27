#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PHI 3.14

int validInteger(int *var);
void reVldInteger(int *var, char *nama);
float validFloat(float *var);
void reVldFloat(float *var, char *nama);
void rangeVldInt(int *var, int range1, int range2, char *nama);
float vol_Tabung(float jari_jari, float tinggi);
float LP_Tabung(float jari_jari, float tinggi);
float vol_Bola(float jari_jari);
float LP_Bola(float jari_jari);
float vol_LimasSegiempat(float p_alas, float l_alas, float t_limas);
float LP_LimasSegiempat(float p_alas, float l_alas, float t_limas);
float vol_PrismaSegitiga(float sisi1, float sisi2, float sisi3, float t_prisma);
float LP_PrismaSegitiga(float sisi1, float sisi2, float sisi3, float t_prisma);
float vol_Kerucut(float jari_jari, float t_kerucut);
float LP_Kerucut(float jari_jari, float t_kerucut);
void pilihanOperasi(int pilih_bangunRuang);
void subProgramBangunRuang(int pilih_bangunRuang, int pilihHitung);

int main(){
    int pilih_bangunRuang;
    int inputUlang;

    system ("COLOR 70");
    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 1-------------");
    printf("\n\t\t\t-------------------KELOMPOK 23-------------------");
    printf("\n\t\t\t\t================================");
    printf("\n\t\t\t\t  Program 1.3 Menghitung volume");
    printf("\n\t\t\t\t    dan luas permukaan bangun");
    printf("\n\t\t\t\t\t     ruang");
    printf("\n\t\t\t\t================================");

    printf("\n\t\t\tPilihan Menu: \n");
    printf("\t\t\t1. Tabung               || kode = 1\n");
    printf("\t\t\t2. Bola                 || kode = 2\n");
    printf("\t\t\t3. Limas Segiempat      || kode = 3\n");
    printf("\t\t\t4. Prisma Segiiga       || kode = 4\n");
    printf("\t\t\t5. Kerucut              || kode = 5\n");
    printf("\t\t\t6. KELUAR               || kode = 5\n");
    reVldInteger(&pilih_bangunRuang, "Masukkan Pilihan Menu: ");

    switch (pilih_bangunRuang){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            pilihanOperasi(pilih_bangunRuang);
            break;
        case 6:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
        default:
            printf("\n\t\t\tMaaf Pilihan Operasi Tidak Tersedia\n\n");
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

//validasi menerima input float
float validFloat(float *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%f %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}

//validasi ulang float
void reVldFloat(float *var, char *nama){
    while(1){
        printf("%s",nama);
        fflush(stdin);
        if(validFloat(var))
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

float vol_Tabung(float jari_jari, float tinggi){
    float volume_Tabung = PHI * jari_jari * jari_jari * tinggi;

    return volume_Tabung;
}

float LP_Tabung(float jari_jari, float tinggi){
    float L_permukaan_Tabung = 2 * PHI * jari_jari * tinggi + 2 * PHI * jari_jari * jari_jari;

    return L_permukaan_Tabung;
}

float vol_Bola(float jari_jari){
    float volume_Bola = (4/3) * PHI * jari_jari * jari_jari * jari_jari;

    return volume_Bola;
}

float LP_Bola(float jari_jari){
    float L_permukaan_Bola = 4 * PHI * jari_jari * jari_jari;

    return L_permukaan_Bola;
}

float vol_LimasSegiempat(float p_alas, float l_alas, float t_limas){
    float volume_limasSegi4, luas_alas;
    luas_alas = p_alas * l_alas;

    volume_limasSegi4 = 0.33 * luas_alas * t_limas;

    return volume_limasSegi4;
}

float LP_LimasSegiempat(float p_alas, float l_alas, float t_limas){
    float s_miring, d_alas, luas_alas, t_segitiga1, t_segitiga2;
    float luas_segitiga1, luas_segitiga2;
    float LP_limasSegi4;

    d_alas = sqrt(p_alas * p_alas + l_alas * l_alas);
    s_miring = sqrt(d_alas/2 * d_alas/2 + t_limas*t_limas);
    t_segitiga1 = sqrt(p_alas/2 * p_alas/2 + t_limas * t_limas);
    t_segitiga2 = sqrt(l_alas/2 * l_alas/2 + t_limas * t_limas);

    luas_alas = p_alas * l_alas;
    luas_segitiga1 = 0.5 * p_alas * t_segitiga1;
    luas_segitiga2 = 0.5 * l_alas * t_segitiga2;

    LP_limasSegi4 = luas_alas + (2*luas_segitiga1) + (2*luas_segitiga2);
    return LP_limasSegi4;
}

float vol_PrismaSegitiga(float sisi1, float sisi2, float sisi3, float t_prisma){
    float sp, luas_alas, volume_prismaSegitiga;

    sp = (sisi1 + sisi2 + sisi3) / 2;
    luas_alas = sqrt(sp*(sp - sisi1)*(sp - sisi2)*(sp - sisi3));

    volume_prismaSegitiga = luas_alas*t_prisma;
    return volume_prismaSegitiga;
}

float LP_PrismaSegitiga(float sisi1, float sisi2, float sisi3, float t_prisma){
    float sp, luas_alas, keliling_alas, LP_prismasegitiga;

    sp = (sisi1 + sisi2 + sisi3) / 2;
    luas_alas = sqrt(sp*(sp - sisi1)*(sp - sisi2)*(sp - sisi3));
    keliling_alas = sisi1 + sisi2 + sisi3;

    LP_prismasegitiga = 2*luas_alas + keliling_alas*t_prisma;

    return LP_prismasegitiga;
}

float vol_Kerucut(float jari_jari, float t_kerucut){
    float volume_kerucut;

    volume_kerucut = 0.33*PHI*jari_jari*jari_jari*t_kerucut;
    return volume_kerucut;
}

float LP_Kerucut(float jari_jari, float t_kerucut){
    float sisi_miring, LP_kerucut;

    sisi_miring = sqrt(jari_jari*jari_jari + t_kerucut*t_kerucut);
    LP_kerucut = PHI*jari_jari*jari_jari + PHI*jari_jari*sisi_miring;
    return LP_kerucut;
}

void pilihanOperasi(int pilih_bangunRuang){
    int pilihHitung;

    system("cls");
    printf("\n\t\t\t=============================");
    printf("\n\n\t\t\t1. Volume           |kode =1|");
    printf("\n\t\t\t2. Luas Permukaan   |kode =2|");
    printf("\n\t\t\t3. KEMBALI          |kode =3|\n");
    printf("\n\t\t\t=============================");
    rangeVldInt(&pilihHitung,1,3,"\n\nPilih Operasi Perhitungan : ");

    if(pilihHitung >= 1 && pilihHitung <= 2){
        subProgramBangunRuang(pilih_bangunRuang, pilihHitung);
    }else{
        main();
    }
}

void subProgramBangunRuang(int pilih_bangunRuang, int pilihHitung){
    float volume, luas_permukaan;
    char namaBangun[100];
    int inputUlang;
    float p_alas, l_alas, t_limas;
    float jari_jari, tinggi;
    float sisi1, sisi2, sisi3, t_prisma, t_kerucut;

    system("cls");
    if(pilih_bangunRuang == 1){
        strncpy(namaBangun, "Tabung", sizeof(namaBangun));

        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t         Program Mehitung Volume %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t     Program Mehitung Luas Permukaan %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&jari_jari, "\n\t\t\tMasukkan Jari-Jari Alas Tabung: ");
        reVldFloat(&tinggi, "\n\t\t\tMasukkan Tinggi Tabung: ");

        volume = vol_Tabung(jari_jari, tinggi);
        luas_permukaan = LP_Tabung(jari_jari, tinggi);
    }else if(pilih_bangunRuang == 2){
        strncpy(namaBangun, "Bola", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t         Program Mehitung Volume %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t     Program Mehitung Luas Permukaan %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&jari_jari, "\n\t\t\tMasukkan Jari-Jari Bola: ");

        volume = vol_Bola(jari_jari);
        luas_permukaan = LP_Bola(jari_jari);
    }else if(pilih_bangunRuang == 3){
        strncpy(namaBangun, "Limas Segiempat", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t      Program Mehitung Volume %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t Program Mehitung Luas Permukaan %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&p_alas, "\n\t\t\tMasukkan Panjang Alas: ");
        reVldFloat(&l_alas, "\n\t\t\tMasukkan Lebar Alas: ");
        reVldFloat(&t_limas, "\n\t\t\tMasukkan Tinggi Limas Segiempat: ");

        volume = vol_LimasSegiempat(p_alas, l_alas, t_limas);
        luas_permukaan = LP_LimasSegiempat(p_alas, l_alas, t_limas);
    }else if(pilih_bangunRuang == 4){
        strncpy(namaBangun, "Prisma Segitiga", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t      Program Mehitung Volume %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t Program Mehitung Luas Permukaan %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&sisi1, "\n\t\t\tMasukkan Sisi ke-1: ");
        reVldFloat(&sisi2, "\n\t\t\tMasukkan Sisi ke-2: ");
        reVldFloat(&sisi3, "\n\t\t\tMasukkan Sisi ke-3: ");
        reVldFloat(&t_prisma, "\n\t\t\tMasukkan Tinggi Prisma Segitiga: ");

        volume = vol_PrismaSegitiga(sisi1, sisi2, sisi3, t_prisma);
        luas_permukaan = LP_PrismaSegitiga(sisi1, sisi2, sisi3, t_prisma);
    }else if(pilih_bangunRuang == 5){
        strncpy(namaBangun, "Kerucut", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t         Program Mehitung Volume %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t     Program Mehitung Luas Permukaan %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&jari_jari, "\n\t\t\tMasukkan Jari-Jari: ");
        reVldFloat(&t_kerucut, "\n\t\t\tMasukkan Tinggi Kerucut: ");

        volume = vol_Kerucut(jari_jari, t_kerucut);
        luas_permukaan = LP_Kerucut(jari_jari, t_kerucut);
    }
    if(pilihHitung == 1){
        printf("\n\t\t\t\t\tVolume = %.2f\n", volume);
    }else if(pilihHitung == 2){
        printf("\n\t\t\t\t    Luas Permukaan = %.2f\n", luas_permukaan);
    }
    printf("\t\t\t\t  ============================\n");

    printf("\n\t\t\t1. Ulangi Menghitung");
    printf("\n\t\t\t2. Ganti Operasi Hitung");
    printf("\n\t\t\t3. Menu Utama");
    printf("\n\t\t\t4. Akhiri Program");
    printf("\n\t\t\t==================================\n");
    rangeVldInt(&inputUlang, 1,4, "\n\n\t\t\t Pilih : ");

    switch (inputUlang){
        case 1:
            subProgramBangunRuang(pilih_bangunRuang, pilihHitung);
            break;
        case 2:
            pilihanOperasi(pilih_bangunRuang);
            break;
        case 3:
            main();
            break;
        case 4:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
    }
}
