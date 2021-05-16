// Nama : Reihan Andhika P
// Nim : 13519043
//  26/11/2020
#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

void InvertBtree(BinTree *P){
    /* I.S. Pohon P terdefinisi */
    /* F.S. Pohon P diflip secara vertikal */
    /*      Contoh:
            1
            2   5
            3 4 6
            Menjadi:
            1
            5   2
            6 4 3 */
    if (IsBiner(*P)) {
		BinTree trash;
        trash = Right(*P);
        Right(*P) = Left(*P);
        Left(*P) = trash;
		InvertBtree(&Left(*P));
		InvertBtree(&Right(*P));
	} else if (IsUnerRight(*P)) {
		Left(*P) = Right(*P);
		Right(*P) = Nil;
		InvertBtree(&Left(*P));
    } else if (IsUnerLeft(*P)) {
		Right(*P) = Left(*P);
		Left(*P) = Nil;
		InvertBtree(&Right(*P));
    }
}
