#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include<unistd.h>

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
	int jumlah_permain;
	int main_lagi;
	bool penentu_player;
	bool penentu_dimensi;
	bool invalid_move;
	bool penentu_main_lagi;
}Permainan;

Permainan permainan;
Papan papan;
Pemain pemain1, pemain2, computer;

void cetak_menu_awal();
	void tampilan_tiktaktoe();
	void tampilan_1play();
	void tampilan_2exit();
	void tampilan_input_awal();

void keluar_permainan();
	void tampilan_thankyou();
	void tampilan_for();
	void tampilan_playing();

void pilih_pemain();
	void tampilan_1single();
	void tampilan_2multi();
	void tampilan_input_cara_bermain();

void pilih_dimensi_papan();
	void tampilan_3x3();
	void tampilan_5x5();
	void tampilan_7x7();
	void tampilan_input_pilih_board();
	void cetak_papan();

void tampilan_nickname();
	void tampilan_input_nickname();

void mulai_permainan();
	void hapus_papan();
	void game_board_permainan();
		void cetak_papan();
		void tampilan_color_X_O();
		void tampilan_player_biner();
		void tampilan_row_colums();
		void tampilan_nama_player();
		void tampilan_score();
		void tampilan_aksesoris_tiktaktoe();
		void giliran_pemain();
		void giliran_computer();
		bool cek_tempat_kosong();
	char cek_menang();
	char cek_menang_3x3();
	char cek_menang_5x5();
	char cek_menang_7x7();
	bool cek_papan_penuh();
	
void ulangi_permainan(char winner);
	void tampilan_wins();
	void tampilan_tie();
	void tampilan_champion();
	void tampilan_good();
	void tampilan_input_main_lagi();

void hitung_score();

void gotoxy(int x, int y);

/*================================================================================================================*/
/*================================================================================================================*/
int main(){
	/*Deklarasi*/
	permainan.jumlah_permain = 0;
	papan.ukuran = 1;
	/*Algoritma*/
	system("color");
	do{
		cetak_menu_awal();
		if(permainan.input_awal == 1){
			pilih_pemain();
			pilih_dimensi_papan();
			tampilan_nickname();
			mulai_permainan();
		}
		if(permainan.input_awal == 2){
			keluar_permainan();
			return 0;	
		}
	}while((permainan.input_awal != 1) || (permainan.input_awal != 2));
	
	return 0;
}
/*================================================================================================================*/
/*================================================================================================================*/


void cetak_menu_awal(){
	system("cls");
	tampilan_tiktaktoe();
	tampilan_1play();
	tampilan_2exit();
	tampilan_input_awal();
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
void tampilan_input_awal(){
	gotoxy(43,20);printf("\033[1;37m+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &permainan.input_awal);getchar();
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


void pilih_pemain(){
	do{
	system("cls");
	tampilan_tiktaktoe();
	tampilan_1single();
	tampilan_2multi();
	tampilan_input_cara_bermain();
	}while(permainan.penentu_player);
}
void tampilan_1single(){
	gotoxy(31,8);printf("\033[1;32m11        100011  01  011   01  1000010  01      101010");
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
void tampilan_input_cara_bermain(){
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &permainan.input_cara_bermain);getchar();
	if((permainan.input_cara_bermain == 1) || (permainan.input_cara_bermain == 2)){
		permainan.penentu_player = false;
	} else {
		permainan.penentu_player = true;
	}
}


void pilih_dimensi_papan(){
	do{
	system("cls");
	tampilan_3x3();
	tampilan_5x5();
	tampilan_7x7();
	tampilan_input_pilih_board();
	}while(permainan.penentu_dimensi);
}
void tampilan_3x3(){
	gotoxy(40,2);printf("\033[1;32m1010101      01   10      0101011");
	gotoxy(43,3);printf("110       10 01           110");
	gotoxy(37,4);printf("0101001        011        1101011");
	gotoxy(40,5);printf("010       10 01           101");
	gotoxy(35,6);printf("1101001      01   10      0101000\033[0m");
}
void tampilan_5x5(){
	gotoxy(39,8);printf("\033[0;33m11010101      01   10     00101011");
	gotoxy(38,9);printf("110            10 01      110");
	gotoxy(37,10);printf("00110101        011       01110101");
	gotoxy(41,11);printf("010       10 01           101");
	gotoxy(35,12);printf("11010001      01   10     10111000\033[0m");
}
void tampilan_7x7(){
	gotoxy(39,14); printf("\033[0;31m11010101      01   10     10101011");
	gotoxy(43,15); printf("110       10 01           110");
	gotoxy(42,16); printf("001        011            011");
	gotoxy(41,17); printf("010       10 01           101");
	gotoxy(40,18); printf("001      01   10          000\033[0m");
}
void tampilan_input_pilih_board(){
	gotoxy(38,0);printf("\033[1;37mS E L E C T   D I M E N S I O N ?");
	gotoxy(50,19);printf("3 / 5 / 7");
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+\033[0m");
	gotoxy(54,21);scanf("%d", &papan.ukuran);getchar();
	if((papan.ukuran == 3) || (papan.ukuran == 5) || (papan.ukuran == 7)){
		permainan.penentu_dimensi = false;
	} else {
		permainan.penentu_dimensi = true;
	}
}


void tampilan_nickname(){
	for(int i = 1; i <= permainan.input_cara_bermain; i++){
		system("cls");
		tampilan_tiktaktoe();
		tampilan_input_nickname();
		if(i == 1){
			gotoxy(50,15);fgets(pemain1.nama,10, stdin);
		}
		if(i == 2){
			gotoxy(50,15);fgets(pemain2.nama,10, stdin);
		}
	}
}
void tampilan_input_nickname(){
	gotoxy(49,12);printf("\033[1;37mP L A Y E R %d", permainan.jumlah_permain+1);
	gotoxy(47,13);printf("N I C K N A M E ?");
	gotoxy(43,14);printf("+----------------------+");
	gotoxy(43,15);printf("|                      |");
	gotoxy(43,16);printf("+----------------------+");
	gotoxy(46,17);printf("M A X  1 0  C H A R\033[0m");
	//gotoxy(50,15);fgets(pemain1.nama,10, stdin);
	permainan.jumlah_permain++;
}


/*================================================================================================================*/
void mulai_permainan(){
	/*deklarasi*/
	int ulangi;
	pemain1.simbol = 'X';
	pemain2.simbol = 'O';
	computer.simbol = 'O';
	pemain1.score = 0;
	pemain2.score = 0;
	computer.score = 0;
	char winner = ' ';
	/*Algoritma*/
	do{
	system("cls");
	cetak_papan();
	hapus_papan();
		while((winner = ' ') && (cek_papan_penuh())){
			do{
			game_board_permainan();
			giliran_pemain(pemain1);
			}while(permainan.invalid_move);
			winner = cek_menang();
			if((winner == 'X') || (winner == 'O') || cek_papan_penuh() == false){
				game_board_permainan();
				gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
				sleep(5);
				break;
			}
			if(permainan.input_cara_bermain == 1){
				giliran_computer(computer);
				winner = cek_menang();
				if((winner == 'X') || (winner == 'O') || cek_papan_penuh() == false){
					game_board_permainan();
					gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
					sleep(5);
					break;
				}		
			} else {
				do{
				game_board_permainan();
				giliran_pemain(pemain2);
				}while(permainan.invalid_move);
				winner = cek_menang();
				if((winner == 'X') || (winner == 'O') || cek_papan_penuh() == false){
					gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
					sleep(5);
					break;
				}
			}
		}
	ulangi_permainan(winner);
	}while(permainan.main_lagi == 1);
	hitung_score();
	keluar_permainan();
	permainan.input_awal = 2;
}
/*================================================================================================================*/


void hapus_papan(){
	for (int i = 0; i < papan.ukuran; i++){
		for(int j=0; j < papan.ukuran; j++){
			papan.kotak[i][j] = ' ';
		}
	}
}
void game_board_permainan(){
	//cetak_papan();
	tampilan_color_X_O();
	tampilan_player_biner();
	tampilan_row_colums();
	tampilan_nama_player();
	tampilan_score();
	tampilan_aksesoris_tiktaktoe();
	if (permainan.invalid_move){
		gotoxy(86,25);printf("Invalid Move!");
	} else {
		gotoxy(86,25);printf("             ");
	}
}
void cetak_papan(){
	for(int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if((papan.kotak[i][j] != ' ') || (papan.kotak[i][j] != 'X') || (papan.kotak[i][j] != 'O')){
			papan.kotak[i][j] = '0';
			}
		}
	}
	for (int i = 3; i <= 17; i++){
		if (i % 2 == 1){
			gotoxy(40,i);printf("+---+---+---+---+---+---+---+");
		}
		if (i % 2 == 0){
			gotoxy(40,i);printf("|   |   |   |   |   |   |   |");
		}
	}
}
void tampilan_color_X_O(){
	int a, b;
	a = 0;
	for (int i = 3; i <= 17;i++){
		b = 0;
		for (int j = 40; j <= 66; j++){
			if ((i % 2 == 0) && (j % 4 == 2)){
				if(papan.kotak[a][b] == 'X'){
				gotoxy(j,i);printf("\033[0;31m%c\033[0m", papan.kotak[a][b]);
				} else if (papan.kotak[a][b] == 'O'){
					gotoxy(j,i);printf("\033[0;32m%c\033[0m", papan.kotak[a][b]);
					} else {
						gotoxy(j,i);printf("\033[1;30m%c\033[0m", papan.kotak[a][b]);
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
	if (permainan.input_cara_bermain == 1){
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
	gotoxy(16,4); printf("\033[1;37m%s", pemain1.nama);
	if (permainan.input_cara_bermain == 1){
		gotoxy(84,4); printf("C O M P U T E R");	
	} else {
		gotoxy(86,4); printf("%s", pemain2.nama);
	}
}
void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : %d", pemain1.score);
	if (permainan.input_cara_bermain == 1){
		gotoxy(84,15); printf("S C O R E : %d", computer.score);
	} else {
		gotoxy(84,15); printf("S C O R E : %d", pemain2.score);
	}
}
void tampilan_aksesoris_tiktaktoe(){
	gotoxy(8,20);
	printf("010101 01 101010    010101   1001   101010    101010 0110010 010101      +--------------------+\n");
	printf("         10   10 01          10    01  10  01          01   10   01 10           |ROW    :            |\n");
	printf("        01   01 10          01   10101001 10          10   01   10 011001        +--------------------+\n");
	printf("       10   10 01          10   01    10 01          01   10   01 10             |COLUMS :            |\n");
	printf("      01   01 101010      01   10    01 101010      10   0101010 010101          +--------------------+\n");
}
void giliran_pemain(Pemain pemain){
	permainan.invalid_move = false;
	int baris, kolom;
	gotoxy(91,19); 
	if(pemain.simbol == 'X'){
		printf("\033[0;31m%c\033[0m", pemain.simbol);
	} else {
		printf("\033[0;32m%c\033[0m", pemain.simbol);
	}
	gotoxy(91,21); scanf("%d", &baris);
	baris--;
	gotoxy(91,23);scanf("%d", &kolom);
	kolom--;
	getchar();
	
	if(cek_tempat_kosong(baris, kolom)){
		papan.kotak[baris][kolom] = pemain.simbol;
	} else {
		permainan.invalid_move = true;
	}
}
void giliran_computer(Pemain pemain){
	int baris, kolom;
	do {
		baris = rand() % papan.ukuran;
		kolom = rand() % papan.ukuran;
		if(cek_tempat_kosong(baris, kolom)){
			papan.kotak[baris][kolom] = pemain.simbol;
			break;
		}
	}while(papan.kotak[baris][kolom] != ' ');
}
bool cek_tempat_kosong(int baris, int kolom){
	if(papan.kotak[baris][kolom] == ' '){
		return true;
	}else{
		return false;
	}
}
char cek_menang(){
	char menang;
    switch (papan.ukuran){
        case 3 : menang = cek_menang_3x3(); 
                 return menang;
                 break;
        case 5 : menang = cek_menang_5x5(); 
                 return menang;
                 break;
        case 7 : menang = cek_menang_7x7();
                 return menang;
                 break;
    }
}
char cek_menang_3x3(){
	/*Check Row*/
	for (int i = 0; i < 3; i++){
		if((papan.kotak[i][0] == papan.kotak[i][1])&&(papan.kotak[i][1] == papan.kotak[i][2])){
			return papan.kotak[i][0];
		}
	}
	/*Check Colums*/
	for (int i = 0; i < 3; i++){
		if((papan.kotak[0][i] == papan.kotak[1][i])&&(papan.kotak[1][i] == papan.kotak[2][i])){
			return papan.kotak[0][i];
		}
	}
	/*Check Diagonals*/
	if((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][2])){
		return papan.kotak[0][0];
	}
	if((papan.kotak[0][2] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][0])){
		return papan.kotak[0][2];
	}
	
	return ' ';
}
char cek_menang_5x5(){
    /*Cek Row */
    for(int i = 0; i < 5; i++){
        if(((papan.kotak[i][0] == papan.kotak[i][2]) || (papan.kotak[i][4] == papan.kotak[i][2])) && (((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3])) && (papan.kotak[i][2] != ' '))){
        	return papan.kotak[i][2];
		}
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if(((papan.kotak[0][i] == papan.kotak[2][i]) || (papan.kotak[4][i] == papan.kotak[2][i])) && (((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i])) && (papan.kotak[2][i] != ' '))){
			return papan.kotak[2][i];
    	}
	}
    /*Cek Diagonals\*/
    if((papan.kotak[1][0] != ' ') && (((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak[2][1] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][3])) && (papan.kotak[4][3] == papan.kotak[1][0]))){
    	return papan.kotak[1][0];
	}
	if((papan.kotak[0][1] != ' ') && (((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][3])) && ((papan.kotak[2][3] == papan.kotak[3][4])) && (papan.kotak[3][4] == papan.kotak[0][1]))){
    	return papan.kotak[0][1];
	}
	if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][0] == papan.kotak [2][2]) || (papan.kotak[4][4] == papan.kotak [2][2])) && (((papan.kotak[1][1] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][3])) && (papan.kotak[3][3] == papan.kotak [1][1])))){
		return papan.kotak[2][2];
	}
	/*Cek Diagonals/*/
	if((papan.kotak[0][3] != ' ') && (((papan.kotak[0][3] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][1])) && ((papan.kotak[2][2] == papan.kotak[3][0]) && (papan.kotak[3][0] == papan.kotak[0][3])))){
    	return papan.kotak[0][3];
	}
	if((papan.kotak[1][4] != ' ') && (((papan.kotak[1][4] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][1])) && (papan.kotak[4][1] == papan.kotak[1][4]))){
    	return papan.kotak[1][4];
	}
	if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][4] == papan.kotak [2][2]) || (papan.kotak[4][0] == papan.kotak [2][2])) && (((papan.kotak[1][3] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][1])) && (papan.kotak[3][1] == papan.kotak [1][3])))){
		return papan.kotak[2][2];
	}
    return ' ';
}
char cek_menang_7x7(){
    /*Cek Row */
    for(int i = 0; i < 7; i++){
        if((papan.kotak[i][0] == papan.kotak[i][1]) && (papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4])){
	   		return papan.kotak[i][0];
    	}
        if((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][5])){
             return papan.kotak[i][1];
        }
        if((papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][5]) && (papan.kotak[i][5] == papan.kotak[i][6])){
            return papan.kotak[i][2];
        }
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if((papan.kotak[0][i] == papan.kotak[1][i]) && (papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i])){
			return papan.kotak[0][i];
    	}
        if((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[5][i])){
	    	return papan.kotak[1][i];
        }
        if((papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[5][i]) && (papan.kotak[5][i] == papan.kotak[6][i])){
	    	return papan.kotak[2][i];
        }
    }
    /*Cek Diagonals \*/
    if((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4])){
        return papan.kotak[0][0];
    }
    if((papan.kotak[1][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[5][5])){
        return papan.kotak[1][1];
    }
    if((papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[5][5]) && (papan.kotak[5][5] == papan.kotak[6][6])){
        return papan.kotak[2][2];
    }
    if((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5])){
        return papan.kotak[0][1];
    }
    if((papan.kotak[1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5]) && (papan.kotak[4][5] == papan.kotak[5][6])){
        return papan.kotak[1][2];
    }
    if((papan.kotak[0][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[4][6])){
        return papan.kotak[0][2];
    }
    if((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak[2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4])){
        return papan.kotak[1][0];
    }
    if((papan.kotak[2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4]) && (papan.kotak[5][4] == papan.kotak[6][5])){
        return papan.kotak[2][1];
    }
    if((papan.kotak[2][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[6][4])){
        return papan.kotak[2][0];
    }
    /*Cek Diagona; /*/
    if((papan.kotak[4][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[0][4])){
        return papan.kotak[4][0];
    }
    if((papan.kotak[5][0] == papan.kotak[4][1]) && (papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4])){
        return papan.kotak[5][0];
    }
    if((papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4]) && (papan.kotak[1][4] == papan.kotak[0][5])){
        return papan.kotak[4][1];
    }
    if((papan.kotak[6][0] == papan.kotak[5][1]) && (papan.kotak[5][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4])){
        return papan.kotak[6][0];
    }
    if((papan.kotak[5][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[1][5])){
        return papan.kotak[5][1];
    }
    if((papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[1][5]) && (papan.kotak[1][5] == papan.kotak[0][6])){
        return papan.kotak[4][2];
    }
    if((papan.kotak[6][1] == papan.kotak[5][2]) && (papan.kotak[5][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5])){
        return papan.kotak[6][1];
    }
    if((papan.kotak[5][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5]) && (papan.kotak[2][5] == papan.kotak[1][6])){
        return papan.kotak[5][2];
    }
    if((papan.kotak[6][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[2][6])){
        return papan.kotak[6][2];
    }
    
    return ' ';
}
bool cek_papan_penuh(){
	for(int i = 0; i < papan.ukuran; i++){
		for (int j = 0; j < papan.ukuran; j++){
			if(papan.kotak[i][j] == ' '){
				return true;
			}
		}
	}
	return false;
}


void ulangi_permainan(char winner){
	do{
	system("cls");
	if(winner == 'X'){
		tampilan_wins(pemain1.nama);
		tampilan_champion();
		pemain1.score++;	
	} else if (winner == 'O'){
		if(permainan.input_cara_bermain == 1){
			tampilan_wins(pemain1.nama);
			gotoxy(31,7);printf("C O M P U T E R");
			computer.score++;
		}
			tampilan_wins(pemain2.nama);
			tampilan_champion();
			pemain2.score++;
		} else {
			tampilan_tie();
			tampilan_good();
		}
	tampilan_input_main_lagi();
	}while(permainan.penentu_main_lagi);
}
void tampilan_wins(Pemain player){
	gotoxy(31,7); printf("%s", player.nama);
	gotoxy(19,9); printf("\033[1;37m00     11  10  101   01  01 101001");
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
	gotoxy(15,13); printf("01    00       101011       11    01  100001\033[0m");
}
void tampilan_champion(){
	gotoxy(61,3); printf("\033[0;33m 1010                          0110 ");
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
	gotoxy(61,18); printf("    10101110001010110111000100\033[0m");
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
	gotoxy(23,16); printf("1. Y A");
	gotoxy(23,17); printf("2. T I D A K");
	gotoxy(23,15); printf("M A I N  L A G I ? ");scanf("%d", &permainan.main_lagi);
	if((permainan.main_lagi == 1) || (permainan.main_lagi == 2)){
		permainan.penentu_main_lagi = false;
	} else {
		permainan.penentu_main_lagi = true;
	}
}


void hitung_score(){
	system("cls");
	tampilan_champion();
	int j = 1;
	gotoxy(13,2); printf(" N O       N I C K N A M E       S C O R E");
	for (int i = 3; i < 24; i++){
		if (i % 2 == 1){
			gotoxy(13,i); printf("+-----+-------------------------+----------+");
		} else if (j < 10){
			gotoxy(13,i); printf("| %d.  |                         |          |", j);
			j++;
		} else {
			gotoxy(13,i); printf("| %d. |                         |          |", j);
		}
	}
	sleep(10);
}


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}