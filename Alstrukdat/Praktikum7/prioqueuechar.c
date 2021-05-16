// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 08/10/2020
/* File : prioqueue.c */
/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */




#include "boolean.h"
#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

// #define Nil -1
// /* Konstanta untuk mendefinisikan address tak terdefinisi */

// /* Definisi elemen dan address */
// typedef struct {
//     int prio;  /* [1..100], prioritas dengan nilai 1..100 (1 adalah prioritas tertinggi) */
//     char info;  /* elemen karakter */
// } infotype;

// typedef int address;   /* indeks tabel */
// /* Contoh deklarasi variabel bertype PrioQueueChar : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct {
//     infotype * T;   /* tabel penyimpan elemen */
//     address HEAD;  /* alamat penghapusan */
//     address TAIL;  /* alamat penambahan */
//     int MaxEl;     /* Max elemen queue */
// } PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
// #define Prio(e)     (e).prio
// #define Info(e)     (e).info
// #define Head(Q)     (Q).HEAD
// #define Tail(Q)     (Q).TAIL
// #define InfoHead(Q) (Q).T[(Q).HEAD]
// #define InfoTail(Q) (Q).T[(Q).TAIL]
// #define MaxEl(Q)    (Q).MaxEl
// #define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Q.TAIL == Nil && Q.HEAD == Nil);
}

boolean IsFull (PrioQueueChar Q){
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return (Q.TAIL == Q.MaxEl-1 && Q.HEAD == 0);
}

int NBElmt (PrioQueueChar Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmpty(Q)){
        return 0;
    } else if (Q.HEAD <= Q.TAIL) {
        return (Q.TAIL - Q.HEAD + 1);
    } else {
        return (Q.MaxEl-Q.HEAD+Q.TAIL+1);
    }
    
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    /* I.S. sembarang */
    /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
    /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
    /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
    /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infotype*) malloc(Max*sizeof(infotype));
    if ((*Q).T != NULL){
        MaxEl(*Q) = Max;
        Tail(*Q) = Nil;
        Head(*Q) = Nil;
    } else {
        MaxEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoHead(*Q) = X ;
    } else {
        boolean found = false;
        address Xadd = Tail(*Q) ;
        address Xtuk = 0 ;
        while (!(found)){
            Xtuk = Xadd + 1;
            if (Xtuk == MaxEl(*Q)) {
                Xtuk = 0; 
            }
            if (Prio(Elmt(*Q,Xadd)) > Prio(X)){
                Elmt(*Q,Xtuk) = Elmt(*Q,Xadd);
                Elmt(*Q,Xadd) = X;
                found = true ;
            }else{
                Elmt(*Q,Xtuk) = Elmt(*Q,Xadd);
            } 
            Xadd = Xadd -1 ;
            if (Xadd == -1) {
                Xadd = (*Q).MaxEl - 1; 
            }
                
        }
        Tail(*Q) = Tail(*Q) + 1 ;
        if (Tail(*Q) == MaxEl(*Q)){
            Tail(*Q) = 0 ; 
        } 
        // address Xaddress = Head(Q);
        // if (Prio(Elmt(*Q,Xaddress)) > Prio(X)){
        //     Xaddress = Head(Q);
        // } else {
        //     Xaddress = Xaddress + 1 ;
        // }

    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        if (Head(*Q)==MaxEl(*Q)-1){
            Head(*Q) = 0;
        } else {
            Head(*Q) = Head(*Q) + 1;
        }
    }
}


/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    #
    */
   infotype CurrentElmt;
    while (!IsEmpty(Q)){
        Dequeue(&Q, &CurrentElmt);
        printf("%d %c\n", Prio(CurrentElmt), Info(CurrentElmt));
    }
    printf("#\n");
}



