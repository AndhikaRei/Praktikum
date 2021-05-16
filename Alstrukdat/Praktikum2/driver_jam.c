/* File: driver_jam.c */
// Nama : Reihan Andhika Putra 
// Nim : 13519043
// Topik : Driver Jam
/* Tanggal: 02 September 2020 */

#include "jam.h"
#include <stdio.h>
#include "boolean.h"

int main() {

    JAM J, J2;
    int det, N;
    det = 5000;
    printf("Mari kita mengetes ADTJam! \n");
    printf("Masukkan jam dibawah \n");
    BacaJAM(&J);
    printf("Jam yang anda masukkan: ");
    TulisJAM(J);
    printf("\n");
    printf("Jika jam sekarang dikonversi menjadi detik: %d\n",JAMToDetik(J));
    J2 = DetikToJAM(det);
    printf("5000 detik sama dengan jam : ");
    TulisJAM(J2);
    printf("\n");
    if (JEQ(J, J2)) 
    {
        printf("JEQ : Jam pertama sama dengan jam kedua \n");
    } else
    {
        printf("JEQ: Jam pertama berbeda dengan jam kedua \n");
    }
    if (JNEQ(J, J2)) 
    {
        printf("JNEQ: Jam pertama berbeda dengan jam kedua \n");
    } else
    {
        printf("JNEQ :Jam pertama sama dengan jam kedua \n");
    }
    if (JLT(J, J2)) 
    {
        printf("JLT: Jam pertama kurang dari jam kedua \n");
    } else
    {
        printf("JLT: Jam pertama lebih dengan jam kedua \n");
    }
    if (JGT(J, J2)) 
    {
        printf("JGT: Jam pertama lebih dari dengan jam kedua \n");
    } else
    {
        printf("JGT: Jam pertama kurang dari dengan jam kedua \n");
    }

    printf("Satu detik setelah jam pertama adalah jam: ");
    TulisJAM(NextDetik(J));
    printf("\n");
    printf("Masukkan N: ");
    scanf("%d",&N);
    printf("N detik setelah jam pertama adalah jam: ");
    TulisJAM(NextNDetik(J,N));
    printf("\n");
    printf("Satu detik sebelum jam pertama adalah jam: ");
    TulisJAM(PrevDetik(J));
    printf("\n");
    printf("N detik sebelum jam pertama adalah jam: ");
    TulisJAM(PrevNDetik(J,N));
    printf("\n");
    printf("Jarak antara jam kedua dan pertama adalah : ");
    printf("%d",Durasi(J,J2));




    
    return 0;
}
