// Nama : Reihan Andhika Putra
// Nim : 13519043
// 19/11/2020
#include "listrek.h"
#include <stdlib.h>

int total = 0;
List simpan = Nil;
int Apa(List L, int nbelmt, int n){
	if(IsEmpty(L)) return 1; //basis
	total++; // buat ngitung panjang listnya, masukin ke variabel global
	Apa(Tail(L), nbelmt+1, n); // nbelmt biar tau skrg rekursif di elemen ke brp
	// nah kan mau delete elemen ke-n dari belakang, idenya sebelum ngedelete disimpen dulu node setelahnya
	if(n+nbelmt-1 == total) simpan = L; // node ke n+1 disimpen
	if(n+nbelmt == total)  {Dealokasi(L);if(nbelmt == 0) return 0;} // node ke-n didelete
	if(n+nbelmt+1 == total) SetNext(L, simpan); // node ke n-1 disambungin sama yg tadi disimpen
	// ada pengecualian, kalo n == panjang list,
	// artinya dia mau ngedelete elemen pertama
	// artinya elemen ke n-1 ga ada kan, masuk ke kasus di baris 24
}

List delNFromEnd(List L, int n) {
	if(IsEmpty(L)) return L;
	if(!Apa(L, 0, n)) return simpan;
	return L;
}
