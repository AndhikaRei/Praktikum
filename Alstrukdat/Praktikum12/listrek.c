// Nama : Reihan Andhika Putra
// Nim : 13519043
// 17/11/2020
/* File: listrek.h */
/* ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listrek.h"

// #define Nil NULL
// /* Definisi Type */
// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;

// /* Definisi list : */
// /* List kosong : L = Nil */
// typedef address List;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

// /* Selektor */
// #define Info(P) (P)->info
// #define Next(P) (P)->next

/* *** Manajemen Memori *** */
address Alokasi (infotype X){
	/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    return Nil;
}

void Dealokasi (address P){
	/* I.S. P terdefinisi */
	/* F.S. P dikembalikan ke sistem */
	/* Melakukan dealokasi/pengembalian address P */
	free(P);
}


/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
	/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
	return (L == Nil);
}

int IsOneElmt(List L){
	/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
	if (IsEmpty(L)) {
		return 0;
	} else if (Next(L) == Nil) {
		return 1;
	} else {
		return 0;
	}
}



/* *** Selektor *** */
infotype FirstElmt (List L){
	/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
	return Info(L);
}

List Tail(List L){
	/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
	return(Next(L));
}

/* *** Konstruktor *** */
List Konso(infotype e, List L){
	/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
	e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
	address P;
	P = Alokasi(e);
	if (P != Nil){
		Next(P) = L;
		return P ;
	} else {
		return L;
	}
}

List KonsB(List L, infotype e){
	/* Mengirimkan list L dengan tambahan e sebagai elemen terakhirnya */
	/* e harus dialokasi terlebih dahulu */
	/* Jika alokasi e gagal, mengirimkan L */ 
	address P;
	P = Alokasi(e);
	if (P != Nil){ 
		if(IsEmpty(L)) {
			return P;
		} else {
			Next(L) = KonsB(Tail(L), e);
        	return L;
		}
	} else {
		return L;
	}
}


/* *** Operasi Lain *** */
List Copy (List L){
	/* Mengirimkan salinan list L (menjadi list baru) */
	/* Jika ada alokasi gagal, mengirimkan L */ 
	if (IsEmpty(L)) {
		return Nil;
	} else {
		return Konso(FirstElmt(L),Copy(Tail(L)));
	}
}

void MCopy (List Lin, List *Lout){
	/* I.S. Lin terdefinisi */
	/* F.S. Lout berisi salinan dari Lin */
	/* Proses : menyalin Lin ke Lout */
	List Lout2;
	if (IsEmpty(Lin)) {
		*Lout = Nil;
	} else {
		MCopy(Tail(Lin), &Lout2);
		*Lout = Konso(FirstElmt(Lin), Lout2);
	}
}

List Concat (List L1, List L2){
	/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
	/* Jika ada alokasi gagal, menghasilkan Nil */
	List L3;
	if (IsEmpty(L1)){
		return Copy(L2);
	} else {
		return Konso(FirstElmt(L1), Concat(Tail(L1), L2));
	}
}

void MConcat (List L1, List L2, List *LHsl){
	/* I.S. L1, L2 terdefinisi */
	/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
	/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
	if (IsEmpty(L1)) {
		*LHsl = Copy(L2);
	} else {
		*LHsl = Concat(L1,L2);
	}
}

void PrintList (List L){
	/* I.S. L terdefinisi. */
	/* F.S. Setiap elemen list dicetak. */
	if (!IsEmpty(L)) {
        printf("%d\n", FirstElmt(L));
        PrintList(Tail(L));
    }
}

int NbElmtList (List L){
	/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
	if (IsEmpty(L)) {
		return 0 ;
	} else {
		return 1 + NbElmtList(Tail(L)); 
	}
}

boolean Search (List L, infotype X){
	/* Mengirim true jika X adalah anggota list, false jika tidak */
	if (IsEmpty(L)){
		return false;
	} else {
		if ((FirstElmt(L))==X){
			return true;
		} else {
			return Search(Tail(L),X);
		}
	}
}

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L){
	/* Mengirimkan nilai info(P) yang maksimum */
	if (IsOneElmt(L)){
		return FirstElmt(L);
	} else {
		if (FirstElmt(L) > MaxList(Tail(L))){
			return FirstElmt(L);
		} else {
			return MaxList(Tail(L));
		}
	}
}


infotype MinList (List L){
	/* Mengirimkan nilai info(P) yang minimum */
	if (IsOneElmt(L)){
		return FirstElmt(L);
	} else {
		if (FirstElmt(L) < MinList(Tail(L))){
			return FirstElmt(L);
		} else {
			return MinList(Tail(L));
		}
	}
}


infotype SumList (List L){
	/* Mengirimkan total jumlah elemen List L */
	if (IsEmpty(L)){
        return 0;
	} else {
        return FirstElmt(L) + SumList(Tail(L));
    }
}


float AverageList (List L){
	/* Mengirimkan nilai rata-rata elemen list L */
	return ((float) SumList(L)/NbElmtList(L));
}


/*** Operasi-Operasi Lain ***/
List InverseList (List L){
	/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
	Semua elemen list baru harus dialokasi */
	/* Jika alokasi gagal, hasilnya list kosong */
	if (IsEmpty(L)) {
		return Nil;
	} else {
        return KonsB(InverseList(Tail(L)), FirstElmt(L));
	}
}


void SplitPosNeg (List L, List *L1, List *L2){
	/* I.S. L mungkin kosong */
	/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
	/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
	semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
	/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
	/* Jika L kosong, maka L1 dan L2 kosong */
	List Ltemp1, Ltemp2;
	if (IsEmpty(L)){
		*L1 = Nil;
		*L2 = Nil;
	} else {
		SplitPosNeg(Tail(L), &Ltemp1, &Ltemp2);
        if (FirstElmt(L) >= 0) {
            *L1 = Konso(FirstElmt(L), Ltemp1);
            *L2 = Ltemp2;
        } else {
            *L2 = Konso(FirstElmt(L), Ltemp2);
            *L1 = Ltemp1;
        }
    }
}



void SplitOnX (List L, infotype X, List *L1, List *L2){
	/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
	/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
	kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
	L1, dengan urutan kemunculan yang sama. */
	List Ltemp1, Ltemp2;
	if (IsEmpty(L)){
		*L1 = Nil;
		*L2 = Nil;
	} else {
		SplitOnX(Tail(L),X, &Ltemp1, &Ltemp2);
        if (FirstElmt(L) < X) {
            *L1 = Konso(FirstElmt(L), Ltemp1);
            *L2 = Ltemp2;
        } else {
            *L2 = Konso(FirstElmt(L), Ltemp2);
            *L1 = Ltemp1;
        }
    }
}


int ListCompare (List L1, List L2){
	/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
	/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
	/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
	/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
	dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
	urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
	/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
	/* L1>L2: kebalikan dari L1<L2 */
	if (IsEmpty(L1) && IsEmpty(L2)){
		return 0;
	} else if (IsEmpty(L1) && !IsEmpty(L2)) {
		return -1;
	} else if (!IsEmpty(L1) && IsEmpty(L2)) {
		return 1;
	} else if (FirstElmt(L1) > FirstElmt(L2)) {
            return 1;
	} else if (FirstElmt(L1) < FirstElmt(L2)) {
        return -1;
	} else {
        return ListCompare(Tail(L1), Tail(L2));
	}
}

boolean IsAllExist (List L1, List L2){
	/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
	memperhatikan urutan ataupun banyaknya elemen).
	Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
	if (IsEmpty(L1)) {
        return false;
	} else if (IsOneElmt(L1)) {
        return Search(L2, FirstElmt(L1));
	} else {
        return (IsAllExist(Tail(L1), (L2)) && Search(L2, FirstElmt(L1)));
	}
}



