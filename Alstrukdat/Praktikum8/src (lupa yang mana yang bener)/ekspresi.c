// Nama : Reihan Andhika Putra
//  Nim : 13519043
//  Tanggal : 22/10/2020
//  Topik : Ekspresi.c
// Dengan memanfaatkan ADT Stack yang telah Anda kerjakan sebagai tugas pra-praktikum (file header: stackt.h) dan 
// Mesin Token yang dihasilkan pada praktikum sebelumnya, buatlah sebuah program dalam file bernama ekspresi.c 
// yang membaca sebuah pita karakter yang hanya berisi bilangan positif dan 0 serta operator ’+’, ’-’, ’*’, ’/’, dan ’^’ 
// yang membentuk sebuah ekspresi aritmatika dalam notasi postfix dan mengevaluasi ekspresi yang terdapat pada pita 
// karakter tersebut.



#include <stdio.h>
#include "stackt.h"
#include "mesintoken.h"

int main()
{
	STARTTOKEN();
	Stack Ekspresi;
	int op1, op2;
	CreateEmpty(&Ekspresi);
	if (EndToken) {
		printf("Ekspresi kosong\n");
	} else {
		int op3;
		while (!EndToken) {
			if (CToken.tkn == 'b') {
				printf("%d\n", CToken.val);
				Push(&Ekspresi, CToken.val);
			} else if (CToken.val == -1 ) {
				Pop(&Ekspresi, &op2);
				Pop(&Ekspresi, &op1);
				if (CToken.tkn == '+') {
					op3 = op1 + op2;
				} else if (CToken.tkn == '-') {
					op3 = op1 - op2;
				} else if (CToken.tkn == '*'){
					op3 = op1 * op2;
				} else if (CToken.tkn == '/') {
					op3 = op1 / op2;
				} else {
					if (op2 == 0 ) {
						op3 = 1 ;
					} else {
						op3 = op1 ;
						int i ;
						for (i = 1 ; i < op2; i++)
						op3 = op3*op1;
					}
				}
				printf("%d %c %d\n", op1, CToken.tkn, op2);
				printf("%d\n", op3);
				Push(&Ekspresi, op3);
			}
			ADVTOKEN();
		}
		Pop(&Ekspresi, &op3);
		printf("Hasil=%d\n", op3);
	}

	return 0;
}