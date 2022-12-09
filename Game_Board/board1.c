#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_tiktaktoe();
void tampilan_1play();
void tampilan_2exit();
void tampilan_input();

void gotoxy(int x, int y);

int main(){
	tampilan_tiktaktoe();
	tampilan_1play();
	tampilan_2exit();
	tampilan_input();
}

void tampilan_tiktaktoe(){
	gotoxy(19,2);printf("010101  01  101010      010101    1001    101010      101010  0110010  010101");
	gotoxy(21,3);printf("10    10  01            10     01  10   01            01    10   01  10");
	gotoxy(21,4);printf("01    01  10            01    10101001  10            10    01   10  011001");
	gotoxy(21,5);printf("10    10  01            10    01    10  01            01    10   01  10");
	gotoxy(21,6);printf("01    01  101010        01    10    01  101010        10    0101010  010101");
}

void tampilan_1play(){
	gotoxy(33,8);printf("11        1010011  01        1000    11    11");
	gotoxy(33,9);printf("01        01   10  10      01  10     10  01");
	gotoxy(33,10);printf("00        0010101  01      10101001    1101");
	gotoxy(33,11);printf("01        10       00      10    01     01");
	gotoxy(33,12);printf("10        01       101010  00    10     10");
}

void tampilan_2exit(){
	gotoxy(33,14); printf("010101        010111   10   00   01   010010");
	gotoxy(33,15); printf("    10        10        01 01    00     10");
	gotoxy(33,16); printf("010101        001101     111     11     01");
	gotoxy(33,17); printf("10            10        10 10    00     10");
	gotoxy(33,18); printf("010101        100101   01   01   10     01");
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