// Nama : Reihan Andhika Putra
//  Nim : 13519043
//  Tanggal : 22/10/2020
//  Topik : Backspace.c
// Diberikan dua buah sequence A dan B yang merepresentasikan urutan pengetikan karakter pada layar. 
// Sequence terdiri dari angka 1-9 dan angka 0 yang merepresentasikan backspace (penghapusan satu karakter). 
// Tentukan apakah A dan B menghasilkan sequence yang sama jika diketikkan ke layar.

#include <stdio.h>
#include "stackt.h"

int main()
{

	int n, m, i, opA, opB;
	Stack A, B;
	CreateEmpty(&A);
	CreateEmpty(&B);
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		scanf("%d", &opA);
		if (opA != 0) {
			Push(&A, opA);
		} else if (opA ==0) {
			if (!IsEmpty(A)) {
				Pop(&A, &opA);
			}
		}
	}

	for (i = 0; i < m; i++) {
		scanf("%d", &opB);
		if (opB != 0) {
			Push(&B, opB);
		} else if (opB == 0) {
			if (!IsEmpty(B)) {
				Pop(&B, &opB);
			}
		}
	}

	boolean same = true;
	while (same && (!IsEmpty(A) || !IsEmpty(B))) {
		Pop(&A, &opA);
		Pop(&B, &opB);
		if ((opA != opB)){
			same = false;
		}
	}
	if ((IsEmpty(A) && !IsEmpty(B))) {
		same = false;
	} else if((!IsEmpty(A) && IsEmpty(B))){
		same = false;	
	}

	if (same) {
		printf("Sama\n");
	} else {
		printf("Tidak sama\n");
	}

	return 0;
}