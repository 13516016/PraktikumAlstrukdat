#include<stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"


boolean IsKataSama(Kata K1, Kata K2){
	int i;
	boolean check = true;
	
	if (K1.Length == K2.Length){
		for (i = 1; i <=K1.Length; i++){
			if (K1.TabKata[i]!= K2.TabKata[i]){
				check = false;
			}
		}
		return check;
	}
	else {
		return false;
	}
}

void printKata(Kata K1){
	int i;
	for (i=1; i<=K1.Length;i++){
		printf("%c",K1.TabKata[i]);
	}

}

boolean isReguler(Kata K1){
	
	return (K1.Length<10);
	
}
	
	
int main(){
	int i;
	int countReguler=0;
	int countPanjang=0;
	int countKata=0;
	int harga = 0;
	Kata kataTitik;
	Kata kataKoma;
	
	//init kata titik
	kataTitik.Length = 5;
	kataTitik.TabKata[1] = 'T';
	kataTitik.TabKata[2] = 'I';
	kataTitik.TabKata[3] = 'T';
	kataTitik.TabKata[4] = 'I';
	kataTitik.TabKata[5] = 'K';
	
	//init kata koma
	kataKoma.Length = 4;
	kataKoma.TabKata[1] = 'K';
	kataKoma.TabKata[2] = 'O';
	kataKoma.TabKata[3] = 'M';
	kataKoma.TabKata[4] = 'A';	
	
	STARTKATA();
	while (!EndKata){
		if (IsKataSama(CKata,kataTitik)){
			printf(".");
		}
		else if (IsKataSama(CKata,kataKoma)){
			printf(",");
			}
		else {
			
			printKata(CKata);
			
			if (isReguler(CKata)){
			countReguler++;
			}
			else {
			countPanjang++;
			}
		
		}
		countKata++;
		
		
		
		ADVKATA();
		
		if (!EndKata && !IsKataSama(CKata,kataTitik) && !IsKataSama(CKata,kataKoma) ){
			printf(" ");
		}
		
	}
	printf("\n");
	
	if (countKata>10){
		harga = (countReguler*1000 + countPanjang*1500) * 90 / 100; 
	}
	else{
		harga = (countReguler*1000 + countPanjang*1500);
	}
	
	printf("%d\n",countReguler);
	printf("%d\n",countPanjang);
	printf("%d\n",harga);
	
	

		
}
