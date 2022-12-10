#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_tiktaktoe();
void tampilan_1single();
void tampilan_2multi();
void tampilan_input();

void gotoxy(int x, int y);

int main(){
	tampilan_tiktaktoe();
	tampilan_1single();
	tampilan_2multi();
	tampilan_input();
}

void tampilan_tiktaktoe(){
	gotoxy(19,2);printf("010101  01  101010      010101    1001    101010      101010  0110010  010101");//77
	gotoxy(21,3);printf("10    10  01            10     01  10   01            01    10   01  10");
	gotoxy(21,4);printf("01    01  10            01    10101001  10            10    01   10  011001");
	gotoxy(21,5);printf("10    10  01            10    01    10  01            01    10   01  10");
	gotoxy(21,6);printf("01    01  101010        01    10    01  101010        10    0101010  010101");
}

void tampilan_1single(){
	gotoxy(31,8);printf("11        100011  01  011   01  1000010  01      101010");//53
	gotoxy(31,9);printf("01        01      10  1010  10  01       01      10");
	gotoxy(31,10);printf("00        000101  01  10 01 01  10  101  10      011010");
	gotoxy(31,11);printf("01            10  00  01  1001  10   01  11      10");
	gotoxy(31,12);printf("10        100100  11  10   001  0100110  100101  010110");
}

void tampilan_2multi(){
	gotoxy(31,14); printf("010101        010   100  01  11  00      101000  10");//51
	gotoxy(31,15); printf("    10        1010 1011  10  00  01        01    01");
	gotoxy(31,16); printf("010101        11 101 01  11  01  01        00    10");
	gotoxy(31,17); printf("10            10     10  10  10  00        10    10");
	gotoxy(31,18); printf("010101        10     01  100101  101001    11    01");
}

void tampilan_input(){
	int z;
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &z);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}