/*	Nama 	: Adylan Roaffa Ilmy
	NIM 	: 13516016
	Tanggal : Kamis, 19 Oktober 2017
	Topik 	: Stack
*/

#include "boolean.h"
#include "mesintoken.h"
#include "mesintoken.h"
#include "stackt.h"
#include <stdio.h>
#include <math.h>





int main(){
	Stack s;
	infotype x;
	char operator;
	int op1;
	int op2;
	int hasil=0;


	CreateEmpty(&s);

	STARTTOKEN();
	if(!EndToken){
		while(!EndToken){
			if(CToken.val<0){
					operator = CToken.tkn;
					Pop(&s,&op1);
					Pop(&s,&op2);

					if (operator == '+'){
						printf("%d + %d\n", op2, op1);
						op2+=op1;
					}
					else if (operator == '-'){
						printf("%d - %d\n", op2, op1);
						op2-=op1;
					}
					else if (operator == '*'){
						printf("%d * %d\n", op2, op1);
						op2*=op1;
					}
					else if (operator == '/'){
						printf("%d / %d\n", op2, op1);
						op2/=op1;
					}
					else if (operator == '^'){
						printf("%d ^ %d\n", op2, op1);
						op2 =  pow(op2,op1);
					}

					printf("%d\n",op2);

					Push(&s,op2);
			}
			else {
				Push(&s, CToken.val);
				printf("%d\n",CToken.val );

			}
			ADVTOKEN();
		}

		printf("Hasil=%d\n",InfoTop(s));
	}
	else {
		printf("Ekspresi kosong\n");
	}


}
