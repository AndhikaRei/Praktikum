// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 10/09/2020
// Topik : marraypos.c
// Deskripsi : Membuat program yang memanfaatkan adt array dan mengecek nilai x adalah maks min atau median

#include "arraypos.h"
#include <stdio.h>
#include "boolean.h"


int main() {
    TabInt T;
    int X,imed;
    ElType Max, Min;
    BacaIsi(&T);
    TulisIsiTab(T);
    printf("\n");
    scanf("%d", &X);
    if (SearchB(T,X)) {
        printf("%d\n", Search1(T,X));
        MaxMin(T,&Max,&Min);
        if (X==Max){
            printf("maksimum\n");
        }
        if (X==Min){
            printf("minimum\n");
        }
        Sort(&T,true);
        if (NbElmt(T)%2 == 1) {
            imed = NbElmt(T)/2;
        } else {
            imed = (NbElmt(T)/2)-1;
        }
        if (X==Elmt(T,imed)){
            printf("median\n");
        }
    } 
    else
    {
        printf("%d tidak ada\n",X );
    }
    
    return 0;
}