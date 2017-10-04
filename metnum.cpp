/*Nama:	- Hendra Abdul Rohman	3411151132
		- Anggun Titah Islamiyah	3411151179
   Kelas : SIE-C
   Program Operasi Aritmatika
   Tugas Metode Numerik
*/
   
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define nmax 100

int main  (){
	
//kamus data
int angka, jarak;
int q[nmax+1];

int r[nmax+1];
float pre[nmax+1], error[nmax+1];
float k, o, fx;
float sigmaq, sigmar, er, sigmaerror, sigmaqr=0, jumqkuadrat=0, jumrkuadrat=0;
int x, l;
int qkuadrat[nmax+1], rkuadrat[nmax+1], qr[nmax+1];

//algoritma
printf ("\nPROGRAM MENGHITUNG REGRESI LINIER SEDERHANA\n");
printf("-----------------------------------------\n");
printf ("\nMasukkan banyaknya N : "); scanf ("%d", &l);
printf ("\n\n");

//nilai q
for(x=1;x<=l;x++){
	printf ("Masukkan nilai q : ");scanf("%d", &angka);
	q[x]=angka;
	qkuadrat[x]=pow(q[x], 2);
    sigmaq=sigmaq + q[x];
    jumqkuadrat=jumqkuadrat + qkuadrat[x];
} 

//tampil q
printf ("\n  NILAI Q\n");
for (x=1; x<=l;x++){
	printf ("\n q[%d] = %d \n", x, q[x]
	);
} printf ("\n \n");

  
//nilai r
printf("\n--------------------------------\n");
for (x=1;x<=l;x++){
	printf("Masukkan nilai r : "); scanf("%d", &angka);
	r[x]=angka;
	sigmar=sigmar + r[x];
    rkuadrat[x]=pow(r[x], 2);
    jumrkuadrat=jumrkuadrat + rkuadrat[x];
    qr[x]=q[x]*r[x];
    sigmaqr=sigmaqr + qr[x];
}
//tampil r
printf ("\n NILAI r \n");
for (x=1; x<=l;x++){
	printf ("\n r[%d] = %d \n",x, q[x]);
} printf ("\n \n");

  
  //menghitung k
  k=((x*sigmaqr)-(sigmaq*sigmar)) / ((x*jumqkuadrat)-pow(sigmaq, 2));
  printf("\nNilai k = %.2f \n", k);
  
  //menghitung o
  o=((sigmar*jumqkuadrat)-(sigmaq*sigmaqr)) / ((x*jumqkuadrat)-pow(sigmaq, 2));
  printf("\nNilai o = %.2f \n", o);
  
  
  //menghitung prediksi
  printf ("\n--------- PREDIKSI ---------\n");
  for (x=1; x<=l;x++){
      pre[x]=(k*q[x])+o;
      printf ("\nNilai Prediksi jika f[%d] = %.2f \n", q[x], pre[x]);
  }
  
  //menghitung error
   for (x=1; x<=l;x++){
   	error[x]=r[x]-pre[x];
   	if (error[x]<0){
          error[x]=pre[x]-r[x];
	  }
          sigmaerror=sigmaerror + error[x];
   }
       	 //menghitung error
   			er=sigmaerror/l;
  
   
   //tampil error tiap prediksi
    printf ("\n");
   printf ("\n------- SELISIH WAKTU (ERROR) ----------\n");
   for (x=1; x<=l;x++){
    	printf ("\nSelisih Waktu jika f(x)=%.2f yaitu %.2f \n", pre[x], error[x]);
}
   //tampil nilai error keseluruhan
   printf ("\n ------------ ERROR --------------\n");
   printf ("\nMaka nilai error sebesar %.2f \n ", er);
}
