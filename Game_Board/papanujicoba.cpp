#include<stdio.h>
#include<windows.h>

char A[7][7];
void gotoxy(int x, int y);
void tampilan_player_biner();
void tampilan_row_colums();
void tampilan_nama_player();
void tampilan_papan();
void tampilan_color_X_O();
void tampilan_score();
void tampilan_aksesoris_tiktaktoe();

int player = 2;


int main(){
	int row, colums;
	
	system("color");
	tampilan_papan();
	tampilan_color_X_O();
	tampilan_player_biner();
	tampilan_row_colums();
	tampilan_nama_player();
	tampilan_score();
	tampilan_aksesoris_tiktaktoe();
	gotoxy(91,21); scanf("%d", &row);
	gotoxy(91,23); scanf("%d", &colums);
	return 0;
}

void tampilan_papan(){
	int l = 0;
	for(int e = 0; e < 7; e++){
		for (int f = 0; f < 7; f++){
		A[e][f] = '0';
		}
	}
	printf("\033[1;37m");
	for (int i = 3; i <= 17; i++){
		if (i % 2 == 1){
			gotoxy(40,i);printf("+---+---+---+---+---+---+---+");
		}
		if (i % 2 == 0){
			gotoxy(40,i);printf("|   |   |   |   |   |   |   |");
			l++;
		}
	}
}

void tampilan_color_X_O(){
	int a, b;
	a = 0;
	printf("\033[1;31m");
	for (int i = 3; i <= 17;i++){
		b = 0;
		for (int j = 40; j <= 66; j++){
			if ((i % 2 == 0) && (j % 4 == 2)){
				if(A[a][b] == 'X'){
				gotoxy(j,i);printf("\033[1;31m%c\033[0m", A[a][b]);
				} else if (A[a][b] == 'O'){
					gotoxy(j,i);printf("\033[1;32m%c\033[0m", A[a][b]);
					} else {
						gotoxy(j,i);printf("\033[1;30m%c\033[0m", A[a][b]);
					}
			b++;
			}
		}
		if (i % 2 == 0){
		a++;
		}
	}
}

void tampilan_player_biner(){
	gotoxy(17,6); printf("\033[1;34m010101");
	gotoxy(16,7); printf("11010111");
	gotoxy(16,8); printf("00010100");
	gotoxy(16,9); printf("11001011");
	gotoxy(17,10); printf("110110");
	gotoxy(14,11); printf("010100101010");
	gotoxy(13,12); printf("10101010101001");	
	gotoxy(13,13); printf("10101010101110");
	if (player == 1){
		gotoxy(83,6); printf("\033[1;32m1000101110010101");
		gotoxy(83,7);printf("10            01");
		gotoxy(83,8);printf("00            01");
		gotoxy(83,9);printf("01            11");
		gotoxy(83,10);printf("10            10");
		gotoxy(83,11);printf("1010010010010101");
		gotoxy(83,12);printf("    01001011");
		gotoxy(83,13);printf("  101000101010");
	} else {
	gotoxy(87,6); printf("\033[1;32m010101");
	gotoxy(86,7); printf("11010111");
	gotoxy(86,8); printf("00010100");
	gotoxy(86,9); printf("11001011");
	gotoxy(87,10); printf("110110");
	gotoxy(84,11); printf("010100101010");
	gotoxy(83,12); printf("10101010101001");	
	gotoxy(83,13); printf("10101010101110");
	}
}

void tampilan_row_colums(){
	int l = 1;
	printf("\033[1;31m");
	gotoxy(49,1); printf("C O L U M S");
	gotoxy(41,2); printf(" 1   2   3   4   5   6   7");
	gotoxy(36,8); printf("R");
	gotoxy(36,10); printf("O");
	gotoxy(36,12); printf("W");
	for (int i = 3; i <= 17;i++){
		if(i % 2 == 0){
			gotoxy(38,i);printf("%d", l);
			l++;
		}
	}
}

void tampilan_nama_player(){
	gotoxy(16,4); printf("\033[1;37mArnanda");
	if (player == 1){
		gotoxy(84,4); printf("C O M P U T E R");	
	} else {
		gotoxy(86,4); printf("Bhisma");
	}
}

void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : 0");
	gotoxy(84,15); printf("S C O R E : 0");
}

void tampilan_aksesoris_tiktaktoe(){
	gotoxy(8,20);
	printf("010101 01 101010    010101   1001   101010    101010 0110010 010101      +--------------------+\n");
	printf("         10   10 01          10    01  10  01          01   10   01 10           |ROW    :            |\n");
	printf("        01   01 10          01   10101001 10          10   01   10 011001        +--------------------+\n");
	printf("       10   10 01          10   01    10 01          01   10   01 10             |COLUMS :            |\n");
	printf("      01   01 101010      01   10    01 101010      10   0101010 010101          +--------------------+\n");
	
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
