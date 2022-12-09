#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_thankyou();
void tampilan_for();
void tampilan_playing();
void tampilan_input();

void gotoxy(int x, int y);

int main(){
	tampilan_thankyou();
	tampilan_for();
	tampilan_playing();
}

void tampilan_thankyou(){
	gotoxy(20,2);printf("101010   10  01     101     101   00   11  10   10    11   101001   01  11");//67
	gotoxy(22,3);printf("10     01  10    10 10    0101  10   01 01     10  01    01  00   10  00");
	gotoxy(22,4);printf("10     110101   1110011   01 11 10   1001       0101     10  10   01  10");
	gotoxy(22,5);printf("01     01  10   10   10   11  0100   00 10       01      01  10   10  01");
	gotoxy(22,6);printf("00     00  10   01   00   01   101   10  10      00      101001   100101");
}

void tampilan_for(){
	gotoxy(45,8);printf("011010   000101   100110");//20
	gotoxy(45,9);printf("00       10  01   01  10");
	gotoxy(45,10);printf("111011   10  01   100011");
	gotoxy(45,11);printf("01       01  10   10 11 ");
	gotoxy(45,12);printf("01       101001   01  00");
}

void tampilan_playing(){
	gotoxy(27,14); printf("101011   10         010     01    01   01   011   01   0111010");//62
	gotoxy(27,15); printf("01  01   01        10 11     10  11    11   1100  11   11     ");
	gotoxy(27,16); printf("101110   11       1000101     1001     11   01 10 01   10  111");
	gotoxy(27,17); printf("10       01       10   01      10      01   01  1001   01   01");
	gotoxy(27,18); printf("01       110100   00   11      01      10   10   001   1010101");
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}