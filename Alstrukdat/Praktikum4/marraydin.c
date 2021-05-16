#include "boolean.h"
#include "arraydin.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    IdxType MaxEl;
    TabInt T ;
    ElType num;
    int Q, op;
    scanf("%d",&MaxEl);
    MakeEmpty(&T,MaxEl);
    BacaIsi(&T);
    scanf("%d",&Q);
    for (int i=1;i<=Q; i++){
        scanf("%d",&op);
        if (op==1) {
            scanf("%d",&num);
            if(IsFull(T)) {
                printf("array sudah penuh\n");
            } else {
                AddAsLastEl(&T,num);
                printf("%d ",MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            }
        } else if (op==2) {
            scanf("%d",&num);
            GrowTab(&T,num);
            printf("%d ",MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        } else if (op==3) {
            scanf("%d",&num);
            if (MaxEl(T)<num) {
                printf("array terlalu kecil\n");
            } else {
                ShrinkTab(&T,num);
                printf("%d ",MaxEl(T));
                TulisIsiTab(T);
                printf("\n");
            }
        } else {
            CompactTab(&T);
            printf("%d ",MaxEl(T));
            TulisIsiTab(T);
            printf("\n");
        }
    }
    Dealokasi(&T);
    return 0;
}