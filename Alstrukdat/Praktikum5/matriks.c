// Nama : Reihan Andhika P
// Nim : 13519043
//  Tanggal : 24/09/2020
//  Topik : Matriks.c
//  Deskripsi : Ambillah ADT Matriks yang sudah Anda buat pada tugas pra-praktikum sebelumnya dan tambahkan beberapa primitif berkaitan dengan operasi berbasis baris dan kolom matriks sebagai berikut:
/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <math.h>

/* Ukuran minimum dan maksimum baris dan kolom */
// #define BrsMin 0
// #define BrsMax 99
// #define KolMin 0
// #define KolMax 99

// typedef int indeks; /* indeks baris, kolom */
// typedef int ElType;
// typedef struct {
// 	ElType Mem[BrsMax+1][KolMax+1];
//     int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
// 	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
// } MATRIKS;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS(int NB, int NK, MATRIKS *M)
{
	/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
	/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
	/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor *** */
// #define NBrsEff(M) (M).NBrsEff
// #define NKolEff(M) (M).NKolEff
// #define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid(int i, int j)
{
	/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
	return (i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs(MATRIKS M)
{
	/* Mengirimkan indeks baris terkecil M */
	return BrsMin;
}

indeks GetFirstIdxKol(MATRIKS M)
{
	/* Mengirimkan indeks kolom terkecil M */
	return KolMin;
}

indeks GetLastIdxBrs(MATRIKS M)
{
	/* Mengirimkan indeks baris terbesar M */
	return NBrsEff(M) - 1;
}

indeks GetLastIdxKol(MATRIKS M)
{
	/* Mengirimkan indeks kolom terbesar M */
	return NKolEff(M) - 1;
}
boolean IsIdxEff(MATRIKS M, indeks i, indeks j)
{
	return (i >= BrsMin && i <= GetLastIdxBrs(M)) && (j >= KolMin && j <= GetLastIdxKol(M));
	/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
}

ElType GetElmtDiagonal(MATRIKS M, indeks i)
{
	/* Mengirimkan elemen M(i,i) */
	return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS(MATRIKS MIn, MATRIKS *MHsl)
{
	/* Melakukan assignment MHsl  MIn */
	*MHsl = MIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS(MATRIKS *M, int NB, int NK)
{
	/* I.S. IsIdxValid(NB,NK) */
	/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
	/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
	/* Selanjutnya membaca nilai elemen per baris dan kolom */
	/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
	1 2 3
	4 5 6
	8 9 10 
	*/
	MakeMATRIKS(NB, NK, M);
	indeks i, j;
	for (i = 0; i < NB; i++)
	{
		for (j = 0; j < NK; j++)
		{
			ElType N;
			scanf("%d", &N);
			Elmt(*M, i, j) = N;
		}
	}
}

void TulisMATRIKS(MATRIKS M)
{
	/* I.S. M terdefinisi */
	/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
		dipisahkan sebuah spasi */
	/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
	/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
	1 2 3
	4 5 6
	8 9 10
	*/
	for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M); j++)
		{
			if (j == GetLastIdxKol(M) && i == GetLastIdxBrs(M))
			{
				printf("%d", Elmt(M, i, j));
			}
			else if (j == GetLastIdxKol(M))
			{
				printf("%d\n", Elmt(M, i, j));
			}
			else
			{
				printf("%d ", Elmt(M, i, j));
			}
		}
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS(MATRIKS M1, MATRIKS M2)
{
	/* Prekondisi : M1  berukuran sama dengan M2 */
	/* Mengirim hasil penjumlahan matriks: M1 + M2 */
	MATRIKS M3;
	NBrsEff(M3) = NBrsEff(M1);
	NKolEff(M3) = NKolEff(M1);
	for (indeks i = 0; i <= GetLastIdxBrs(M2); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M1); j++)
		{
			Elmt(M3, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
		}
	}
	return M3;
}

MATRIKS KurangMATRIKS(MATRIKS M1, MATRIKS M2)
{
	/* Prekondisi : M berukuran sama dengan M */
	/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
	MATRIKS M3;
	NBrsEff(M3) = NBrsEff(M1);
	NKolEff(M3) = NKolEff(M1);
	for (indeks i = 0; i <= GetLastIdxBrs(M2); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M1); j++)
		{
			Elmt(M3, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
		}
	}
	return M3;
}

MATRIKS KaliMATRIKS(MATRIKS M1, MATRIKS M2)
{
	/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
	/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
	MATRIKS Mnew;
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &Mnew);
	indeks i, j, x;

	for (i = 0; i <= GetLastIdxBrs(Mnew); i++)
	{
		for (j = 0; j <= GetLastIdxKol(Mnew); j++)
		{
			ElType tmp = 0;
			for (x = 0; x <= GetLastIdxKol(M1); x++)
			{
				tmp += (Elmt(M1, i, x) * Elmt(M2, x, j));
			}
			Elmt(Mnew, i, j) = tmp;
		}
	}

	return Mnew;
}

MATRIKS KaliKons(MATRIKS M, ElType X)
{
	/* Mengirim hasil perkalian setiap elemen M dengan X */
	MATRIKS M3;
	NBrsEff(M3) = NBrsEff(M);
	NKolEff(M3) = NKolEff(M);
	for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M); j++)
		{
			Elmt(M3, i, j) = Elmt(M, i, j) * X;
		}
	}
	return M3;
}

void PKaliKons(MATRIKS *M, ElType K)
{
	/* I.S. M terdefinisi, K terdefinisi */
	/* F.S. Mengalikan setiap elemen M dengan K */
	for (indeks i = 0; i <= GetLastIdxBrs(*M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(*M); j++)
		{
			Elmt(*M, i, j) = Elmt(*M, i, j) * K;
		}
	}
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ(MATRIKS M1, MATRIKS M2)
{
	/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
	/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
	/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
		dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
	if (NBElmt(M1) != NBElmt(M2))
	{
		return false;
	}
	else if ((GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) || (GetLastIdxKol(M1) != GetLastIdxKol(M2)))
	{
		return false;
	}
	else
	{
		for (indeks i = 0; i <= GetLastIdxBrs(M2); i++)
		{
			for (indeks j = 0; j <= GetLastIdxKol(M1); j++)
			{
				if (Elmt(M1, i, j) != Elmt(M2, i, j))
				{
					return false;
				}
			}
		}
	}
	return true;
}

boolean NEQ(MATRIKS M1, MATRIKS M2)
{
	/* Mengirimkan true jika M1 tidak sama dengan M2 */
	return !(EQ(M1, M2));
}

boolean EQSize(MATRIKS M1, MATRIKS M2)
{
	/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
	/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}

/* ********** Operasi lain ********** */
int NBElmt(MATRIKS M)
{
	/* Mengirimkan banyaknya elemen M */
	return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar(MATRIKS M)
{
	/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
	return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri(MATRIKS M)
{
	/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
	dan untuk setiap elemen M, M(i,j)=M(j,i) */
	if (!IsBujurSangkar(M))
	{
		return false;
	}
	else
	{
		for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
		{
			for (indeks j = 0; j <= GetLastIdxKol(M); j++)
			{
				if (Elmt(M, i, j) != Elmt(M, j, i))
				{
					return false;
				}
			}
		}
	}
	return true;
}

boolean IsSatuan(MATRIKS M)
{
	/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
	setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
	if (!IsBujurSangkar(M))
	{
		return false;
	}
	else
	{
		for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
		{
			for (indeks j = 0; j <= GetLastIdxKol(M); j++)
			{
				if (i == j && (Elmt(M, i, j) != 1))
				{
					return false;
				}
				else if (i != j && (Elmt(M, i, j) != 0))
				{
					return false;
				}
			}
		}
	}
	return true;
}

boolean IsSparse(MATRIKS M)
{
	/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
	hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
	int NotZero = 0;
	for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M); j++)
		{
			if ((Elmt(M, i, j) != 0))
			{
				NotZero = NotZero + 1;
			}
		}
	}
	float percentage = (float)NotZero / NBElmt(M);
	return (percentage <= 0.05);
}

MATRIKS Inverse1(MATRIKS M)
{
	/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	MATRIKS M3;
	NBrsEff(M3) = NBrsEff(M);
	NKolEff(M3) = NKolEff(M);
	for (indeks i = 0; i <= GetLastIdxBrs(M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(M); j++)
		{
			Elmt(M3, i, j) = Elmt(M, i, j) * -1;
		}
	}
	return M3;
}

float Determinan(MATRIKS M)
{
	/* Prekondisi: IsBujurSangkar(M) */
	/* Menghitung nilai determinan M */
	if (NBElmt(M) == 1)
	{
		float de = (float)Elmt(M, 0, 0);
		return de;
	}
	else
	{
		MATRIKS Minor;
		MakeMATRIKS((NBrsEff(M) - 1), (NBrsEff(M) - 1), &Minor);
		int i, j, k, c1, c2;
		int determinant;
		int O = 1;

		determinant = 0;
		if (NBrsEff(M) == 2)
		{

			determinant = Elmt(M, 0, 0) * Elmt(M, 1, 1) - Elmt(M, 0, 1) * Elmt(M, 1, 0);
			return determinant;
		}
		else
		{
			for (i = 0; i < NBrsEff(M); i++)
			{
				c1 = 0, c2 = 0;
				for (j = 0; j < NBrsEff(M); j++)
				{
					for (k = 0; k < NBrsEff(M); k++)
					{
						if (j != 0 && k != i)
						{
							Elmt(Minor, c1, c2) = Elmt(M, j, k);
							c2++;
							if (c2 > NBrsEff(M) - 2)
							{
								c1++;
								c2 = 0;
							}
						}
					}
				}
				determinant = determinant + O * (Elmt(M, 0, i) * Determinan(Minor));
				O = -1 * O;
			}
		}
		return determinant;
		// float detT= 0;
		// for(int i = 0; i <= GetLastIdxBrs(M); i++){
		// 	MATRIKS M2;
		// 	MakeMATRIKS((NBrsEff(M)-1), (NBrsEff(M)-1), &M2);
		// 	indeks l = 0;
		// 	indeks m = 0;
		// 	for(indeks j = 0; i <= GetLastIdxBrs(M); i++){
		// 		for (indeks k = 0; j <= GetLastIdxKol(M); j++){
		// 			if ( k!=i && j!=0  ){
		// 				Elmt(M2,l,m)= Elmt(M,i,j);
		// 				m = m+1;
		// 				if (m>GetLastIdxKol(M2)){
		// 					m = 0;
		// 					l = l+1;
		// 				}
		// 			}
		// 		}
		// 	}
		// 	detT = detT+ Elmt(M,0,i)*Determinan(M2)*pow(-1.0,2+i);
		// 	return detT;
		// }
		// return detT;
	}
}

void PInverse1(MATRIKS *M)
{
	/* I.S. M terdefinisi */
	/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	for (indeks i = 0; i <= GetLastIdxBrs(*M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(*M); j++)
		{
			Elmt(*M, i, j) = Elmt(*M, i, j) * -1;
		}
	}
}

void Transpose(MATRIKS *M)
{
	/* I.S. M terdefinisi dan IsBujursangkar(M) */
	/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
	MATRIKS M3;
	NBrsEff(M3) = NBrsEff(*M);
	NKolEff(M3) = NKolEff(*M);
	for (indeks i = 0; i <= GetLastIdxBrs(*M); i++)
	{
		for (indeks j = 0; j <= GetLastIdxKol(*M); j++)
		{
			Elmt(M3, i, j) = Elmt(*M, j, i);
		}
	}
	*M = M3;
}

float RataBrs (MATRIKS M, indeks i){
	/* Menghasilkan rata-rata dari elemen pada baris ke-i */
	/* Prekondisi: i adalah indeks baris efektif dari M */
	float sum;
	indeks j;
	sum = 0;
	for (j = 0; j <= GetLastIdxKol(M); j++){
		sum = sum + Elmt(M,i,j);
	}
	sum = (float) sum/M.NKolEff;
	return sum;
}

float RataKol (MATRIKS M, indeks j){
	/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
	/* Prekondisi: j adalah indeks kolom efektif dari M */
	float sum;
	indeks i;
	sum = 0;
	for (i = 0; i <= GetLastIdxBrs(M); i++){
		sum = sum + Elmt(M,i,j);
	}
	sum = (float) sum/M.NBrsEff;
	return sum;
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min){
	/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
	/* F.S. max berisi elemen maksimum pada baris i dari M
		min berisi elemen minimum pada baris i dari M */
	ElType maxtmp,mintmp;
	maxtmp = -999999 ;
	mintmp = 999999 ;

	indeks j;
	for (j = 0; j <= GetLastIdxKol(M); j++){
		if (Elmt(M,i,j) >= maxtmp) {
			maxtmp = Elmt(M,i,j);
		};
		if (Elmt(M,i,j) <= mintmp){
			mintmp = Elmt(M,i,j);
		}
	}
	*max = maxtmp;
	*min = mintmp;
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min){
	/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
	/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
	ElType maxtmp,mintmp;
	maxtmp = -999999 ;
	mintmp = 999999 ;

	indeks i;
	for (i = 0; i <= GetLastIdxBrs(M); i++){
		if (Elmt(M,i,j) >= maxtmp) {
			maxtmp = Elmt(M,i,j);
		};
		if (Elmt(M,i,j) <= mintmp){
			mintmp = Elmt(M,i,j);
		}
	}
	*max = maxtmp;
	*min = mintmp;
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
	/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
	int sum ;
	sum = 0;
	indeks j;
	for (j = 0; j <= GetLastIdxKol(M); j++){
		if (Elmt(M,i,j) == X) {
			sum = sum +1 ;
		};
	}
	return sum;
}

int CountXKol (MATRIKS M, indeks j, ElType X){
	/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
	int sum ;
	sum = 0;
	indeks i;
	for (i = 0; i <= GetLastIdxBrs(M); i++){
		if (Elmt(M,i,j) == X) {
			sum = sum +1 ;
		};
	}
	return sum;
}


