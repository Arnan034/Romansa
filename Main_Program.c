

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
    int jam;
    int menit;
    int detik;
}Time;

void cetak_menu_awal();

void pilih_pemain();

void pilih_dimensi_papan();

void cetak_papan();
void tampilan_player_biner();
void tampilan_row_colums();
void tampilan_nama_player();
void tampilan_papan();
void tampilan_score();
void mulai_permainan();
void giliran_pemain();
void bot_mudah();

void giliran_pemain();
char cek_menang(char flag);
char cek_menang_3x3(Papan papan);
char cek_menang_5x5(Papan papan);
char cek_menang_7x7(Papan papan);
bool cek_tempat_kosong(Papan papan, int baris, int kolom);
bool cek_papan_penuh(Papan papan);

void cetak_hasil_permainan();
int ulangi_permainan();
void hapus_papan(Papan *papan);

void simpan_skor();
void hitung_skor();

void gotoxy(int x, int y);
void gotoxy(int x, int y);

int main(){
	Pemain pemain1, pemain2;
	Papan papan;
	

	pilih_pemain(&pemain1, &pemain2);
	pilih_dimensi_papan(&papan);   
	mulai_permainan();        
	cetak_hasil_permainan();
	ulangi_permainan();
	simpan_skor();
}

void cetak_menu_awal(){

}

void pilih_pemain(Pemain *pemain1, Pemain *pemain2){

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

void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : 0");
	gotoxy(83,15); printf("S C O R E : 0");
}
	do{	
		printf("Enter row #(1-3): ");
		scanf("%d", &baris);
		baris--;
		printf("Enter column #(1-3): ");
		scanf("%d", &kolom);
		kolom--;
		
		if (cek_tempat_kosong(papan, baris, kolom)){
			papan.kotak[baris][kolom] = pemain.simbol;
			break;
		} else {
			printf("Invalid Move!\n");
		}
	}while(papan.kotak[baris][kolom] != ' ');
}

void giliran_pemain(Pemain pemain, Papan papan){
    int baris;
	int kolom;
	

	do{	
		printf("Enter row #(1-3): ");
		scanf("%d", &baris);
		baris--;
		printf("Enter column #(1-3): ");
		scanf("%d", &kolom);
		kolom--;
		
		if (cek_tempat_kosong(papan, baris, kolom)){
			papan.kotak[baris][kolom] = pemain.simbol;
			break;
		} else {
			printf("Invalid Move!\n");
		}
	}while(papan.kotak[baris][kolom] != ' ');
}

Void bot_mudah(){
int x, y;
	x = rand() % 7;
	y = rand() % 7;
}

char cek_menang(char flag){
	char menang;
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

char cek_menang_3x3(Papan papan){
	/*Check Row*/
	for (int i = 0; i < 3; i++){
		if((papan.kotak[i][0] == papan.kotak[i][1])&&(papan.kotak [i][0] == papan.kotak[i][2])){
			return papan.kotak[i][0];
		}
	}
	/*Check Colums*/
	for (int i = 0; i < 3; i++){
		if((papan.kotak[0][i] == papan.kotak[1][i])&&(papan.kotak [0][i] == papan.kotak[2][i])){
			return papan.kotak[0][i];
		}
	}
	/*Check Diagonals*/
	if((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[0][0] == papan.kotak[2][2])){
		return papan.kotak[0][0];
	}
	if((papan.kotak[0][2] == papan.kotak[1][1]) && (papan.kotak[0][2] == papan.kotak[2][0])){
		return papan.kotak[0][2];
	}
	
	return ' ';
}

char cek_menang_5x5(Papan papan){
    /*Cek Row */
    for(int i = 0; i < 5; i++){
        if((papan.kotak[i][0] == papan.kotak[i][1]) && (papan.kotak [i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3])){
	   		return papan.kotak[i][0];
    	}
        if((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak [i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4])){
             return papan.kotak[i][0];
        }
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if((papan.kotak[0][i] == papan.kotak[1][i]) && (papan.kotak [1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i])){
			return papan.kotak[0][i];
    	}
        if((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak [2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i])){
	    	return papan.kotak[1][i];
        }
    }
    /*Cek Diagonals*/
    if ((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak [1][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[3][3])){
        return papan.kotak[0][0];
    }
    if ((papan.kotak[1][1] == papan.kotak[2][2]) && (papan.kotak [2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4])){
        return papan.kotak[1][1];
    }
    if ((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak [1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4])){
        return papan.kotak[0][1];
    }
    if ((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak [2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3])){
        return papan.kotak[1][0];
    }
    if ((papan.kotak[3][0] == papan.kotak[2][1]) && (papan.kotak [2][1] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[3][0])){
        return papan.kotak[3][0];
    }
    if ((papan.kotak[4][0] == papan.kotak[3][1]) && (papan.kotak [3][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[1][3])){
        return papan.kotak[4][0];
    }
    if ((papan.kotak[3][1] == papan.kotak[2][2]) && (papan.kotak [2][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[0][4])){
        return papan.kotak[3][1];
    }
    if ((papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak [3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4])){
        return papan.kotak[4][1];
    }
    
    return ' ';
}

char cek_menang_7x7(Papan papan){
    /*Cek Row */
    for(int i = 0; i < 7; i++){
        if((papan.kotak[i][0] == papan.kotak[i][1]) && (papan.kotak [i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4])){
	   		return papan.kotak[i][0];
    	}
        if((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak [i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][5])){
             return papan.kotak[i][1];
        }
        if((papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak [i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][5]) && (papan.kotak[i][5] == papan.kotak[i][6])){
            return papan.kotak[i][2];
        }
    }
    /*Cek Colums*/
	for (int i = 0; i < 5; i++){
        if((papan.kotak[0][i] == papan.kotak[1][i]) && (papan.kotak [1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i])){
			return papan.kotak[0][i];
    	}
        if((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak [2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[5][i])){
	    	return papan.kotak[1][i];
        }
        if((papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak [3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[5][i]) && (papan.kotak[5][i] == papan.kotak[6][i])){
	    	return papan.kotak[2][i];
        }
    }
    /*Cek Diagonals \*/
    if((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak [1][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4])){
        return papan.kotak[0][0];
    }
    if((papan.kotak[1][1] == papan.kotak[2][2]) && (papan.kotak [2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[5][5])){
        return papan.kotak[1][1];
    }
    if((papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak [3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[5][5]) && (papan.kotak[5][5] == papan.kotak[6][6])){
        return papan.kotak[2][2];
    }
    if((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak [1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5])){
        return papan.kotak[0][1];
    }
    if((papan.kotak[1][2] == papan.kotak[2][3]) && (papan.kotak [2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5]) && (papan.kotak[4][5] == papan.kotak[5][6])){
        return papan.kotak[1][2];
    }
    if((papan.kotak[0][2] == papan.kotak[1][3]) && (papan.kotak [1][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[4][6])){
        return papan.kotak[0][2];
    }
    if((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak [2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4])){
        return papan.kotak[1][0];
    }
    if((papan.kotak[2][1] == papan.kotak[3][2]) && (papan.kotak [3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4]) && (papan.kotak[5][4] == papan.kotak[6][5])){
        return papan.kotak[2][1];
    }
    if((papan.kotak[2][0] == papan.kotak[3][1]) && (papan.kotak [3][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[6][4])){
        return papan.kotak[2][0];
    }
    /*Cek Diagona; /*/
    if((papan.kotak[4][0] == papan.kotak[3][1]) && (papan.kotak [3][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[0][4])){
        return papan.kotak[4][0];
    }
    if((papan.kotak[5][0] == papan.kotak[4][1]) && (papan.kotak [4][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4])){
        return papan.kotak[5][0];
    }
    if((papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak [3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4]) && (papan.kotak[1][4] == papan.kotak[0][5])){
        return papan.kotak[4][1];
    }
    if((papan.kotak[6][0] == papan.kotak[5][1]) && (papan.kotak [5][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4])){
        return papan.kotak[6][0];
    }
    if((papan.kotak[5][1] == papan.kotak[4][2]) && (papan.kotak [4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[1][5])){
        return papan.kotak[5][1];
    }
    if((papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak [3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[1][5]) && (papan.kotak[1][5] == papan.kotak[0][6])){
        return papan.kotak[4][2];
    }
    if((papan.kotak[6][1] == papan.kotak[5][2]) && (papan.kotak [5][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5])){
        return papan.kotak[6][1];
    }
    if((papan.kotak[5][2] == papan.kotak[4][3]) && (papan.kotak [4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5]) && (papan.kotak[2][5] == papan.kotak[1][6])){
        return papan.kotak[5][2];
    }
    if((papan.kotak[6][2] == papan.kotak[5][3]) && (papan.kotak [5][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[2][6])){
        return papan.kotak[6][3];
    }
    
    return ' ';
}
bool cek_tempat_kosong(Papan papan,int baris, int kolom){
	if(papan.kotak[baris][kolom] == ' '){
		return true;
	}else{
		return false;
	}
}

bool cek_papan_penuh;

void cetak_hasil_permainan(){

}

int ulangi_permainan(){
    
}

void hapus_papan(Papan *papan){
	for (int i=0; i < papan->ukuran; i++){
		for(int j=0; i < papan->ukuran; j++){
			papan->kotak[i][j] = ' ';
		}
	}
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
