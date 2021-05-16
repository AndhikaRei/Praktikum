// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 29/09/2020
// Topik : mesintoken.c
/* File: mesintoken.h */
/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */


#include "mesintoken.h"


/* State Mesin Kata */
boolean EndToken;
Token CToken;

void IgnoreBlank(){
    /* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
    while (CC==BLANK){
	  ADV();
  }
}


void STARTTOKEN(){
    /* I.S. : CC sembarang 
    F.S. : EndToken = true, dan CC = MARK; 
    atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
    CC karakter pertama sesudah karakter terakhir Token */
    START();
	IgnoreBlank();
	if (CC== MARK){
		EndToken = true;
	} else {
		EndToken = false;
		SalinToken();
	}
}


void ADVTOKEN(){
    /* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
    F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
    CC adalah karakter pertama dari kata berikutnya, mungkin MARK
    Jika CC = MARK, maka EndToken = true		  
    Proses : Akuisisi kata menggunakan procedure SalinKata */
    IgnoreBlank();
    if (CC == MARK) {
		EndToken = true;
	} else {
		SalinToken();
		IgnoreBlank();
	}

}


void SalinToken(){
    /* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
    I.S. : CC adalah karakter pertama dari Token
    F.S. : CToken berisi Token yang sudah diakuisisi; 
    CC = BLANK atau CC = MARK; 
    CC adalah karakter sesudah karakter terakhir yang diakuisisi.
    Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    CToken.val = 0;
    while ((i<NMax) && (CC!=MARK) && (CC!=BLANK)){
        if ((CC!='+') && (CC != '-') && (CC != '*') && (CC != '/') && (CC != '^')){
            if (CC == '1'){
                CToken.val = CToken.val * 10 + 1;
            } else if (CC == '2'){
                CToken.val = CToken.val * 10 + 2;
            } else if (CC == '3'){
                CToken.val = CToken.val * 10 + 3;
            } else if (CC == '4'){
                CToken.val = CToken.val * 10 + 4;
            } else if (CC == '5'){
                CToken.val = CToken.val * 10 + 5;
            } else if (CC == '6'){
                CToken.val = CToken.val * 10 + 6;
            } else if (CC == '7'){
                CToken.val = CToken.val * 10 + 7;
            } else if (CC == '8'){
                CToken.val = CToken.val * 10 + 8;
            } else if (CC == '9'){
                CToken.val = CToken.val * 10 + 9;
            } else {
                CToken.val = CToken.val * 10 + 0;
            }
            CToken.tkn = 'b';
        }
        else{
            CToken.tkn = CC;
            CToken.val = -1;
        }
        ADV();
        i++;
    }
}



