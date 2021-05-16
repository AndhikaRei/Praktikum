// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 29/09/2020
// Topik : mesinkata.c
/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

// #define NMax 50
// #define BLANK ' '

// typedef struct {
//  char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
//     int Length;
// } Kata;

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
	/* Mengabaikan satu atau beberapa BLANK
  I.S. : CC sembarang 
  F.S. : CC ≠ BLANK atau CC = MARK */
  while (CC==BLANK){
	  ADV();
  }
}


void STARTKATA(){
	/* I.S. : CC sembarang 
	F.S. : EndKata = true, dan CC = MARK; 
		atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
		CC karakter pertama sesudah karakter terakhir kata */
	START();
	IgnoreBlank();
	if (CC== MARK){
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}


void ADVKATA(){
	/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
  F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
		CC adalah karakter pertama dari kata berikutnya, mungkin MARK
		Jika CC = MARK, EndKata = true.		  
  Proses : Akuisisi kata menggunakan procedure SalinKata */
	if (CC == MARK) {
		EndKata = true;
	} else {
		SalinKata();
		IgnoreBlank();
		if (CC == MARK) {
			EndKata = true;
		}
	}
}


void SalinKata(){
	/* Mengakuisisi kata, menyimpan dalam CKata
  I.S. : CC adalah karakter pertama dari kata
  F.S. : CKata berisi kata yang sudah diakuisisi; 
		CC = BLANK atau CC = MARK; 
		CC adalah karakter sesudah karakter terakhir yang diakuisisi.
		Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i ;
	i = 0 ;
	while ((CC!=BLANK) && (CC != MARK) && (i<NMax)){
		CKata.TabKata[i] = CC;
		ADV();
		i = i + 1 ;
	}
	CKata.Length = i ;
}




