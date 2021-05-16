/* File: driver_point.c */
/* Nama : Reihan Andhika Putra */
// Nim : 13519043
// Topik : Driver Point
/* Tanggal: 02 September 2020 */

#include <stdio.h>
#include "point.h"

int main()
{
    POINT P, P2;
    float dx, dy, sudut;

    printf("Masukkan nilai absis dan ordinat! \n");
    BacaPOINT(&P);
    printf("Titik yang dibaca: ");
    TulisPOINT(P);
    printf("\n");

    if (IsOrigin(P))
    {
        printf("Sebuah titik Origin\n");
    }
    else
    {
        printf("Bukan titik Origin\n");
    }

    
    if (IsOnSbX(P))
    {
        printf("Ada di sumbu X\n");
    }
    else
    {
        printf("Tidak ada di sumbu X\n");
    }

    if (IsOnSbY(P))
    {
        printf("Ada di sumbu y\n");
    }
    else
    {
        printf("Tidak ada di sumbu Y\n");
    }

    printf("Terletak di kuadran %d \n", Kuadran(P));
    
    printf("Tanpa mengubah nilai titik, jika x digeser 1 maka titiknya: ");
    TulisPOINT(NextX(P));
    printf("\n");

    printf("Tanpa mengubah nilai titik, jika y digeser 1 maka titiknya: ");
    TulisPOINT(NextY(P));
    printf("\n");

    printf("Geser sejajar sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("Geser sejajar sumbu y sebesar = ");
    scanf("%f", &dy);
    printf("Tanpa mengubah nilai titik, setelah digeser maka titiknya : ");
    TulisPOINT(PlusDelta(P, dx, dy));
    printf("\n");

    printf("Tanpa mengubah nilai titik, jika dicerminkan terhadap sumbu x maka titiknya : ");
    TulisPOINT(MirrorOf(P, true));
    printf("\n"); 

    printf("Tanpa mengubah nilai titik, jika dicerminkan terhadap sumbu y maka titiknya : ");
    TulisPOINT(MirrorOf(P, false));
    printf("\n"); 

    printf("Jarak titik tersebut terhadap titik origin adalah %f \n", Jarak0(P));

    printf("Definisikan P2 = (1,1) \n");
    P2 = MakePOINT(1,1);
    printf("Jarak titik terhadap P2 adalah %f \n", Panjang(P,P2));

    printf("Geser sejajar sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("Geser sejajar sumbu y sebesar = ");
    scanf("%f", &dy);
    Geser(&P,dx,dy);
    printf("Dengan menubah nilai titik, setelah digeser maka titiknya : ");
    TulisPOINT(P);
    printf("\n");
    
    printf("Dengan mengubah nilai titik, jika dicerminkan terhadap sumbu x maka titiknya : ");
    Mirror(&P, true);
    TulisPOINT(P);
    printf("\n"); 

    printf("Dengan mengubah nilai titik, jika dicerminkan terhadap sumbu y maka titiknya : ");
    Mirror(&P, false);
    TulisPOINT(P); 
    printf("\n");

    printf("Masukkan sudut (derajat) :");
    scanf("%f", &sudut);
    printf("Nilap P akan dirotasi, hasil titikny adalah :");
    Putar(&P, sudut);
    TulisPOINT(P);
    printf("\n");
    return 0;
}