#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y);
void tampilan_player_biner();
void tampilan_row_colums();
void tampilan_nama_player();
void tampilan_papan();
void tampilan_score();

int main(){
	system("color 7");
	tampilan_papan();
	tampilan_player_biner();
	tampilan_row_colums();
	tampilan_nama_player();
	tampilan_score();
	return 0;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void tampilan_papan(){
	char A[7][7];
	int l = 0;
	for(int e = 0; e < 7; e++){
		for (int f = 0; f < 7; f++){
		A[e][f] = '0';
		}
	}
	for (int i = 3; i <= 17; i++){
		if (i % 2 == 1){
			gotoxy(40,i);printf("+---+---+---+---+---+---+---+");
		}
		if (i % 2 == 0){
			gotoxy(40,i);printf("| %c | %c | %c | %c | %c | %c | %c |", A[l][0], A[l][1], A[l][2], A[l][3], A[l][4], A[l][5], A[l][6]);
			l++;
		}
	}
}

void tampilan_player_biner(){
	gotoxy(17,6); printf("\033[1;31m");printf("010101");
	gotoxy(16,7); printf("11010111");
	gotoxy(16,8); printf("00010100");
	gotoxy(16,9); printf("11001011");
	gotoxy(17,10); printf("110110");
	gotoxy(14,11); printf("010100101010");
	gotoxy(13,12); printf("10101010101001");	
	gotoxy(13,13); printf("10101010101110");
	gotoxy(86,6); printf("010101");
	gotoxy(85,7); printf("11010111");
	gotoxy(85,8); printf("00010100");
	gotoxy(85,9); printf("11001011");
	gotoxy(86,10); printf("110110");
	gotoxy(83,11); printf("010100101010");
	gotoxy(82,12); printf("10101010101001");	
	gotoxy(82,13); printf("10101010101110");printf("\033[1;31m");
}

void tampilan_row_colums(){
	int l = 1;
	printf("\033[1;34m");
	gotoxy(49,1); printf("C O L U M N");
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
	printf("\033[1;34m");
}

void tampilan_nama_player(){
	/*char player[10];
	player = 'Arnan';
	for (int i = 0; i < strlen(player);i++){
		player[i] = toupper(player[i]);
	}*/
	gotoxy(16,4); printf("Arnanda");
	gotoxy(85,4); printf("Bhisma");
}

void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : 0");
	gotoxy(83,15); printf("S C O R E : 0\n\n");
}