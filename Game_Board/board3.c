#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_3x3();
void tampilan_5x5();
void tampilan_7x7();
void tampilan_input();

void gotoxy(int x, int y);

int main(){
	tampilan_3x3();
	tampilan_5x5();
	tampilan_7x7();
	tampilan_input();
}

void tampilan_3x3(){
	gotoxy(40,2);printf("1010101      01   10      0101011");
	gotoxy(43,3);printf("110       10 01           110");
	gotoxy(37,4);printf("0101001        011        1101011");
	gotoxy(40,5);printf("010       10 01           101");
	gotoxy(35,6);printf("1101001      01   10      0101000");
}

void tampilan_5x5(){
	gotoxy(39,8);printf("11010101      01   10     00101011");
	gotoxy(38,9);printf("110            10 01      110");
	gotoxy(37,10);printf("00110101        011       01110101");
	gotoxy(41,11);printf("010       10 01           101");
	gotoxy(35,12);printf("11010001      01   10     10111000");
}

void tampilan_7x7(){
	gotoxy(39,14); printf("11010101      01   10     10101011");
	gotoxy(43,15); printf("110       10 01           110");
	gotoxy(42,16); printf("001        011            011");
	gotoxy(41,17); printf("010       10 01           101");
	gotoxy(40,18); printf("001      01   10          000");
}

void tampilan_input(){
	int z;
	gotoxy(37,0);printf("S E L E C T   D I M E N S I O N ?");
	gotoxy(50,19);printf("3 / 5 / 7");
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(92,23);printf("9.Back");
	gotoxy(54,21);scanf("%d", &z);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}