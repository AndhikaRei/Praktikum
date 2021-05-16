// Nama : Reihan Andhika Putra
// Nim : 13519043
// Tanggal : 08/10/2020
/* File : packet.c */


#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "prioqueuechar.h"

int main() {
    int N;
    infotype Packet;
    PrioQueueChar Q;
    int i;
    int nowpacket;
    nowpacket = 1;
    
    scanf("%d", &N);
    MakeEmpty(&Q, 100);
    for(i = 1; i <= N; i++){
        scanf("%d %c", &Prio(Packet), &Info(Packet));
        Enqueue(&Q, Packet);
        while(Prio(InfoHead(Q))==nowpacket){
            Dequeue(&Q, &Packet);
            printf("%d %c\n", i, Info(Packet));
            nowpacket = nowpacket + 1;
        }
    }
    return 0;
    
}