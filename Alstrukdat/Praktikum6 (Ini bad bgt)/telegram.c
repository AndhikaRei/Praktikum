// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 29/09/2020
// Topik : mesintoken.c
// File: mesintoken.h
// File: mesintoken.h 

#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

boolean IsKataSama (Kata K1, Kata K2){
    // Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. Dua kata kosong adalah kata yang sama. 
     boolean sama = true;
    int i = 0;
    
    if (K1.Length == K2.Length){
        while ((i < K1.Length) && sama) {
            if (K1.TabKata[i] != K2.TabKata[i]) {
                sama = false;
            }
            i++;
        }
    } else {
        sama = false;
    }

    return sama;
}

int main(){
    Kata Titik, Koma;
    Titik.TabKata[0] = 'T';
    Titik.TabKata[1] = 'I';
    Titik.TabKata[2] = 'T';
    Titik.TabKata[3] = 'I';
    Titik.TabKata[4] = 'K';
    Titik.Length = 5;
    Koma.TabKata[0] = 'K';
    Koma.TabKata[1] = 'O';
    Koma.TabKata[2] = 'M';
    Koma.TabKata[3] = 'A';
    Koma.Length = 4;
    STARTKATA();
    int nreg = 0;
    int npan = 0 ;
    int i ;
    int countkata = 0;
    while (!EndKata) {
        if (!IsKataSama(CKata, Koma) && !IsKataSama(CKata, Titik)){
            if (countkata > 0) {
                printf(" ");
            }
            for (i=0;i<CKata.Length;i++){
                printf("%c", CKata.TabKata[i]);
            }

            if (CKata.Length >= 10) {
                npan++;
            } else {
                nreg++;
            }
        } else {
            if (IsKataSama(CKata, Koma)) {
                printf(",");
            } else if (IsKataSama(CKata, Titik)) {
                printf(".");
            }
        }
        countkata++;
        IgnoreBlank();
        ADVKATA();
    }
    printf("\n");
    printf("%d \n", nreg);
    printf("%d \n", npan);
    if (countkata >= 10){
        printf("%d", ((npan*1500 + nreg*1000)*90/100));
    } else {
        printf("%d", ((npan*1500 + nreg*1000)));
    }
    printf("\n");
    return 0;
}