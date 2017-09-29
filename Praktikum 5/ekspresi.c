#include<stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesintoken.h"

int main(){
	
	
	STARTTOKEN();
	if (!EndToken){
		while(!EndToken){
			if (CToken.tkn == 'b'){
				printf("%d\n",CToken.val);
			}
			else{
				printf("%c\n",CToken.tkn);
			}
			ADVTOKEN();
		}
	}
	else {
		printf("Ekspresi kosong\n");
	}
}
