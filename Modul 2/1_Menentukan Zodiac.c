#include <stdio.h>	//untuk menjalanakn fungsi basic dari c
#include <stdlib.h>	//untuk menjalankan fungsi system()
#include <string.h>	//untuk menjalankan fungsi strcpy()
#include <conio.h>	//untuk menjalankan fungsi getch()
#include <unistd.h> //untuk menjalankan fungsi sleep()
#include <ctype.h>
#include <stdbool.h>


int pengulangan;
char zodiak[20];
int tahunLahir, bulanLahir, tanggalLahir;
char bulan[10];


void ulang();




char* january(int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 19){
			strcpy(zodiak, "Capricorn");
		}
		else if (tglLahir >= 20){
			strcpy(zodiak, "Aquarius");
	    }
	}

	return zodiak;
}

char* februari(int tglLahir){
	int totalTgl = 29;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 18){
			strcpy(zodiak, "Aquarius");
		}
		else if (tglLahir >= 19){
			strcpy(zodiak, "Pisces");
	    }
	}

	return zodiak;
}

char* maret (int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 20){
			strcpy(zodiak, "Pisces");
		}
		else if (tglLahir >= 21){
			strcpy(zodiak, "Aries");
	    }
	}

	return zodiak;
}

char* april(int tglLahir){
	int totalTgl = 30;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 19){
			strcpy(zodiak, "Aries");
		}
		else if (tglLahir >= 20){
			strcpy(zodiak, "Taurus");
	    }
	}

	return zodiak;
}

char* mei(int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 20){
			strcpy(zodiak, "Taurus");
		}
		else if (tglLahir >= 21){
			strcpy(zodiak, "Gemini");
	    }
	}

	return zodiak;
}

char* juni(int tglLahir){

	int totalTgl = 30;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 20){
			strcpy(zodiak, "Gemini");
		}
		else if (tglLahir >= 21){
			strcpy(zodiak, "Cancer");
	    }
	}

	return zodiak;
}

char* juli(int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 22){
			strcpy(zodiak, "Cancer");
		}
		else if (tglLahir >= 23){
			strcpy(zodiak, "Leo");
	    }
	}

	return zodiak;
}

char* agustus(int tglLahir){
	int totalTgl = 30;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 22){
			strcpy(zodiak, "Leo");
		}
		else if (tglLahir >= 23){
			strcpy(zodiak, "Virgo");
	    }
	}

	return zodiak;
}

char* september(int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 22){
			strcpy(zodiak, "Virgo");
		}
		else if (tglLahir >= 23){
			strcpy(zodiak, "Libra");
	    }
	}

	return zodiak;
}

char* oktober(int tglLahir){
	int totalTgl = 30;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 22){
			strcpy(zodiak, "Libra");
		}
		else if (tglLahir >= 23){
			strcpy(zodiak, "Scorpio");
	    }
	}

	return zodiak;
}

char* november(int tglLahir){
	int totalTgl = 31;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 21){
			strcpy(zodiak, "Scorpio");
		}
		else if (tglLahir >= 22){
			strcpy(zodiak, "Sagitarius");
	    }
	}

	return zodiak;
}

char* desember(int tglLahir){

	int totalTgl = 30;

	if (tglLahir > 0 && tglLahir<= totalTgl){
		if (tglLahir > 0 && tglLahir <= 21){
			strcpy(zodiak, "Sagitarius");
		}
		else if (tglLahir >= 22){
			strcpy(zodiak, "Capricorn");
	    }
	}

	return zodiak;
}

void judul(){

    fflush(stdin);
    system("cls");
    printf("\n\t\t\t------------PRAKTIKUM ALPROG MODUL 2------------");
    printf("\n\t\t\t-------------------KELOMPOK 23------------------");
    printf("\n\t\t\t================================================");
    printf("\n\t\t\t           Program 3.1 Menentukan Zodiak   ");
    printf("\n\t\t\t================================================");

	printf("\n\n\t\tJika ingin kembali ke menu sebelumnya masukkan input 10101\n");
}

void func_bulan(){
    fflush(stdin);
    int pengulangan;
    do{
        printf("\n\t\t[2] Bulan ke berapakah Anda lahir?");
        printf("\n\t\t(masukkan dari angka 1 hingga 12) ");
        bulanLahir = validatorInteger();

        if (bulanLahir == 10101){
            system("cls");
            bulanLahir = 0;
            main();
        }
        if (bulanLahir >= 1 && bulanLahir <= 12){
            if (bulanLahir == 1){
                strcpy(bulan, "Januari");
            }
            else if (bulanLahir == 2){
                strcpy(bulan, "Februari");
            }
            else if (bulanLahir == 3){
                strcpy(bulan, "Maret");
            }
            else if (bulanLahir == 4){
                strcpy(bulan, "April");
            }
            else if (bulanLahir == 5){
                strcpy(bulan, "Mei");
            }
            else if (bulanLahir == 6){
                strcpy(bulan, "Juni");
            }
            else if (bulanLahir == 7){
                strcpy(bulan, "Juli");
            }
            else if (bulanLahir == 8){
                strcpy(bulan, "Agustus");
            }
            else if (bulanLahir == 9){
                strcpy(bulan, "September");
            }
            else if (bulanLahir == 10){
                strcpy(bulan, "Oktober");
            }
            else if (bulanLahir == 11){
                strcpy(bulan, "November");
            }
            else{
                strcpy(bulan, "Desember");
            }
                printf("\n\t\t[2.1] Bulan Kelahiran anda adalah bulan %s\n", bulan);
                pengulangan = 1;
        }
        else {
            mengulang();
        }
    } while(pengulangan == 0);
}

int func_tanggal(){
    int pengulangan;
		printf("\n\t\t[3] Silahkan masukkan tanggal kelahiran anda! ");
		tanggalLahir = validatorInteger();
        if (tanggalLahir == 10101){
            do{
                system("cls");
                func_bulan();
                func_tanggal();
            }while(pengulangan == 0);
        }
    return pengulangan = 1;
}


int validatorInteger(){
    int angka;
    char huruf;
    int c;
    for (;;) {
      if(scanf("%d%c", &angka, &huruf) != 2 || huruf != '\n') {
          printf("\n\t\tMohon Memasukkan Input Berupa Angka! ");

          while (('\n' != (c=fgetc(stdin))) && (c != EOF));
          if (c == EOF) break;
      }
      else {
          break;
      }
    }

    return angka;
}

int mengulang(){
	printf("\n\n\t\tInvalid Input\n\t\tMohon Masukkan Data yang Benar!\n");
	sleep(2);
	//system("cls");

	return pengulangan = 0;
}

int main(void) {
    fflush(stdin);
    system("COLOR 70");

	do{
		judul();

		printf("\n\t\t[1] Silahkan masukkan tahun kelahiran Anda!  ");
		tahunLahir = validatorInteger();

		//Mengecek apakah input tahunLahir benar apa tidak
		if (tahunLahir == 10101){
            system("cls");
            main();
		}
		//
		if (tahunLahir >= 1945 && tahunLahir <= 2030){
			pengulangan = 1;
		}
		else {
			mengulang();
		}

	} while(pengulangan == 0);


    //BAGIAN BULAN
    func_bulan();



    //BAGIAN TANGGAL
	do{
        pengulangan = func_tanggal();

		if (tahunLahir % 4 == 0){
			if (bulanLahir == 2){
				if (tanggalLahir > 0 && tanggalLahir <= 29){
					pengulangan = 1;
				}
				else {
					mengulang();
				}
			}
		}
		else{
				//Mengecek apakah bulan lahir memiliki total tanggal 31 atau tidak
				//dengan cara mengecek apakah ganjil dan apakah bulan ke 8

			if (bulanLahir == 1 || bulanLahir == 3 || bulanLahir == 5 || bulanLahir == 7 || bulanLahir == 8 || bulanLahir == 10 || bulanLahir == 12){
				if (tanggalLahir >= 0 && tanggalLahir <= 31){
					pengulangan = 1;
				}
				else{
					mengulang();
				}
			}
			else if (bulanLahir == 2){
                if (tanggalLahir >=0 && tanggalLahir <= 28){
                    pengulangan = 1;
                }
                else{
                    mengulang();
                }
			}
			else{
				if (tanggalLahir >= 0 && tanggalLahir <= 30){
					pengulangan = 1;
				}
				else{
					mengulang();
				}
			}
		}

	} while(pengulangan == 0);




	if (bulanLahir == 1){
		january(tanggalLahir);
	}

	else if (bulanLahir == 2){
		februari(tanggalLahir);
	}

	else if (bulanLahir == 3){
		maret(tanggalLahir);
    }

    else if (bulanLahir == 4){
        april(tanggalLahir);
    }

    else if (bulanLahir == 5){
        mei(tanggalLahir);
    }

    else if (bulanLahir == 6){
        juni(tanggalLahir);
    }

    else if (bulanLahir == 7){
        juli(tanggalLahir);
    }

    else if (bulanLahir == 8){
        agustus(tanggalLahir);
    }

    else if (bulanLahir == 9){
        september(tanggalLahir);
    }

    else if (bulanLahir == 10){
        oktober(tanggalLahir);
    }

    else if (bulanLahir == 11){
        november(tanggalLahir);
    }

    else if (bulanLahir == 12){
        desember(tanggalLahir);
    }

    printf("\n\t\tBerdasarkan data tersebut, zodiak Anda adalah %s!", &zodiak);

	ulang();

  return 0;
}

void ulang(){
	char inputUlang;
	printf("\n\t\tApakah ingin mengulang kembali? (Y/T) ");

	inputUlang = getch();

	if (inputUlang == 'y' || inputUlang == 'Y'){
		system("cls");
		main();
	}

	else if (inputUlang == 't' || inputUlang == 'T'){
		return;
	}

	else {
		system("cls");
		printf (" Invalid Input\n");
		ulang();
    }
}

