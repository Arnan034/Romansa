#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void tampilan_wins();
void tampilan_tie();
void tampilan_champion();
void tampilan_good();
void tampilan_input_main_lagi();

void gotoxy(int x, int y);

int main(){
	int x;
	x = 1;
	if (x == 1){
		tampilan_wins();
		tampilan_champion();
		tampilan_input_main_lagi();
	} else {
		tampilan_tie();
		tampilan_good();
		tampilan_input_main_lagi();
	}
}

void tampilan_wins(){
	gotoxy(31,7); printf("NAMA PLAYER");
	gotoxy(19,9); printf("00     11  10  101   01  01 101001");//62
	gotoxy(19,10); printf("10     00  11  0001  11   0 01");
	gotoxy(19,11); printf("01 100 10  00  11 01 01     101111");
	gotoxy(19,12); printf("1010 1011  10  00  1010         01");
	gotoxy(19,13); printf("100   111  00  10   110     101010");
}

void tampilan_tie(){
	gotoxy(15,9); printf("01  000101 00  010011     010111  01  010010");
	gotoxy(15,10); printf("11    00    1  01           10    10  10");
	gotoxy(15,11); printf("11    11       111011       01    11  011101");
	gotoxy(15,12); printf("00    01           00       00    11  01");
	gotoxy(15,13); printf("01    00       101011       11    01  100001");
}

void tampilan_champion(){
	gotoxy(61,3); printf(" 1010                          0110 ");
	gotoxy(61,4); printf("10  0110101010101010100000100100  11");
	gotoxy(61,5); printf("00   01010010101010010111001001   11");
	gotoxy(61,6); printf(" 111 01010100101001101010100101 101 ");
	gotoxy(61,7); printf("   111010101010001010100100101000   ");
	gotoxy(61,8); printf("      10010100100100000100100       ");
	gotoxy(61,9); printf("       001000100100101001001        ");
	gotoxy(61,10); printf("         10100010010100101          ");
	gotoxy(61,11); printf("            1010101101              ");
	gotoxy(61,12); printf("               0010                 ");
	gotoxy(61,13); printf("               1011                 ");
	gotoxy(61,14); printf("            0100100010              ");
	gotoxy(61,15); printf("          00111011010001            ");
	gotoxy(61,16); printf("       101011110010101001001        ");
	gotoxy(61,17); printf("       001001010100010111101        ");
	gotoxy(61,18); printf("    10101110001010110111000100      ");
}
void tampilan_good(){
	gotoxy(65,3); printf("             00011                  ");
	gotoxy(65,4); printf("            1011001                 ");
	gotoxy(65,5); printf("            1001001                 ");
	gotoxy(65,6); printf("           01010101                 ");
	gotoxy(65,7); printf("           10011101111              ");
	gotoxy(65,8); printf("         01010110111001001001       ");
	gotoxy(65,9); printf(" 101   010101001101100001000101     ");
	gotoxy(65,10); printf(" 101010101011101100101010           ");
	gotoxy(65,11); printf(" 0101101010101110101000010101101    ");
	gotoxy(65,12); printf(" 1110000100111100000110100010010    ");
	gotoxy(65,13); printf(" 110001010100110101010110           ");
	gotoxy(65,14); printf(" 001010100111010101000101010010     ");
	gotoxy(65,15); printf(" 010101010000000011001010010010     ");
	gotoxy(65,16); printf(" 000  1010100001101010100           ");
	gotoxy(65,17); printf("        1010100001100001001011      ");
	gotoxy(65,18); printf("            101010010000010         ");
}
void tampilan_input_main_lagi(){
	int d;
	gotoxy(23,16); printf("1. Y A");
	gotoxy(23,17); printf("2. T I D A K");
	gotoxy(23,15); printf("M A I N  L A G I ? ");scanf("%d", &d);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}