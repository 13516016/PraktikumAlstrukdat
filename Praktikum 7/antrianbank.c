#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#include "boolean.h"

float AvgElmt (Queue Q){
	int front;
	float sum=0;
	int nElmt = NBElmt(Q);
	
	while(!IsEmpty(Q)){
		Del(&Q,&front);
		sum+=front;
	}
	
	return sum/nElmt;
};
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */



int main(){	
	Queue antrian;
	int nCustomer = 0;
	int tAntrian;
	int frontAntrian;
	int maxAntrian = 0;
	int nAntrian;
	int menu;
	float avgAntrian;
	float sumAntrian;
	
	scanf("%d",&maxAntrian);
	sumAntrian=0;
	CreateEmpty(&antrian,maxAntrian);
	do {
		scanf("%d", &menu);
		if(menu==1){
			scanf("%d",&tAntrian);
			if (!IsFull(antrian)){
				Add(&antrian,tAntrian);
				nAntrian++;
			}
			else {
				printf("Queue penuh\n");
			}
		}
		else if(menu == 2){
			if (!IsEmpty(antrian)){
				Del(&antrian,&frontAntrian);
				nAntrian--;
			}
			else {
				printf("Queue kosong\n");
			}
		}
	}while (menu!=0);
	
	printf("%d\n",nAntrian);
	if (!IsEmpty(antrian)){
		printf("%.2f\n",AvgElmt(antrian));
	}
	else {
		printf("Tidak bisa dihitung\n");
	}
	
}
