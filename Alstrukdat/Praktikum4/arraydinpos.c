// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 15/09/2020
// Adt List Dinamis

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi III : dengan banyaknya elemen didefinisikan secara implisit,
   memori tabel dinamik */


#include "boolean.h"
#include "arraydinpos.h"
#include <stdlib.h>
#include <stdio.h>

// /*  Kamus Umum */
// #define IdxMin 0
// /* Indeks minimum array */
// #define IdxUndef -1
// /* Indeks tak terdefinisi*/
// #define ValUndef -999
// /* Nilai elemen tak terdefinisi*/

// /* Definisi elemen dan koleksi objek */
// typedef int IdxType; /* type indeks */
// typedef int ElType;  /* type elemen tabel */
// typedef struct
// {
//   ElType *TI; /* memori tempat penyimpan elemen (container) */
//   int MaxEl;  /* ukuran elemen */
// } TabInt;
// /* Indeks yang digunakan [IdxMin..MaxEl-1] */
// /* Jika T adalah TabInt, cara deklarasi dan akses: */
// /* Deklarasi : T : TabInt */
// /* Maka cara akses:
//    T.TI    untuk mengakses seluruh nilai elemen tabel
//    T.TI[i] untuk mengakses elemen ke-i */
// /* Definisi :
//   Tabel kosong: semua elemen bernilai ValUndef
//   Definisi elemen pertama : T.TI[i] dengan i=0
//   Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i terbesar
//                                              sehingga T.TI[i] != ValUndef */

// /* ********** SELEKTOR ********** */
// #define TI(T) (T).TI
// #define Elmt(T, i) (T).TI[(i)]
// #define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
    /* I.S. T sembarang, maxel > 0 */
    /* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
    /* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
    TI(*T) = (int *) malloc (maxel * sizeof(ElType));
	MaxEl(*T) = maxel ;
	int i;
	for (i = IdxMin; i <= maxel-1; i++)
	{
		Elmt(*T, i) = ValUndef;
	}
}


void Dealokasi(TabInt *T){
    /* I.S. T terdefinisi; */
    /* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
    free(TI(*T));
	MaxEl(*T) = 0 ;

}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
    /* Mengirimkan banyaknya elemen efektif tabel */
    /* Mengirimkan nol jika tabel kosong */
    int elmnt = 0;
	int i;
	for (i = IdxMin; i <= MaxEl(T)-1; i++)
	{
		if (Elmt(T, i) != ValUndef)
		{
			elmnt = elmnt + 1;
		}
	}
	return elmnt;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
    return MaxEl(T);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
    return (IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
    return NbElmt(T) - 1;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
    return (i>= IdxMin && i<= MaxEl(T));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
    return (i>= GetFirstIdx(T) && i<= GetLastIdx(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
{
	/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
{
	/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (NbElmt(T) == MaxEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
    int N ;
	scanf("%d", &N);
	while (N<0 || N>MaxElement(*T))
	{
		scanf("%d", &N);
	}
	if (N != 0)
	{
		IdxType i ;
		ElType e;
		for(i=IdxMin ; i <N; i++){
			scanf("%d",&e);
			Elmt(*T,i) = e ;
		}
	}
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
    printf("[");
	if (!IsEmpty(T))
	{
		int i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (i == GetLastIdx(T))
			{
				printf("%d", Elmt(T, i));
			}
			else
			{
				printf("%d,", Elmt(T, i));
			}
		}
	}
	printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
    TabInt T3;
	MakeEmpty(&T3, MaxEl(T1));
	if (plus)
	{
		int i;
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			Elmt(T3, i) = Elmt(T1, i) + Elmt(T2, i);
		}
	}
	else
	{
		int i ;
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			Elmt(T3, i) = Elmt(T1, i) - Elmt(T2, i);
		}
	}
	return (T3);
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
    boolean same;
	same = true;
	if (NbElmt(T1) == NbElmt(T2))
	{
		int i;
		i = GetFirstIdx(T1);
		while (same && i <= GetLastIdx(T1))
		{
			if (Elmt(T1, i) != Elmt(T2, i))
			{
				same = false;
			}
			i = i + 1;
		}
	}
	else
	{
		same = false;
	}
	return same;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
    if (IsEmpty(T))
	{
		return IdxUndef;
	}
	else
	{
		boolean belumditemukan;
		belumditemukan = true;
		int i;
		i = GetFirstIdx(T);
		while (i <= GetLastIdx(T) && belumditemukan)
		{
			if (Elmt(T, i) == X)
			{
				belumditemukan = false;
			}
			else
			{
				i = i + 1;
			}
		}
		if (belumditemukan)
		{
			return (IdxUndef);
		}
		else
		{
			return (i);
		}
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan ValUndef */
/* Menghasilkan indeks tak terdefinisi (ValUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
    if (IsEmpty(T))
	{
		return false;
	}
	else
	{
		boolean belumditemukan;
		belumditemukan = true;
		int i;
		i = GetFirstIdx(T);
		while (i <= GetLastIdx(T) && belumditemukan)
		{
			if (Elmt(T, i) == X)
			{
				belumditemukan = false;
			}
			else
			{
				i = i + 1;
			}
		}
		return (!(belumditemukan));
	}
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
    int MaxT, MinT;
	MaxT = -99999;
	MinT = 99999;
	int i;
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if (Elmt(T, i) >= MaxT)
		{
			MaxT = Elmt(T, i);
		}
		if (Elmt(T, i) <= MinT)
		{
			MinT = Elmt(T, i);
		}
	}
	*Max = MaxT;
	*Min = MinT;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
    MakeEmpty(Tout, MaxEl(Tin));
	MaxEl(*Tout) = MaxEl(Tin);
	int i;
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
		Elmt(*Tout,i) = Elmt(Tin,i);
	}
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
    ElType sum;
	sum = 0;
	if (IsEmpty(T))
	{
		sum = 0;
	}
	else
	{
		int i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			sum = sum + Elmt(T, i);
		}
	}
	return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
    if (IsEmpty(T))
	{
		return 0;
	}
	else
	{
		int count;
		count = 0;
		int i;
		for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			if (Elmt(T, i) == X)
			{
				count = count + 1;
			}
		}
		return count;
	}
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
    if (IsEmpty(T))
	{
		return true;
	}
	else
	{
		boolean genap;
		genap = true;
		int i;
		i = GetFirstIdx(T);

		while (genap && i <= GetLastIdx(T))
		{
			if (Elmt(T, i) % 2 == 1)
			{
				genap = false;
			}
			i = i + 1;
		}
		return genap;
	}
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
    if (IsEmpty(*T))
	{
	}
	else
	{
		if (asc)
		{
			ElType i, j;
			for (i = GetFirstIdx(*T); i <= GetLastIdx(*T) - 1; i++)
			{
				for (j = GetFirstIdx(*T); j <= GetLastIdx(*T) - i - 1; j++)
				{
					if (Elmt(*T, j) > Elmt(*T, j + 1))
					{
						ElType temp = Elmt(*T, j);
						Elmt(*T, j) = Elmt(*T, j + 1);
						Elmt(*T, j + 1) = temp;
					}
				}
			}
		}
		else
		{
			ElType i, j;
			for (i = GetFirstIdx(*T); i <= GetLastIdx(*T) - 1; i++)
			{
				for (j = GetFirstIdx(*T); j <= GetLastIdx(*T) - i - 1; j++)
				{
					if (Elmt(*T, j) < Elmt(*T, j + 1))
					{
						ElType temp = Elmt(*T, j);
						Elmt(*T, j) = Elmt(*T, j + 1);
						Elmt(*T, j + 1) = temp;
					}
				}
			}
		}
	}
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
    Elmt(*T, GetLastIdx(*T) + 1) = X;

}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
    *X = Elmt(*T, GetLastIdx(*T));
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
    TabInt tmpArray;
    IdxType i;

	CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)+num);
    
    for (i=GetFirstIdx(tmpArray); i<= GetLastIdx(tmpArray); i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
    TabInt tmpArray;
    IdxType i;
    
    CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)-num);
    
    for (i=GetFirstIdx(tmpArray); i<= MaxElement(tmpArray)-num-1; i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Dealokasi(&tmpArray);
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
    MaxEl(*T) = NbElmt(*T);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */

