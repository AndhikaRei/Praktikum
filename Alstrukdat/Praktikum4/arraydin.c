// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 15/09/2020
// Adt List Dinamis
// Topik : arraydin.c

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel dinamik */
#include "boolean.h"
#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

/*  Kamus Umum */
// #define IdxMin 0
// /* Indeks minimum array */
// #define IdxUndef -1
// /* Indeks tak terdefinisi*/

// /* Definisi elemen dan koleksi objek */
// typedef int IdxType; /* type indeks */
// typedef int ElType;  /* type elemen tabel */
// typedef struct
// {
//   ElType *TI; /* memori tempat penyimpan elemen (container) */
//   int Neff;   /* >=0, banyaknya elemen efektif */
//   int MaxEl;  /* ukuran elemen */
// } TabInt;
// /* Indeks yang digunakan [IdxMin..MaxEl] */
// /* Jika T adalah TabInt, cara deklarasi dan akses: */
// /* Deklarasi : T : TabInt */
// /* Maka cara akses:
//    T.Neff  untuk mengetahui banyaknya elemen
//    T.TI    untuk mengakses seluruh nilai elemen tabel
//    T.TI[i] untuk mengakses elemen ke-i */
// /* Definisi :
//   Tabel kosong: T.Neff = 0
//   Definisi elemen pertama : T.TI[i] dengan i=0
//   Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

// /* ********** SELEKTOR ********** */
// #define Neff(T) (T).Neff
// #define TI(T) (T).TI
// #define Elmt(T, i) (T).TI[(i)]
// #define MaxEl(T) (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
	/* I.S. T sembarang, maxel > 0 */
	/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
	TI(*T) = (int *) malloc (maxel * sizeof(ElType));
	MaxEl(*T) = maxel ;
	Neff(*T) = 0 ;
}


void Dealokasi(TabInt *T){
	/* I.S. T terdefinisi; */
	/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
	free(TI(*T));
	MaxEl(*T) = 0 ;
	Neff(*T) = 0 ;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
	return Neff(T);
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T){
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return MaxEl(T);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T pertama */
	return (IdxMin);
}

IdxType GetLastIdx(TabInt T){
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T terakhir */
	return (Neff(T)-1);
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
	/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
	/* yaitu antara indeks yang terdefinisi utk container*/
	return (i>= IdxMin && i<= MaxEl(T));
}

boolean IsIdxEff(TabInt T, IdxType i){
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
	/* yaitu antara FirstIdx(T)..LastIdx(T) */
	return (i>= GetFirstIdx(T) && i<= GetLastIdx(T));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
	/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
	return (Neff(T)==0);
}

/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
	/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
	return (Neff(T)==MaxElement(T));
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
	/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
	/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
	/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
		IdxMin satu per satu diakhiri enter */
	/*    Jika N = 0; hanya terbentuk T kosong */
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
		Neff(*T) = N ;
	}
}

void TulisIsiTab(TabInt T){
	/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. T boleh kosong */
	/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika tabel kosong : menulis [] */
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


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
	/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
	/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
	/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
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
	Neff(T3) = Neff(T1);
	return (T3);
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
	/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
	boolean same;
	same = true;
	if (Neff(T1) == Neff(T2))
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


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
	/* Jika tidak ada, mengirimkan IdxUndef */
	/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
	/* Skema Searching yang digunakan bebas */
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

boolean SearchB(TabInt T, ElType X){
	/* Search apakah ada elemen tabel T yang bernilai X */
	/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
	/* Skema searching yang digunakan bebas */
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


/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
	/* I.S. Tabel T tidak kosong */
	/* F.S. Max berisi nilai maksimum T;
		Min berisi nilai minimum T */
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


/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
	/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
	/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
	/* Proses : Menyalin isi Tin ke Tout */
	MakeEmpty(Tout, MaxEl(Tin));
	MaxEl(*Tout) = MaxEl(Tin);
	Neff(*Tout) = Neff(Tin);
	int i;
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++){
		Elmt(*Tout,i) = Elmt(Tin,i);
	}
}

ElType SumTab(TabInt T){
	/* Menghasilkan hasil penjumlahan semua elemen T */
	/* Jika T kosong menghasilkan 0 */
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

int CountX(TabInt T, ElType X){
	/* Menghasilkan berapa banyak kemunculan X di T */
	/* Jika T kosong menghasilkan 0 */
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
	/* I.S. T boleh kosong */
	/* F.S. Jika asc = true, T terurut membesar */
	/*      Jika asc = false, T terurut mengecil */
	/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
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


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
	/* Proses: Menambahkan X sebagai elemen terakhir tabel */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/* F.S. X adalah elemen terakhir T yang baru */
	Elmt(*T, GetLastIdx(*T) + 1) = X;
	Neff(*T) = Neff(*T) + 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
	/* Proses : Menghapus elemen terakhir tabel */
	/* I.S. Tabel tidak kosong */
	/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	*X = Elmt(*T, GetLastIdx(*T));
	Neff(*T) = Neff(*T)-1;
	// int* tmparray;
	// int i ;
	// tmparray = (int *) malloc (MaxEl(*T) * sizeof(ElType));
	// for (i = GetFirstIdx(*T); i <= (GetLastIdx(*T)-1); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// TI(*T) = tmparray;
	// Neff(*T) = Neff(*T)-1;
	// free(tmparray);

	// TabInt Temp;
	// MakeEmpty(&Temp, MaxEl(*T));
	// int i ;
	// for (i = GetFirstIdx(*T); i < GetLastIdx(*T); i++){
	// 	Elmt(Temp,i) = Elmt(*T,i);
	// }
	// Neff(Temp) = Neff(*T)-1;
	// *T = Temp;
	// Dealokasi(&Temp);
}


/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
	/* Proses : Menambahkan max element sebanyak num */
	/* I.S. Tabel sudah terdefinisi */
	/* F.S. Ukuran tabel bertambah sebanyak num */

	// int* tmparray;
	// int i ;
	// tmparray = (int *) malloc ((MaxEl(*T)+num) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) + num ;
	// free(tmparray);
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


void ShrinkTab(TabInt *T, int num){
	/* Proses : Mengurangi max element sebanyak num */
	/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
	/* F.S. Ukuran tabel berkurang sebanyak num. */

	// int* tmparray;
	// int i ;
	// tmparray = (int *) malloc ((MaxEl(*T)-num) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) - num ;
	// free(tmparray);

	TabInt tmpArray;
    IdxType i;
    
    CopyTab(*T, &tmpArray);
    Dealokasi(T);
    MakeEmpty(T, MaxElement(tmpArray)-num);
    
    
    for (i=GetFirstIdx(tmpArray); i<= MaxElement(tmpArray)-num-1; i++){
        Elmt(*T,i) = Elmt(tmpArray, i);
    }
    
    Neff(*T) = Neff(tmpArray);
    
    if (MaxEl(*T) < Neff(*T)){
        Neff(*T) = MaxEl(*T);
    }
    Dealokasi(&tmpArray);
    
}


void CompactTab(TabInt *T){
	/* Proses : Mengurangi max element sehingga Neff = MaxEl */
	/* I.S. Tabel tidak kosong */
	/* F.S. Ukuran MaxEl = Neff */

	// int* tmparray;
	// int i, sel ;
	// sel = MaxEl(*T)-Neff(*T);
	// tmparray = (int *) malloc ((MaxEl(*T)-sel) * sizeof(int));
	// for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
	// 	tmparray[i] = Elmt(*T,i);
	// }
	// free(TI(*T));
	// TI(*T) = tmparray;
	// MaxEl(*T) = MaxEl(*T) - sel ;
	// free(tmparray);

	MaxEl(*T) = Neff(*T);

}


