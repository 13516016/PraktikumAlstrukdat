/* File: mesintoken.h */
/* Definisi Mesin Token: Model Akuisisi Versi I */

/* State Mesin Kata */
#include<stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"


boolean EndToken;
Token CToken;

void IgnoreBlank(){
	
	while ((CC==BLANK) && (CC!=MARK)){
		ADV();
	}
	
};
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTTOKEN(){
	START();
	IgnoreBlank();
	if (CC == MARK) {
		EndToken = true;
	} else /* CC != MARK */ 
	{
		EndToken = false;
		SalinToken();
	}
};
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN(){
	IgnoreBlank();
	if (CC == MARK) {
		EndToken = true;
	} else /* CC != MARK */ {
		SalinToken();
	}
};
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinToken(){
	IgnoreBlank();
	int i = 1; /* inisialisasi */
	int token ;
/* Algoritma*/
	CToken.val = -1;
	
	if (CC == '+' || CC == '-' ||CC == '*' ||CC == '/' || CC == '^'){
		CToken.tkn = CC;	
		
		ADV();
		
	} 
	else {
		CToken.val = 0;
		CToken.tkn = 'b';
		for (;;) {
		token = CC - '0' ;
		CToken.val = CToken.val + token;
		ADV();
		if ((CC == MARK) || (CC == BLANK) || (i>=NMax)) {
			break;
		if (i>NMax){
			i--;	
			}
		} 	
		else {
			i++;
			CToken.val = CToken.val*10;
		}
	}
  } /* CC = MARK or CC = BLANK */
  IgnoreBlank();
};
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


