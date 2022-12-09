#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_input();
void tampilan_tiktaktoe();
void gotoxy(int x, int y);

int main(){
	tampilan_tiktaktoe();
	tampilan_input();
}

void tampilan_tiktaktoe(){
	gotoxy(19,2);printf("010101  01  101010      010101    1001    101010      101010  0110010  010101");
	gotoxy(21,3);printf("10    10  01            10     01  10   01            01    10   01  10");
	gotoxy(21,4);printf("01    01  10            01    10101001  10            10    01   10  011001");
	gotoxy(21,5);printf("10    10  01            10    01    10  01            01    10   01  10");
	gotoxy(21,6);printf("01    01  101010        01    10    01  101010        10    0101010  010101");
}
 

void tampilan_input(){
	int z;
	gotoxy(49,12);printf("P L A Y E R %d", 1);
	gotoxy(47,13);printf("N I C K N A M E ?");
	gotoxy(43,14);printf("+----------------------+");
	gotoxy(43,15);printf("|                      |");
	gotoxy(43,16);printf("+----------------------+");
	gotoxy(46,17);printf("M A X  1 0  C H A R");
	gotoxy(92,23);printf("9.Back");
	gotoxy(50,15);scanf("%d", &z);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}