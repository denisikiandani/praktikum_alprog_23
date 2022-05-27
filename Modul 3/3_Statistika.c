#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void reinput();
void statistika();
void judulprogram();
void rangeVldIntReinput();
void rangeVldInt();

int main(){
    system("COLOR 70");
    int n;
    judulprogram();
   	rangeVldInt(&n, "\n\n\t\t\t\t\tMasukkan Jumlah Data : ");
	fflush(stdin);
	statistika(&n);
	reinput();
}

void judulprogram(){
    system("cls");
    printf("\n\t\t\t\t\t  PRATIKUM ALPROG MODUL 3 NO. 3  ");
	printf("\n\t\t\t\t\t	   KELOMPOK 23			     ");
    printf("\n\t\t\t\t\t================================"            );
    printf("\n\t\t\t\t\t       Program Statistika"                   );
    printf("\n\t\t\t\t\t================================"            );
}

void statistika(int *n){
	judulprogram();
    int a,b,temp = 0, q1, q2;
    int data [*n], frekuensi[*n], modus, max=0,sum=0;

    for (a = 0; a<*n;a++){
        printf("\n\n\t\t\t\t\tMasukkan data ke-%d\t: ",a+1);
        scanf("%d", &data[a]);
    	sum=sum+data[a];
    }
    printf("\n\n");

	//sorting
    for(a=0;a<(*n-1);a++){
        for(b=a;b<*n;b++){
            if(data[b]<data[a]){
                temp=data[a];
                data[a]=data[b];
                data[b]=temp;
            }
        }
    }

    printf("\n\t\t\t\t\tData setelah diurutkan : ");
    for(a=0;a<*n;a++){
        printf("%d ", data[a]);
    }

	//median
	float median;
    if(*n%2==1){
        q2=(*n/2);
        median=data[q2];
        printf("\n\t\t\t\t\tMedian data tersebut : %.2f",median);
    }else if(*n%2==0){
		q1=(*n/2)-1;
		q2=(*n/2);
        median=((float)data[q1]+(float)data[q2])/2;
        printf("\n\t\t\t\t\tMedian data tersebut : %.2f",median);
    }

	//mean
	float mean;
    mean=(float)sum/ *n;
    printf("\n\t\t\t\t\tMean data tersebut : %.2f",mean);

	//modus
    for(a=0;a<=data[*n-1];a++){
        frekuensi[a]=0;
        for(b=0;b<*n;b++){
            if(data[b]==a){
                frekuensi[a]=frekuensi[a]+1;
            }
        }
        if(frekuensi[a]>max){
            max=frekuensi[a];
			modus=a;
        }
    }

    printf("\n\t\t\t\t\tModus data tersebut : %d\n\n",modus);
}

void reinput(){
    int pilih;
    int n;
    printf("\n\t\t\t\t\t===============================");
    printf("\n\t\t\t\t\tApakah anda ingin mengulang operasi?");
    printf("\n\t\t\t\t\t[1] Untuk Mengulang Perhitungan\n");
    printf("\n\t\t\t\t\t[2] Untuk kembali Keluar Dari Program\n");
    rangeVldIntReinput(&pilih, "\n\t\t\t\t\tMasukan Pilihan = ");
    if(pilih == 1){
        system("cls");
        main();
    }else if(pilih == 2){
    	system("cls");
    	exit (0);
    }
}

int validInt(int *var){
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

void reVldInt(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validInt(var))
			break;
		printf("\n\t\t\t\t\tInput salah! Masukkan Angka\n");
	}
}

void rangeVldInt(int *var, char *prompt){
	while(1){
		reVldInt(var, prompt);
		if(*var >=1)
			break;
		printf("\n\t\t\t\t\tInput salah! Masukkan Angka Lebih dari 0\n");
	}
}

void rangeVldIntReinput(int *var, char *prompt){
	while(1){
		reVldInt(var, prompt);
		if(*var == 1 || *var == 2)
			break;
		printf("\n\t\t\t\t\tInput salah! Pilih 1 atau 2.\n");
	}
}
