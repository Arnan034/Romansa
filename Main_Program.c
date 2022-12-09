<<<<<<< HEAD
#include<stdio.h>
#include<windows.h>
#include <stdio.h>
#include <stdbool.h>
>>>>>>> 6d63f32295d1e7c9e37e3ce9c740d5622f770c03

typedef struct(){
    char nama[10];
    char simbol;
    int score;
}Pemain;

typedef struct(){
    char kotak[7][7];
    int ukuran;
}Papan;

typedef struct(){
    int jam;
    int menit;
    int detik;
}Time;

void cetak_menu_awal();

void pilih_pemain();

void pilih_dimensi_papan();

void mulai_permainan();

void cetak_papan();

void tampilan_player_biner();

void tampilan_row_colums();

void tampilan_nama_player();

void tampilan_papan();

void tampilan_score();

void giliran_pemain();

char cek_menang(char flag);

char cek_menang_3x3();

char cek_menang_5x5();

char cek_menang_7x7();

bool cek_tempat_kosong(Papan papan);


void cetak_hasil_permainan();

int ulangi_permainan();

void hapus_papan(Papan *papan);

void timer();

void simpan_skor();

void hitung_skor();

<<<<<<< HEAD
void gotoxy(int x, int y);
=======
>>>>>>> 6d63f32295d1e7c9e37e3ce9c740d5622f770c03

int main(){

	cetak_menu_awal();
	pilih_pemain(Pemain *pemain1, Pemain *pemain2);
	pilih_dimensi_papan(Papan *papan);
	mulai_permainan();
	cetak_hasil_permainan();
	ulangi_permainan();
	simpan_skor();
}

void cetak_menu_awal(){

}

void pilih_pemain(){

}

void pilih_dimensi_papan(){

}

void mulai_permainan(){

}

void cetak_papan(){
    tampilan_papan();
	tampilan_player_biner();
	tampilan_row_colums();
	tampilan_nama_player();
	tampilan_score();
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
	gotoxy(16,4); printf("Arnanda");
	gotoxy(85,4); printf("Bhisma");
}

void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : 0");
	gotoxy(83,15); printf("S C O R E : 0");
}
void giliran_pemain(){
    int x;
	int y;
	
	do{	
		printf("Enter row #(1-3): ");
		scanf("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf("%d", &y);
		y--;
		
		if(board[x][y] != ' '){
			printf("Invalid Move!\n");
		} else {
			board[x][y] = /*player*/;
			break;
		}
	}while(board [x][y] != ' ');
}

char cek_menang(char flag){
    switch (flag){
        case 1 : menang = cek_menang_3x3; 
                 return menang;
                 break;
        case 2 : menang = cek_menang_5x5; 
                 return menang;
                 break;
        case 3 : menang = cek_menang_7x7;
                 return menang;
                 break;
    }
}

char cek_menang_3x3(){
	/*Check Row*/
	for (int i = 0; i < 3; i++){
		if((board[i][0] == board[i][1])&&(board [i][0] == board[i][2])){
			return board[i][0];
		}
	}
	/*Check Colums*/
	for (int i = 0; i < 3; i++){
		if((board[0][i] == board[1][i])&&(board [0][i] == board[2][i])){
			return board[0][i];
		}
	}
	/*Check Diagonals*/
	if((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])){
		return board[0][0];
	}
	if((board[0][2] == board[1][1]) && (board[0][2] == board[2][0])){
		return board[0][2];
	}
	
	return ' ';
}

char cek_menang_5x5(){
    /*Cek Row */
    for(int i = 0; i < 5; i++){
        if((board[i][0] == board[i][1]) && (board [i][1] == board[i][2]) && (board[i][2] == board[i][3])){
	   		return board[i][0];
    	}
        if((board[i][1] == board[i][2]) && (board [i][2] == board[i][3]) && (board[i][3] == board[i][4])){
             return board[i][0];
        }
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if((board[0][i] == board[1][i]) && (board [1][i] == board[2][i]) && (board[2][i] == board[3][i])){
			return board[0][i];
    	}
        if((board[1][i] == board[2][i]) && (board [2][i] == board[3][i]) && (board[3][i] == board[4][i])){
	    	return board[1][i];
        }
    }
    /*Cek Diagonals*/
    if ((board[0][0] == board[1][1]) && (board [1][1] == board[2][2]) && (board[2][2] == board[3][3])){
        return board[0][0];
    }
    if ((board[1][1] == board[2][2]) && (board [2][2] == board[3][3]) && (board[3][3] == board[4][4])){
        return board[1][1];
    }
    if ((board[0][1] == board[1][2]) && (board [1][2] == board[2][3]) && (board[2][3] == board[3][4])){
        return board[0][1];
    }
    if ((board[1][0] == board[2][1]) && (board [2][1] == board[3][2]) && (board[3][2] == board[4][3])){
        return board[1][0];
    }
    if ((board[3][0] == board[2][1]) && (board [2][1] == board[1][2]) && (board[1][2] == board[3][0])){
        return board[3][0];
    }
    if ((board[4][0] == board[3][1]) && (board [3][1] == board[2][2]) && (board[2][2] == board[1][3])){
        return board[4][0];
    }
    if ((board[3][1] == board[2][2]) && (board [2][2] == board[1][3]) && (board[1][3] == board[0][4])){
        return board[3][1];
    }
    if ((board[4][1] == board[3][2]) && (board [3][2] == board[2][3]) && (board[2][3] == board[1][4])){
        return board[4][1];
    }
    
    return ' ';
}

char cek_menang_7x7(){
    /*Cek Row */
    for(int i = 0; i < 7; i++){
        if((board[i][0] == board[i][1]) && (board [i][1] == board[i][2]) && (board[i][2] == board[i][3]) && (board[i][3] == [i][4])){
	   		return board[i][0];
    	}
        if((board[i][1] == board[i][2]) && (board [i][2] == board[i][3]) && (board[i][3] == board[i][4]) && (board[i][4] == [i][5])){
             return board[i][1];
        }
        if((board[i][2] == board[i][3]) && (board [i][3] == board[i][4]) && (board[i][4] == board[i][5]) && (board[i][5] == [i][6])){
            return board[i][2];
        }
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if((board[0][i] == board[1][i]) && (board [1][i] == board[2][i]) && (board[2][i] == board[3][i]) && (board[3][i] == board[4][i])){
			return board[0][i];
    	}
        if((board[1][i] == board[2][i]) && (board [2][i] == board[3][i]) && (board[3][i] == board[4][i]) && (board[4][i] == board[5][i])){
	    	return board[1][i];
        }
        if((board[2][i] == board[3][i]) && (board [3][i] == board[4][i]) && (board[4][i] == board[5][i]) && (board[5][i] == board[6][i])){
	    	return board[2][i];
        }
    }
    /*Cek Diagonals \*/
    if((board[0][0] == board[1][1]) && (board [1][1] == board[2][2]) && (board[2][2] == board[3][3]) && (board[3][3] == board[4][4])){
        return board[0][0];
    }
    if((board[1][1] == board[2][2]) && (board [2][2] == board[3][3]) && (board[3][3] == board[4][4]) && (board[4][4] == board[5][5])){
        return board[1][1];
    }
    if((board[2][2] == board[3][3]) && (board [3][3] == board[4][4]) && (board[4][4] == board[5][5]) && (board[5][5] == board[6][6])){
        return board[2][2];
    }
    if((board[0][1] == board[1][2]) && (board [1][2] == board[2][3]) && (board[2][3] == board[3][4]) && (board[3][4] == board[4][5])){
        return board[0][1];
    }
    if((board[1][2] == board[2][3]) && (board [2][3] == board[3][4]) && (board[3][4] == board[4][5]) && (board[4][5] == board[5][6])){
        return board[1][2];
    }
    if((board[0][2] == board[1][3]) && (board [1][3] == board[2][4]) && (board[2][4] == board[3][5]) && (board[3][5] == board[4][6])){
        return board[0][2];
    }
    if((board[1][0] == board[2][1]) && (board [2][1] == board[3][2]) && (board[3][2] == board[4][3]) && (board[4][3] == board[5][4])){
        return board[1][0];
    }
    if((board[2][1] == board[3][2]) && (board [3][2] == board[4][3]) && (board[4][3] == board[5][4]) && (board[5][4] == board[6][5])){
        return board[2][1];
    }
    if((board[2][0] == board[3][1]) && (board [3][1] == board[4][2]) && (board[4][2] == board[5][3]) && (board[5][3] == board[6][4])){
        return board[2][0];
    }
    /*Cek Diagona; /*/
    if((board[4][0] == board[3][1]) && (board [3][1] == board[2][2]) && (board[2][2] == board[1][3]) && (board[1][3] == board[0][4])){
        return board[4][0];
    }
    if((board[5][0] == board[4][1]) && (board [4][1] == board[3][2]) && (board[3][2] == board[2][3]) && (board[2][3] == board[1][4])){
        return board[5][0];
    }
    if((board[4][1] == board[3][2]) && (board [3][2] == board[2][3]) && (board[2][3] == board[1][4]) && (board[1][4] == board[0][5])){
        return board[4][1];
    }
    if((board[6][0] == board[5][1]) && (board [5][1] == board[4][2]) && (board[4][2] == board[3][3]) && (board[3][3] == board[2][4])){
        return board[6][0];
    }
    if((board[5][1] == board[4][2]) && (board [4][2] == board[3][3]) && (board[3][3] == board[2][4]) && (board[2][4] == board[1][5])){
        return board[5][1];
    }
    if((board[4][2] == board[3][3]) && (board [3][3] == board[2][4]) && (board[2][4] == board[1][5]) && (board[1][5] == board[0][6])){
        return board[4][2];
    }
    if((board[6][1] == board[5][2]) && (board [5][2] == board[4][3]) && (board[4][3] == board[3][4]) && (board[3][4] == board[2][5])){
        return board[6][1];
    }
    if((board[5][2] == board[4][3]) && (board [4][3] == board[3][4]) && (board[3][4] == board[2][5]) && (board[2][5] == board[1][6])){
        return board[5][2];
    }
    if((board[6][2] == board[5][3]) && (board [5][3] == board[4][4]) && (board[4][4] == board[3][5]) && (board[3][5] == board[2][6])){
        return board[6][3];
    }
    
    return ' ';
}
bool cek_tempat_kosong(Papan papan, int baris, int kolom){
	if(papan.kotak[baris][kolom] == ' '){
		return true;
	}else{
		return false;
	}
}

void cetak_hasil_permainan(){

}

int ulangi_permainan(){
    
}

void hapus_papan(Papan *papan){
	int i, j;
	
	for (i=0; i<papan.ukuran; i++){
		for(j=0; i<papan.ukuran){
			papan.kotak[i][j] = ' ';
		}
	}
}

void timer(){

}

void simpan_skor(){

}

void hitung_skor(){

}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}