#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PHI 3.14

/*Program Menghitung Luas dan Kll Bangun Datar*/

int validInteger(int *var);
void reVldInteger(int *var, char *nama);
float validFloat(float *var);
void reVldFloat(float *var, char *nama);
void rangeVldInt(int *var, int range1, int range2, char *nama);
void subMenu(int pilihBangunDatar);
void pilihanOperasi(int pilihBangunDatar);
void subProgramBangunDatar(int pilihBangunDatar, int pilihHitung, int pilihKondisi);
int pilihKondisi;


int main(){
    int pilihBangunDatar, pilihHitung;
    int inputUlang;

    system("COLOR 70");
    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 1-------------");
    printf("\n\t\t\t-------------------KELOMPOK 23-------------------");
    printf("\n\t\t\t\t================================");
    printf("\n\t\t\t\tProgram 1.2 Menghitung luas");
    printf("\n\t\t\t\tdan keliling bangun datar") ;
    printf("\n\t\t\t\t================================");

    printf("\n\t\t\tPilihan Menu:\n");
    printf("\t\t\t1. Segitiga Sembarang   || kode = 1\n");
    printf("\t\t\t2. Belah Ketupat        || kode = 2\n");
    printf("\t\t\t3. Jajar Genjang        || kode = 3\n");
    printf("\t\t\t4. Trapesium            || kode = 4\n");
    printf("\t\t\t5. Lingkaran            || kode = 5\n");
    printf("\t\t\t6. KELUAR               || kode = 6\n");
    reVldInteger(&pilihBangunDatar, "Masukkan Piihan Menu: ");

    switch (pilihBangunDatar){
        case 1:
            subMenu(pilihBangunDatar);
            break;
        case 2:
            pilihanOperasi(pilihBangunDatar);
            break;
        case 3:
            pilihanOperasi(pilihBangunDatar);
            break;
        case 4:
            subMenu(pilihBangunDatar);
            break;
        case 5:
            pilihanOperasi(pilihBangunDatar);
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
        printf("\t\t\t Input salah! Hanya Masukkan Angka.\n");
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
        if(*var >= range1  && *var <= range2){
            break;
        }
        printf("\t\t\t Input salah! Silahkan coba lagi.\n");
    }
}

void subMenu(int pilihBangunDatar){
    system ("cls");
    if(pilihBangunDatar == 1){
        printf("\n\t\t\t=============================================================\n\n");
        printf("\t\t\tPilihan Kondisi:\n");
        printf("\t\t\t1. Diketahui semua sisi segitiga\n");
        printf("\t\t\t2. Diketahui hanya 2 sisi segitiga dan 1 sudut\n");
        printf("\t\t\t3. KEMBALI\n");
        printf("\n\t\t\t=============================================================\n");
        rangeVldInt(&pilihKondisi, 1,3, "Masukkan Pilihan Kondisi: ");
    }else if(pilihBangunDatar == 4){
        printf("\n\t\t\t=============================================================\n\n");
        printf("\t\t\tPilihan Kondisi:\n");
        printf("\t\t\t1. Trapesium Sama Kaki\n");
        printf("\t\t\t2. Trapesium Siku-siku\n");
        printf("\t\t\t3. KEMBALI\n");
        printf("\n\t\t\t=============================================================\n");
        rangeVldInt(&pilihKondisi,1, 3, "Masukkan Pilihan Kondisi: ");
    }
    if(pilihKondisi >= 1 && pilihKondisi <= 2){
        pilihanOperasi(pilihBangunDatar);
    }else if(pilihKondisi == 3){
        main();
    }
}

void pilihanOperasi(int pilihBangunDatar){
    int pilihHitung;

    system("cls");
    printf("\n\t\t\t========================");
    printf("\n\n\t\t\t1. Keliling     |kode =1|");
    printf("\n\t\t\t2. Luas         |kode =2|");
    printf("\n\t\t\t3. KEMBALI      |kode =3|\n");
    printf("\n\t\t\t========================");
    rangeVldInt(&pilihHitung,1,3,"\n\nPilih Operasi Perhitungan : ");

    if(pilihHitung == 1 || pilihHitung == 2){
        subProgramBangunDatar(pilihBangunDatar, pilihHitung, pilihKondisi);
    }else{
        switch(pilihBangunDatar){
            case 1:
            case 2:
                subMenu(pilihBangunDatar);
                break;
        }
        main();
    }
}

void subProgramBangunDatar(int pilihBangunDatar, int pilihHitung, int pilihKondisi){
    float keliling, luas;
    char namaBangun[100];
    int inputUlang;

    system("cls");
    if(pilihBangunDatar == 1){
        float sp; //semi perameter
        float sisi1, sisi2, sisi3;
        float sudut, radian;
        strncpy(namaBangun, "Segitiga Sembarang", sizeof(namaBangun));

        if(pilihKondisi == 1){
            if(pilihHitung == 1){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t   Program Mehitung Keliling %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }else if(pilihHitung == 2){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t    Program Mehitung Luas %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }
            reVldFloat(&sisi1, "\n\t\t\tMasukkan sisi ke-1: ");
            reVldFloat(&sisi2, "\n\t\t\tMasukkan sisi ke-2: ");
            reVldFloat(&sisi3, "\n\t\t\tMasukkan sisi ke-3: ");

            sp = (sisi1 + sisi2 + sisi3) / 2;
            luas = sqrt(sp*(sp - sisi1)*(sp - sisi2)*(sp - sisi3));
        }else if(pilihKondisi == 2){
            if(pilihHitung == 1){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t   Program Mehitung Keliling %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }else if(pilihHitung == 2){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t    Program Mehitung Luas %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }
            reVldFloat(&sisi1, "\n\t\t\tMasukkan sisi ke-1: ");
            reVldFloat(&sisi2, "\n\t\t\tMasukkan sisi ke-2: ");
            reVldFloat(&sudut, "\n\t\t\tMasukkan Nilai Sudut: ");

            sp = (sisi1 + sisi2 + sisi3) / 2;
            radian = sudut * PHI/180;
            luas = 0.5 * sisi1 * sisi2 * sin(radian);
            sisi3 = sqrt(sisi1*sisi1 + sisi2*sisi2 - 2*sisi1*sisi2 * cos(radian));
        }
        keliling = sisi1 + sisi2 + sisi3;
    }else if(pilihBangunDatar == 2){
        float d1, d2, sisi;
        strncpy(namaBangun, "Belah Ketupat", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t     Program Mehitung Keliling %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t       Program Mehitung Luas %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&d1, "\n\t\t\tMasukkan diagonal ke-1: ");
        reVldFloat(&d1, "\n\t\t\tMasukkan diagonal ke-2: ");

        luas = 0.5 * d1 * d2;
        sisi = sqrt((d1/2 * d1/2) + (d2/2 * d2/2));
        keliling = 4*sisi;
    }else if(pilihBangunDatar == 3){
        float alas, tinggi, s_miring;
        strncpy(namaBangun, "Jajar Genjang", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t     Program Mehitung Keliling %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t       Program Mehitung Luas %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&alas, "\n\t\t\tMasukkan Alas: ");
        reVldFloat(&tinggi, "\n\t\t\tMasukkan Tinggi: ");
        reVldFloat(&s_miring, "\n\t\t\tSisi Miring: ");

        luas = alas * tinggi;
        keliling = (2*alas) + (2*s_miring);
    }else if(pilihBangunDatar == 4){
        float alas_b, alas_a, s_miring, tinggi, alas_sgt;
        strncpy(namaBangun, "Trapesium", sizeof(namaBangun));
        if(pilihKondisi == 1){
            if(pilihHitung == 1){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t       Program Mehitung Keliling %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }else if(pilihHitung == 2){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t        Program Mehitung Luas %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }
            reVldFloat(&alas_b, "\t\t\tMasukkan Alas Bawah: ");
            reVldFloat(&alas_a, "\t\t\tMasukkan Alas Atas: ");
            reVldFloat(&tinggi, "\t\t\tMasukkan Tinggi: ");

            alas_sgt = (alas_b - alas_a)/2;
            s_miring = sqrt(alas_sgt * alas_sgt + tinggi * tinggi);
            keliling = (2*s_miring) + alas_a + alas_b;
        }else if(pilihKondisi == 2){
            if(pilihHitung == 1){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t       Program Mehitung Keliling %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }else if(pilihHitung == 2){
                printf("\n\t\t\t|===============================================|\n");
                printf("\n\t\t\t        Program Mehitung Luas %s 	        \n", namaBangun);
                printf("\n\t\t\t|===============================================|\n");
            }
            reVldFloat(&alas_b, "\t\t\tMasukkan Alas Bawah: ");
            reVldFloat(&alas_a, "\t\t\tMasukkan Alas Atas: ");
            reVldFloat(&tinggi, "\t\t\tMasukkan Tinggi: ");

            alas_sgt = alas_b - alas_a;
            s_miring = sqrt(alas_sgt*alas_sgt + tinggi*tinggi);
            keliling = alas_a + alas_b + tinggi + s_miring;
        }
        luas = 0.5 * (alas_a + alas_b) * tinggi;
    }else if(pilihBangunDatar == 5){
        float jari_jari, tinggi;
        strncpy(namaBangun, "Lingkaran", sizeof(namaBangun));
        if(pilihHitung == 1){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t       Program Mehitung Keliling %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }else if(pilihHitung == 2){
            printf("\n\t\t\t|===============================================|\n");
            printf("\n\t\t\t        Program Mehitung Luas %s 	        \n", namaBangun);
            printf("\n\t\t\t|===============================================|\n");
        }
        reVldFloat(&jari_jari, "\t\t\tMasukkan Jari-Jari: ");

        luas = PHI * jari_jari * jari_jari;
        keliling = PHI * 2 * jari_jari;
    }
    if(pilihHitung == 1){
        printf("\n\t\t\t\t\t  Keliling = %.2f\n", keliling);
    }else if(pilihHitung == 2){
        printf("\n\t\t\t\t\t  Luas = %.2f\n", luas);
    }
    printf("\t\t\t\t  ============================\n");

    printf("\n\t\t\t1. Ulangi Menghitung");
    printf("\n\t\t\t2. Ganti Operasi Hitung");
    printf("\n\t\t\t3. Ulang Memilih Kondisi");
    printf("\n\t\t\t4. Menu Utama");
    printf("\n\t\t\t5. Akhiri Program");
    printf("\n\t\t\t==================================\n");
    rangeVldInt(&inputUlang, 1,5, "\n\n\t\t\t Pilih : ");

    switch (inputUlang){
        case 1:
            subProgramBangunDatar(pilihBangunDatar, pilihHitung, pilihKondisi);
            break;
        case 2:
            pilihanOperasi(pilihBangunDatar);
            break;
        case 3:
            if(pilihBangunDatar == 1 || pilihBangunDatar == 4){
                subMenu(pilihBangunDatar);
            }else{
                printf("\n\t\t\tBanungun Ruang Ini TIDAK Memiliki Kondisi\n\n");
                rangeVldInt(&inputUlang,0,1,"\t\t\tIngin Kembali ke MENU utama? \t [ 1(iya) / 0(tidak) ] : ");
                if(inputUlang == 1){
                    main();
                }else{
                    printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
                }
            }
            break;
        case 4:
            main();
            break;
        case 5:
            printf("\n\t\t\t\tTekan ENTER untuk keluar!\n");
            break;
    }
}


