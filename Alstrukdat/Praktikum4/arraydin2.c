//
//  Nama            : Daru Bagus Dananjaya
//  NIM             : 13519080
//  Tanggal         : 15 September 2020
//  Topik Praktikum : Array Dinamis
//  Deskripsi       :

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */
//
//  Created by Daru Bagus Dananjaya on 15/09/20.
//  Copyright © 2020 Daru Bagus Dananjaya. All rights reserved.
//

#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{
    TI(*T) = (ElType *) malloc (maxel * sizeof(ElType));
    Neff(*T) = 0;
    MaxEl(*T) = maxel;
}
void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free(TI(*T));
    Neff(*T) = 0;
    MaxEl(*T) = 0;
    
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    return Neff(T);
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}
IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return NbElmt(T)+IdxMin-1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i>=IdxMin && i<=MaxEl(T));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i>=IdxMin) && (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (Neff(T)==0);
}
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return Neff(T) == MaxEl(T);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int n;
    IdxType i;
    
    MakeEmpty(T, MaxEl(*T));
    // proses baca banyaknya elemen yang akan dibaca
    scanf("%d", &n);
    while (n < 0 || (n > MaxElement(*T))){
        scanf("%d", &n);
    }
    
    for (i = GetFirstIdx(*T); i < n; i++){
        scanf("%d", &Elmt(*T, i));
    }
    
    Neff(*T)=n;

}
void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    int i;
    
    //karena jika tabel kosong hanya menuliskan "[]" maka tidak diperlukan analisis kasus
        printf("[");
        for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
            //jika merupakan elemen pertama, maka tidak mencetak ","
            if (i != GetFirstIdx(T)){
                printf(",");
            }
            printf("%d", Elmt(T, i));
        }
        printf("]");

}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt Hasil;
    int i;

    MakeEmpty(&Hasil, MaxElement(T1));

    Neff(Hasil) = Neff(T1);
    
    for (i=GetFirstIdx(T1); i<= GetLastIdx(T1); i++){
            if (plus){
                Elmt(Hasil, i) = Elmt(T1, i)+Elmt(T2, i);
            }
            else{
                Elmt(Hasil, i) = Elmt(T1, i)-Elmt(T2, i);
            }
    }
    
    return Hasil;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{
    int i;
    boolean status = true;
    
    if (NbElmt(T1)!=NbElmt(T2)){
        status = false;
    }
    else{
        for (i=GetFirstIdx(T1); i<=GetLastIdx(T1);i++){
            if (Elmt(T1, i) != Elmt(T2, i)){
                status = false;
            }
        }
    }

    return status;

}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
    int i = GetFirstIdx(T);
    IdxType found = IdxUndef;
    boolean status = false;
    
    while (!status && (i <= GetLastIdx(T))){
        if (Elmt(T, i)==X){
            status = true;
            found = i;
        }
        i++;
    }
    
    return found;
}
boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
    int i = GetFirstIdx(T);
    boolean status = false;
    
    while (!status && i <= GetLastIdx(T)){
        if (Elmt(T, i)==X){
            status = true;
        }
        i++;
    }
    
    return status;
}
/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    ElType temp_max = Elmt(T, GetFirstIdx(T));
    ElType temp_min = Elmt(T, GetFirstIdx(T));
    int i;
    
    for (i= GetFirstIdx(T); i<=GetLastIdx(T); i++){
        if (Elmt(T, i) > temp_max){
            temp_max = Elmt(T, i);
        }
        if (Elmt(T, i) < temp_min){
            temp_min = Elmt(T, i);
        }
    }
    
    *Max = temp_max;
    *Min = temp_min;
}
/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{
    IdxType i;
    
    MakeEmpty(Tout, MaxElement(Tin));
    Neff(*Tout) = Neff(Tin);
    
    for (i = GetFirstIdx(Tin); i<= GetLastIdx(Tin); i++){
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
    
}
ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
    int sum = 0;
    int i;
    
    if (!IsEmpty(T)){
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
                sum+=Elmt(T, i);
        }
    }
    
    return sum;
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
    int count = 0;
    int i;
    
    if (!IsEmpty(T)){
        for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++){
            if (Elmt(T, i)==X){
                count+=1;
            }
        }
    }
    
    return count;
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
    int i;
    boolean status = true;
    
    if (!IsEmpty(T)){
        for (i=GetFirstIdx(T); i < NbElmt(T); i++){
            if (Elmt(T, i) % 2 != 0){
                status = false;
            }
        }
    }

    return status;
}
/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int i, j, idx, temp;
    
    if (!(IsEmpty(*T))){
        for (i=GetFirstIdx(*T); i <= (GetLastIdx(*T)-1); i++){
            idx = i;
            for (j = i+1; j <= GetLastIdx(*T); j++){
                if (asc){
                    if (Elmt(*T, j) < Elmt(*T, idx)){
                        idx = j;
                    }
                } else {
                    if (Elmt(*T, j) > Elmt(*T, idx)){
                        idx = j;
                    }
                }
            }
            
            temp = Elmt(*T, idx);
            Elmt(*T, idx) = Elmt(*T, i);
            Elmt(*T, i) = temp;
        }
    }
}/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    Neff(*T)+=1;
    Elmt(*T, (GetLastIdx(*T))) = X;
}
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T)-=1;
}
/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
    TabInt tmpArray;
    IdxType i;
    
    CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)+num);
    
    for (i=GetFirstIdx(tmpArray); i<= GetLastIdx(tmpArray); i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Neff(*T) = Neff(tmpArray);
}
void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
    TabInt tmpArray;
    IdxType i;
    
    CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)-num);
    
    for (i=GetFirstIdx(tmpArray); i<= GetLastIdx(tmpArray); i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Neff(*T) = Neff(tmpArray);
    
}
void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
    MaxEl(*T) = Neff(*T);
}
