#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char nama[10];
    char simbol;
    int score;
}Pemain;

typedef struct{
    char kotak[7][7];
	int ukuran;
}Papan;

typedef struct{
	int input_awal;
	int input_cara_bermain;	
}Permainan;

void cetak_menu_awal(Permainan *input);
	void tampilan_tiktaktoe();
	void tampilan_1play();
	void tampilan_2exit();
	void tampilan_input_awal(Permainan const *input);

void keluar_permainan();
	void tampilan_thankyou();
	void tampilan_for();
	void tampilan_playing();

void game();

void pilih_pemain(Permainan *const *input);
	void tampilan_1single();
	void tampilan_2multi();
	void tampilan_input_cara_bermain(Permainan const* *input);

void pilih_dimensi_papan();
	void tampilan_3x3();
	void tampilan_5x5();
	void tampilan_7x7();
	void tampilan_input_pilih_board();
	void cetak_papan();

void gotoxy(int x, int y);

/*================================================================================================================*/
int main(){
	/*Deklarasi*/
	Permainan* permainan;
	Pemain pemain1, pemain2, computer;
	Papan papan;
	/*Algoritma*/
	system("color");
	do{
		cetak_menu_awal(&permainan->input_awal);
		if(permainan->input_awal == 1){
			do{
			pilih_pemain(&permainan->input_awal);
			if(permainan->input_cara_bermain == 1){
				do{
				pilih_dimensi_papan(&papan.ukuran);
				}while((papan.ukuran != 3) || (papan.ukuran != 5) || (papan.ukuran != 7));
			} 
			if(permainan->input_cara_bermain == 2){
				do{
				pilih_dimensi_papan(&papan.ukuran);
				}while((papan.ukuran != 3) || (papan.ukuran != 5) || (papan.ukuran != 7));
			}
			}while((permainan->input_cara_bermain != 1) || (permainan->input_cara_bermain != 2));
		}
		if(permainan->input_awal == 2){
			keluar_permainan();
			return 0;
		}
	}while((permainan->input_awal != 1) || (permainan->input_awal != 2));
}
/*================================================================================================================*/


void cetak_menu_awal(Permainan *input){
	system("cls");
	tampilan_tiktaktoe();
	tampilan_1play();
	tampilan_2exit();
	tampilan_input_awal(&input->input_awal);
}
void tampilan_tiktaktoe(){
	gotoxy(19,2);printf("\033[1;37m010101  01  101010      010101    1001    101010      101010  0110010  010101");
	gotoxy(21,3);printf("10    10  01            10     01  10   01            01    10   01  10");
	gotoxy(21,4);printf("01    01  10            01    10101001  10            10    01   10  011001");
	gotoxy(21,5);printf("10    10  01            10    01    10  01            01    10   01  10");
	gotoxy(21,6);printf("01    01  101010        01    10    01  101010        10    0101010  010101\033[0m");
}
void tampilan_1play(){
	gotoxy(33,8);printf("\033[1;32m11        1010011  01        1000    11    11");
	gotoxy(33,9);printf("01        01   10  10      01  10     10  01");
	gotoxy(33,10);printf("00        0010101  01      10101001    1101");
	gotoxy(33,11);printf("01        10       00      10    01     01");
	gotoxy(33,12);printf("10        01       101010  00    10     10\033[0m");
}
void tampilan_2exit(){
	gotoxy(33,14); printf("\033[1;31m010101        010111   10   00   01   010010");
	gotoxy(33,15); printf("    10        10        01 01    00     10");
	gotoxy(33,16); printf("010101        001101     111     11     01");
	gotoxy(33,17); printf("10            10        10 10    00     10");
	gotoxy(33,18); printf("010101        100101   01   01   10     01\033[0m");
}
void tampilan_input_awal(Permainan const *input){
	gotoxy(43,20);printf("\033[1;37m+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &input->input_awal);
}


void keluar_permainan(){
	system("cls");
	tampilan_thankyou();
	tampilan_for();
	tampilan_playing();
}
void tampilan_thankyou(){
	gotoxy(20,2);printf("\033[1;37m101010   10  01     101     101   00   11  10   10    11   101001   01  11");
	gotoxy(22,3);printf("10     01  10    10 10    0101  10   01 01     10  01    01  00   10  00");
	gotoxy(22,4);printf("10     110101   1110011   01 11 10   1001       0101     10  10   01  10");
	gotoxy(22,5);printf("01     01  10   10   10   11  0100   00 10       01      01  10   10  01");
	gotoxy(22,6);printf("00     00  10   01   00   01   101   10  10      00      101001   100101");
}
void tampilan_for(){
	gotoxy(45,8);printf("011010   000101   100110");
	gotoxy(45,9);printf("00       10  01   01  10");
	gotoxy(45,10);printf("111011   10  01   100011");
	gotoxy(45,11);printf("01       01  10   10 11 ");
	gotoxy(45,12);printf("01       101001   01  00");
}
void tampilan_playing(){
	gotoxy(27,14); printf("101011   10         010     01    01   01   011   01   0111010");
	gotoxy(27,15); printf("01  01   01        10 11     10  11    11   1100  11   11     ");
	gotoxy(27,16); printf("101110   11       1000101     1001     11   01 10 01   10  111");
	gotoxy(27,17); printf("10       01       10   01      10      01   01  1001   01   01");
	gotoxy(27,18); printf("01       110100   00   11      01      10   10   001   1010101\033[0m");
}

/*
void game(){
	/*Deklarasi
	Permainan permainan;
	Pemain pemain1, pemain2, computer;
	Papan papan;
	/*Algoritma
	do{
	pilih_pemain(&permainan.input_cara_bermain);
	if(permainan.input_cara_bermain == 1){
		do{
		pilih_dimensi_papan(&papan.ukuran);
		
		}while((papan.ukuran != 3) || (papan.ukuran != 5) || (papan.ukuran != 7));
	} 
	if(permainan.input_cara_bermain == 2){
		do{
		pilih_dimensi_papan(&papan.ukuran);
		}while((papan.ukuran != 3) || (papan.ukuran != 5) || (papan.ukuran != 7));
	}
	}while((permainan.input_cara_bermain != 1) || (permainan.input_cara_bermain != 2));
}*/


void pilih_pemain(Permainan* input){
	system("cls");
	tampilan_tiktaktoe();
	tampilan_1single();
	tampilan_2multi();
	tampilan_input_cara_bermain(&input->input_cara_bermain);
}
void tampilan_1single(){
	gotoxy(31,8);printf("\033[1;32m11        100011  01  011   01  1000010  01      101010");//53
	gotoxy(31,9);printf("01        01      10  1010  10  01       01      10");
	gotoxy(31,10);printf("00        000101  01  10 01 01  10  101  10      011010");
	gotoxy(31,11);printf("01            10  00  01  1001  10   01  11      10");
	gotoxy(31,12);printf("10        100100  11  10   001  0100110  100101  010110\033[0m");
}
void tampilan_2multi(){
	gotoxy(31,14); printf("\033[1;34m010101        010   100  01  11  00      101000  10");//51
	gotoxy(31,15); printf("    10        1010 1011  10  00  01        01    01");
	gotoxy(31,16); printf("010101        11 101 01  11  01  01        00    10");
	gotoxy(31,17); printf("10            10     10  10  10  00        10    10");
	gotoxy(31,18); printf("010101        10     01  100101  101001    11    01\033[0m");
}
void tampilan_input_cara_bermain(Permainan const* *input){
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &input->input_cara_bermain);
}


/*
void pilih_dimensi_papan(Papan papan){
	system("cls");
	tampilan_3x3();
	tampilan_5x5();
	tampilan_7x7();
	tampilan_input_pilih_board(&papan->ukuran);
}
void tampilan_3x3(){
	gotoxy(40,2);printf("\033[1;32m1010101      01   10      0101011");
	gotoxy(43,3);printf("110       10 01           110");
	gotoxy(37,4);printf("0101001        011        1101011");
	gotoxy(40,5);printf("010       10 01           101");
	gotoxy(35,6);printf("1101001      01   10      0101000\033[0m");
}
void tampilan_5x5(){
	gotoxy(39,8);printf("\033[1;33m11010101      01   10     00101011");
	gotoxy(38,9);printf("110            10 01      110");
	gotoxy(37,10);printf("00110101        011       01110101");
	gotoxy(41,11);printf("010       10 01           101");
	gotoxy(35,12);printf("11010001      01   10     10111000\033[0m");
}
void tampilan_7x7(){
	gotoxy(39,14); printf("\033[1;31m11010101      01   10     10101011");
	gotoxy(43,15); printf("110       10 01           110");
	gotoxy(42,16); printf("001        011            011");
	gotoxy(41,17); printf("010       10 01           101");
	gotoxy(40,18); printf("001      01   10          000\033[0m");
}
void tampilan_input_pilih_board(Papan papan){
	gotoxy(38,0);printf("\033[1;37mS E L E C T   D I M E N S I O N ?");
	gotoxy(50,19);printf("3 / 5 / 7");
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+\033[0m");
	gotoxy(54,21);scanf("%d", &papan->ukuran);
	getchar();
}*/


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}