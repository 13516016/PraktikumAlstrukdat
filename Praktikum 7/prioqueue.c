//Nama					: Yuly Haruka Berliana Gunawan
//NIM					: 13516031
//Tanggal				: 5 Oktober 2017
//Topik Praktikum		: Queue
//Deskripsi				: membuat prioqueue.c

#include <stdio.h>
#include "prioqueue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Tail(Q) == Nil && Head(Q) == Nil);
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmpty(Q)) {
        return 0;
    } else {
        if (Head(Q) <= Tail(Q)) {
            return (Tail(Q) - Head(Q) + 1);
        } else {
            return (MaxEl(Q) - (Head(Q) - Tail(Q) - 1));
        }
    }
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
    if ((*Q).T != Nil) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        MaxEl(*Q) = Nil;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).T);
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
	infotype t;

	if (IsEmpty(*Q)) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
		Prio(InfoHead(*Q)) = Prio(X);
		Info(InfoHead(*Q)) = Info(X);
	} else {
		if (Tail(*Q) == MaxEl(*Q)) {
			Tail(*Q) = 1;
			Prio(InfoTail(*Q)) = Prio(X);
			Info(InfoTail(*Q)) = Info(X);
			int i = MaxEl(*Q);
			while(Prio(X) > Prio(Elmt(*Q, i)) && i >= Head(*Q)) {
				Prio(t) = Prio(X);
				Prio(X) = Prio(Elmt(*Q, i));
				Prio(Elmt(*Q, i)) = Prio(t);

				Info(t) = Info(X);
				Info(X) = Info(Elmt(*Q, i));
				Info(Elmt(*Q, i)) = Info(t);
			}
		} else {
			Tail(*Q)++;
			Prio(InfoTail(*Q)) = Prio(X);
			Info(InfoTail(*Q)) = Info(X);
			int i = Tail(*Q) - 1;
			while(Prio(X) > Prio(Elmt(*Q, i)) && i >= Head(*Q)) {
				Prio(t) = Prio(X);
				Prio(Elmt(*Q, i+1)) = Prio(Elmt(*Q, i));
				Prio(Elmt(*Q, i)) = Prio(t);

				Info(t) = Info(X);
				Info(Elmt(*Q, i+1)) = Info(Elmt(*Q, i));
				Info(Elmt(*Q, i)) = Info(t);
				i--;
			}
		}
	}
}

void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmt(*Q) == 1) {
        Prio(*X) = Prio(InfoHead(*Q));
        Info(*X) = Info(InfoHead(*Q));
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Prio(*X) = Prio(InfoHead(*Q));
        Info(*X) = Info(InfoHead(*Q));
        if (Head(*Q) == MaxEl(*Q)) {
            Head(*Q) = 1;
        } else {
            ++Head(*Q);
        }
    }
}

/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	infotype X;

	if (IsEmpty(Q)) {
		printf("#\n");
	} else {
		while(!IsEmpty(Q)) {
			Del(&Q, &X);
			printf("%d %d\n", Prio(X), Info(X));
		}
		printf("#\n");
	}
}
