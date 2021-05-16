// Nama : Reihan Andhika Putra
// Nim : 13519043
// 26/11/2020

#include <stdio.h>
#include "bintree.h"

BinTree makemerkle(int nInput){
    int inpt;
    if (nInput == 0) {
		scanf("%d", &inpt);
        return AlokNode(inpt);
	} else {
        BinTree merkletree = AlokNode(0);
        Left(merkletree) = makemerkle(nInput - 1);
        Right(merkletree) = makemerkle(nInput - 1);
        Akar(merkletree) = Info(Left(merkletree)) + Info(Right(merkletree));
        return merkletree;
    }
}

int main (){
    long nInput; long nTest; int inpt; int merklecnt;
    scanf("%ld", &nInput);
    nTest = 1;
    merklecnt = 0;
    if(nInput > 0){
        while (nTest < nInput){
            nTest = nTest *2 ;
            merklecnt = merklecnt +1;
        }
        if (nTest != nInput){
            printf("Jumlah masukan tidak sesuai\n");
        } else {
            BinTree T; 
            T = makemerkle(merklecnt);
		    PrintTree(T, 2);
        }
    } else {
        printf("Jumlah masukan tidak sesuai\n");
    }
    return 0;
}