// Nama : Reihan Andhika P
// Nim : 13519043
//  Tanggal : 24/09/2020
//  Topik : Nilaikelas.c
/* Sebuah matriks dengan elemen integer, sebut saja MNilai, digunakan untuk menyimpan data nilai mahasiswa suatu kelas terhadap beberapa mata kuliah. Indeks baris matriks merepresentasikan nomor urut mahasiswa, sedangkan indeks kolom matriks merepresentasikan nomor urut mata kuliah. Nilai mahasiswa nomor urut i pada mata kuliah dengan nomor urut j direpresentasikan sebagai MNilai[i,j]. Nilai mahasiswa adalah integer [0..100].


Buatlah sebuah program yang digunakan untuk mengelola data nilai mahasiswa pada beberapa mata kuliah di suatu kelas dengan memanfaatkan ADT Matriks yang sudah dimodifikasi sesuai soal no. 1. Program menerima banyaknya mahasiswa dalam kelas, misalnya n; diikuti banyaknya mata kuliah yang diambil, misalnya m. Diasumsikan n > 0 dan m > 0. Selanjutnya dilakukan pengisian nilai mata kuliah per mahasiswa. Diasumsikan masukan nilai benar yaitu berada dalam rentang 0..100.


Selanjutnya program akan:

Menampilkan data untuk tiap mahasiswa (dari nomor urut tertinggi sampai terendah):

Nilai rata-rata untuk semua mata kuliah,

Nilai tertinggi dari semua mata kuliah,

Nilai terendah dari semua mata kuliah.

Menampilkan data untuk tiap mata kuliah (dari nomor urut tertinggi sampai terendah):

Nilai rata-rata untuk mata kuliah tersebut

Nilai tertinggi, berapa banyak mahasiswa yang memperolehnya, dan nomor urut mahasiswa yang memperolehnya.

Nilai terendah dan berapa banyak mahasiswa yang memperolehnya, dan nomor urut mahasiswa yang memperolehnya.

Semua data real dituliskan dengan 2 angka di belakang koma.*/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"


void TulisNilaiX (MATRIKS M, indeks j, ElType X){
    /*
    { Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
    { Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
    { Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
    { I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
    { F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
    Jika tidak ada elemen dengan nilai = X, menuliskan []
    { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
    1 3 3
    2 5 6
    7 3 9
    maka jika j = 1 dan X = 3, akan tercetak: [0,2]*/
    printf("[");
    indeks i;
    int count = 0;
    for (i=0; i<= GetLastIdxBrs(M); i++){
        if (Elmt(M,i,j)==X){
            if (count == 0){
                printf("%d", i);
            } else {
                printf(",");
                printf("%d",i);
            }
            count = count + 1 ;
        }
    }
    printf("]");
}

void TulisStatistikMhs (MATRIKS M, indeks i){
    /*{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
    { Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
    { Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
    { I.S. M terdefinisi, i adalah indeks baris efektif M }
    { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
    [i] <rata-rata> <nilai max> <nilai min> }
    { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
    100 83 83
    72 55 60
    77 93 90
    maka jika i = 1 akan tercetak:
    [1] 62.33 72 55
    }*/
    int max, min;
    MaxMinBrs(M,i,&max,&min);
    float rata = RataBrs(M,i); 
    printf("[%d] %.2f %d %d", i,rata,max,min);
    printf("\n");
}

void TulisStatistikMK (MATRIKS M, indeks j){
    /*
    { Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
    { Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
    { Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
    { I.S. M terdefinisi, j adalah indeks kolom efektif M }
    { F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
    [j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
    { Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
    100 83 83
    72 55 60
    77 93 90
    maka jika j = 1 akan tercetak:
    [1] 77.00 [93 1 [2]] [55 1 [1]]
    }*/
    int max, min;
    MaxMinKol(M,j,&max,&min);
    float rata = RataKol(M,j);
    int CountMax = CountXKol(M,j,max); 
    int CountMin = CountXKol(M,j,min);
    printf("[%d] %.2f [%d %d ", j,rata,max,CountMax);
    TulisNilaiX(M,j,max);
    printf("] [%d %d ",min,CountMin);
    TulisNilaiX(M,j,min);
    printf("]");
    printf("\n");
}


int main() {
    indeks row, col;
    scanf("%d",&row);
    scanf("%d",&col);
    MATRIKS M;
    BacaMATRIKS(&M,row,col);
    printf("STATISTIK PER MAHASISWA\n");
    indeks i,j;
    for(i=0; i<=GetLastIdxBrs(M); i++){
        TulisStatistikMhs(M,i);
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for(j=0; j<=GetLastIdxKol(M); j++){
        TulisStatistikMK(M,j);
    }
    return 0;
}