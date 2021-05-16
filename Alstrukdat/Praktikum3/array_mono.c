// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 10/09/2020
// Topik : Array_Mono
// Deskripsi : Membuat program yang mengecek kemonotonan array

#include "boolean.h"
#include <stdio.h>
#include "arraypos.h"

int main()
{
    TabInt T, Tbesar, Tkecil;
    BacaIsi(&T);
    Tbesar = T;
    Tkecil = T;
    Sort(&Tbesar, true);
    Sort(&Tkecil, false);
    if (IsEQ(T, Tbesar) && IsEQ(T, Tkecil))
    {
        printf("Array monotonik statik\n");
    }
    else if (IsEQ(T, Tbesar))
    {
        printf("Array monotonik tidak mengecil\n");
    }
    else if (IsEQ(T, Tkecil))
    {
        printf("Array monotonik tidak membesar\n");
    }
    else
    {
        printf("Array tidak monotonik\n");
    }
    return 0;
}
