// Nama : Reihan Andhika Putra
// Nim : 13519043
// 05/11/2022

// Cache dapat direpresentasikan sebagai sebuah list linier. Cache akan diinisialisasi dengan nilai 1 sampai N. Lalu, akan ada Q buah operasi pengambilan nilai x:
// Jika x ada di cache, nilai x dipindah ke depan cache.
// Jika x tidak ada di cache, nilai paling akhir dihapus dari cache dan x dimasukkan ke depan cache.
// Untuk setiap operasi, tuliskan apakah operasi "hit" atau "miss". Lalu, tuliskan isi list.

#include "listlinier.h"
#include <stdio.h>

int main()
{
	int N, x;
	List L;
	address P;
	scanf("%d", &N);
	CreateEmpty(&L);
	for (int i = 1; i <= N; ++i) {
		P = Alokasi(i);
		InsertLast(&L, P);
	}

	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		scanf("%d", &x);
		P = Search(L, x);
        // Jika tidak ditemukan
		if (P == Nil) {
            DelLast(&L, &P);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("miss ");
			PrintInfo(L);
			printf("\n");
            // Jika ditemukan
		} else {
			DelP(&L, x);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("hit ");
			PrintInfo(L);
			printf("\n");
		}
	}
    return 0;
}