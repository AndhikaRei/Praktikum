// 	Nama : Reihan Andhika Putra
//  Nim : 13519043
//  Tanggal : 09/09/2020
//  Topik : ADT array

/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */

#include "boolean.h"
#include "arraypos.h"
#include <stdio.h>

/*  Kamus Umum */
// #define IdxMax 99
// #define IdxMin 0
// #define IdxUndef -999
// #define ValUndef -1
// typedef int IdxType;  /* type indeks */
// typedef int ElType;   /* type elemen tabel */
// typedef struct {
//   ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
// } TabInt;
// #define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T)
{
	/* I.S. T sembarang */
	/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
	/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
	int i;
	for (i = IdxMin; i <= IdxMax; i++)
	{
		Elmt(*T, i) = ValUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
	/* Mengirimkan banyaknya elemen efektif tabel */
	/* Mengirimkan nol jika tabel kosong */
	int elmnt = 0;
	int i;
	for (i = IdxMin; i <= IdxMax; i++)
	{
		if (Elmt(T, i) != ValUndef)
		{
			elmnt = elmnt + 1;
		}
	}
	return elmnt;
}

/* *** Daya tampung container *** */
int MaxNbEl(TabInt T)
{
	/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
	return (IdxMax + 1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
{
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T pertama */
	return IdxMin;
}

IdxType GetLastIdx(TabInt T)
{
	/* Prekondisi : Tabel T tidak kosong */
	/* Mengirimkan indeks elemen T terakhir */
	return NbElmt(T) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
	/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
	/* yaitu antara indeks yang terdefinisi utk container*/
	return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i)
{
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
	/* yaitu antara FirstIdx(T)..LastIdx(T) */
	return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

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
	return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
{
	/* I.S. T sembarang */
	/* F.S. Tabel T terdefinisi */
	/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
	/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
	/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
		IdxMin satu per satu diakhiri enter */
	/*    Jika N = 0; hanya terbentuk T kosong */
	int N;
	scanf("%d", &N);
	while (N < 0 || N > MaxNbEl(*T))
	{
		scanf("%d", &N);
	}
	if (N == 0)
	{
		MakeEmpty(T);
	}
	else
	{
		MakeEmpty(T);
		int i;
		for (i = IdxMin; i < N; i++)
		{
			int n;
			scanf("%d", &n);
			Elmt(*T, i) = n;
		}
	}
}

void TulisIsiTab(TabInt T)
{
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
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
{
	/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
	/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
	/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
	TabInt T3;
	MakeEmpty(&T3);
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

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
{
	/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
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

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
{
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

boolean SearchB(TabInt T, ElType X)
{
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
void MaxMin(TabInt T, ElType *Max, ElType *Min)
{
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
ElType SumTab(TabInt T)
{
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

int CountX(TabInt T, ElType X)
{
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

boolean IsAllGenap(TabInt T)
{
	/* Menghailkan true jika semua elemen T genap */
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

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
{
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
void AddAsLastEl(TabInt *T, ElType X)
{
	/* Proses: Menambahkan X sebagai elemen terakhir tabel */
	/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
	/* F.S. X adalah elemen terakhir T yang baru */
	Elmt(*T, GetLastIdx(*T) + 1) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
{
	/* Proses : Menghapus elemen terakhir tabel */
	/* I.S. Tabel tidak kosong */
	/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
	/*      Banyaknya elemen tabel berkurang satu */
	/*      Tabel T mungkin menjadi kosong */
	*X = Elmt(*T, GetLastIdx(*T));
	Elmt(*T, GetLastIdx(*T)) = ValUndef;
}
