/*
Program	: TicTacToe.c
Deskripsi : Permainan Tic Tac Toe
Author : Arnanda Prasatya (AP), Bhisma Chandra (BC), Revandi Faudiamar (RF)
Tanggal : 12/21/2022
*/

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<unistd.h>
#include<pthread.h>

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
	int input_more;
	int main_lagi;
	bool invalid_move;
	bool penentu_player;
	bool penentu_dimensi;
	bool penentu_main_lagi;
	bool cursor;
	bool stoptimer1;
	bool stoptimer2;
}Permainan;

typedef struct{
	int second;
}Time;

Permainan permainan;
Papan papan;
Pemain pemain1, pemain2, computer;
Time Timer;

void cetak_menu_awal();
/*prosedur cetak menu awal dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Tampilan untuk menampilkan menu belum tertampil
  FS : Tampilan menu sudah tertampil 
*/
	void tampilan_tiktaktoe();
/*prosedur ini sebagai tampilan sebuah teks tik tak toe
  IS : Tampilan teks tik tak tou belum tertampil
  FS : Tampilan teks tik tak toe sudah tertampil 
*/
	void tampilan_cetak_menu_awal();
/*prosedur ini untuk menampilkan teks "1 PLAY" dan "2 EXIT"
  IS : Tampilan teks "1 PLAY" dan "2 EXIT" belum tertampil
  FS : Tampilan teks "1 PLAY" dan "2 EXIT" sudah tertampil 
*/
	
void keluar_permainan();
/*prosedur ini untuk mencetak keluar permainan dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Opsi untuk keluar permainan belum ada
  FS : Opsi untuk keluar permainan sudah ada 
*/
void more();
/*prosedur ini untuk menampilkan opsi dari how to play dan high score dari game tersebut
  IS : Opsi untuk melihat how to play dan high score belum ada
  FS : Opsi untuk melihat how to play dan high score sudah ada 
*/
	void tampilan_more();
/*prosedur ini untuk menampilkan teks 1 how to play dan 2 high score
  IS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" belum tertampil
  FS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" sudah tertampil 
*/

	void how_to_play();
/*prosedur ini digunakan untuk menampilkan tata cara bermain game ini
  IS : Tatacara bermain game belum ada
  FS : Tatacara bermain game sudah ada 
*/

void pilih_pemain();
/*prosedur pilih pemain dengan tujuan player memilih dengan siapa dia bermain singgle atau multiplayer 
  IS : Belum dapat menentukan mode permainan (singgle atau multiplayer)
  FS : Sudah dapat menentukan mode permainan (singgle atau multiplayer)
*/
	void tampilan_pilih_pemain();
/*prosedur ini untuk mencetak tampilan dari 1 single ,2 multi, dan kotak persegi panjang untuk inputan
  IS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan belum tertampil
  FS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan sudah tertampil
*/
	
void pilih_dimensi_papan();
/*prosedur pilih dimensi papan untuk mencetak papan yang sesuai inputannya yang menjadi sebuah jenis papan
  IS : Belum memilih dimensi / jenis papan yang dimainkan
  FS : Sudah memilih dimensi / jenis papan yang dimainkan
*/
	void tampilan_pilih_dimensi_papan();
/*prosedur ini untuk mencetak tampilan dari jenis papan dan memilih dimensi papan
  IS : Tampilan dari jenis papan dan memilih dimensi papan belum ada
  FS : Tampilan dari jenis papan dan memilih dimensi papan sudah ada
*/

void tampilan_nickname();
/*prosedur ini untuk menginputkan nickname pemain
  IS : Belum dapat untuk memberikan nickname pemain
  FS : Dapat memberikan nickname pemain
*/
	void tampilan_input_nickname();
/*prosedur ini untuk mencetak tampilan dari persegi inputan dan memanggil beberapa modul sebelumnya sebagai tampilan
  IS : Tampilan tempat untuk menginputkan pemilihan ukuran papan belum ada
  FS : Tampilan tempat menginputkan pemilihan ukuran papan sudah ada
*/

void mulai_permainan();
/*prosedur mulai permaian prosedur adalah sebuah alur dari sebuah permaianan mulai dari cetak papan hingga penampilan high score
  IS : Belum dapat memulai permainan
  FS : Permainan sudah dapat dimulai
*/
	void hapus_papan();
/*prosedur ini untuk menghapus papan menjadi ' ' atau kotak kosong 
  IS : Papan masih terisi
  FS : Papan sudah menjadi kosong
*/
	void game_board_permainan();
/*prosedur ini berfungsi untuk mencetak alur permaianan dan desain dari sebuah permainan
  IS : Tampilan-tampilan pada gameboard belum ada
  FS : Tampilan-tampilan pada gameboard sudah ada
*/
		void cetak_papan();
/*prosedur ini untuk mencetak tampilan dari papan game yang dipilih
  IS : Papan yang sudah dipiih belum muncul atau belum tercetak
  FS : Papan yang sudah dipiih sudah muncul atau tercetak
*/
		void tampilan_color_X_O();
/*prosedur ini sebagai tampilan warna dalam simbol X berwarna merah dan simbol O berwarna hijau
  IS : Warna simbol belum berubah atau masih putih
  FS : Warna simbol menjadi memiliki warna (simbol X berwarna merah dan simbol O berwarna hijau)
*/
		void tampilan_player_biner();	
/*prosedur ini untuk mencetak tampilan dari emotikon dari orang atau computer yang didesain menggunakan angka 0 dan 1
  IS : Tidak aaa emotikon dari player
  FS : Ada emotikon dari player
*/
		void tampilan_nama_player();
/*prosedur ini untuk mencetak tampilan dari nama player yang sudah diinputkan
  IS : Tampilan nama player belum muncul
  FS : Tampilan nama player muncul
*/
		void tampilan_score();
/*prosedur ini untuk mencetak tampilan dari score dari tiap pemain
  IS : Tampilan score dari tiap player belum muncul
  FS : Tampilan score dari tiap player muncul
*/
		void tampilan_aksesoris_tiktaktoe();
/*prosedur ini untuk mencetak tampilan dari teks tik tak toe
  IS : Tampilan teks "TIK TAK TOE" tidak ada
  FS : Tampilan teks "TIK TAK TOE" ada
*/	
	void giliran_pemain();
/*prosedur ini berfungsi untuk menentukan giliran pemain bermain untuk bergerak (antara player 1 dan 2)
  IS : Tidak ada pergiliran move dari player 1 dan 2
  FS : Ada pergiliran move dari player 1 dan 2
*/	
	void giliran_computer();
/*prosedur ini berfungsi untuk membuat pergerakan komputer
  IS : Tidak ada pergerakan dari komputer
  FS : Ada pergerakan dari komputer
*/	
	bool cek_tempat_kosong();
/*function ini berfungsi untuk mengecek apakah kotak yang di inputkan oleh pemain itu kosong atau tidak
  IS : Belum mengetahui apakah kotak itu terisi apa tidak
  FS : Mengetahui apakah kotak itu terisi apa tidak
*/
	char cek_menang();
/*function ini berfungsi untuk mengecek pemenang dari game sesuai dengan dimensi papan
  IS : Belum mengetahui siapa pemenang game
  FS : Mengetahui siapa pemenang game
*/
	bool cek_papan_penuh();
/*function ini berfungsi untuk mengecek papan apakah papan tersebut sudah terisi semua atau tidak
  IS : Belum mengetahui papan tersebut sudah terisi semua atau tidak
  FS : Mengetahui papan tersebut sudah terisi semua atau tidak
*/
	
void ulangi_permainan(char winner);
/*prosedur ini berfungsi untuk mengulangi permainan berdasarkan input yang di masukan
  IS : Belum ada opsi pengulangan permainan
  FS : Terdapat opsi pengulangan permainan
*/
	void tampilan_wins();
/*prosedur ini untuk mencetak tampilan dari teks wins jika ada pemenang
  IS : Tidak ada tampilan teks "WIN'S"
  FS : Tampilan teks "WIN'S" tertampil
*/
	void tampilan_tie();
/*prosedur ini untuk mencetak tampilan dari teks tie jika seri
  IS : Tidak ada tampilan teks "TIE"
  FS : Tampilan teks "TIE" tertampil
*/
	void tampilan_champion();
/*prosedur ini untuk mencetak tampilan piala
  IS : Tidak ada tampilan piala
  FS : Tampilan piala tertampil
*/
	void tampilan_good();
/*prosedur ini untuk mencetak tampilan dari emotikon memberikan jempol dengan arti goodjob
  IS : Tidak ada tampilan jempol
  FS : Tampilan jempol tertampil
*/
	void tampilan_input_main_lagi();
/*prosedur ini untuk mencetak dan membaca masukan dari player apakah ingin bermain lagi atau tidak
  IS : Tidak ada opsi untuk bermain lagi
  FS : Ada opsi untuk bermain lagi
*/
	void masukkan_score_baru (Pemain pemain_baru);
/*prosedur ini untuk memasukkan score pemain setelah selesai bermain ke dalam file
  IS : Tidak ada tempat untuk menyimpan score pemain
  FS : Ada tempat untuk menyimpan score pemain
*/
	void tukar_posisi_pemain(Pemain *pemain1, Pemain *pemain2);
/*prosedur ini untuk menukar isi dua tipe data Pemain sesuai tingginya score
  IS : Posisi pemain belum tertukar
  FS : Posisi pemain sudah tertukan
*/
	void tampilkan_highscore();
/*prosedur ini untuk mencetak tampilan dari high score yang pernah bermain
  IS : Tampilan high score dalam game belum tertampil
  FS : Tampilan high score dalam game tertampil
*/

void *timer_pemain1();
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 1
  IS : Tampilan dari timer untuk pemain 1 belum tertampil
  FS : Tampilan dari timer untuk pemain 1 tertampil
*/
void *timer_pemain2();
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 2
  IS : Tampilan dari timer untuk pemain 2 belum tertampil
  FS : Tampilan dari timer untuk pemain 2 tertampil
*/

void gotoxy(int x, int y);
/*prosedur ini untuk menentukan tata letak sesuai koordinat x dan y yang diberikan
  IS : Tampilan tata letak masih default atau masih diujung kiri atas
  FS : Tampilan tata letak sudah sesuai dengan koordinat (x dan y) yang dimasukkan
*/


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
		if((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99)){
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
		}
		if(permainan.input_awal == 1){
			pilih_pemain();
			pilih_dimensi_papan();
			tampilan_nickname();
			mulai_permainan();
		}
		if(permainan.input_awal == 2){
			keluar_permainan();//keluar permainan
			return 0;	
		}
		if(permainan.input_awal == 99){
			more();
		}
	}while((permainan.input_awal != 1) || (permainan.input_awal != 2) || (permainan.input_awal != 99));//loop ini berfungsi apabila player menginputkan selain dari 1 / 2 maka tidak akan keluar dan terjadinya looping
}
/*================================================================================================================*/
/*================================================================================================================*/

/*prosedur cetak menu awal dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Tampilan untuk menampilkan menu belum tertampil
  FS : Tampilan menu sudah tertampil 
*/
void cetak_menu_awal(){
	tampilan_tiktaktoe();
	tampilan_cetak_menu_awal();
}
/*prosedur ini sebagai tampilan sebuah teks tik tak toe
  IS : Tampilan teks tik tak tou belum tertampil
  FS : Tampilan teks tik tak toe sudah tertampil 
*/
void tampilan_tiktaktoe(){
	gotoxy(19,2);printf("\033[1;37m010101  01  101010      010101    1001    101010      101010  0110010  010101");
	gotoxy(21,3);printf("10    10  01            10     01  10   01            01    10   01  10");
	gotoxy(21,4);printf("01    01  10            01    10101001  10            10    01   10  011001");
	gotoxy(21,5);printf("10    10  01            10    01    10  01            01    10   01  10");
	gotoxy(21,6);printf("01    01  101010        01    10    01  101010        10    0101010  010101\033[0m");
}
/*prosedur ini untuk menampilkan teks "1 PLAY" dan "2 EXIT"
  IS : Tampilan teks "1 PLAY" dan "2 EXIT" belum tertampil
  FS : Tampilan teks "1 PLAY" dan "2 EXIT" sudah tertampil 
*/
void tampilan_cetak_menu_awal(){
	gotoxy(33,8);printf("\033[1;32m11        1010011  01        1000    11    11");
	gotoxy(33,9);printf("01        01   10  10      01  10     10  01");
	gotoxy(33,10);printf("00        0010101  01      10101001    1101");
	gotoxy(33,11);printf("01        10       00      10    01     01");
	gotoxy(33,12);printf("10        01       101010  00    10     10\033[0m");

	gotoxy(33,14); printf("\033[1;31m010101        010111   10   00   01   010010");
	gotoxy(33,15); printf("    10        10        01 01    00     10");
	gotoxy(33,16); printf("010101        001101     111     11     01");
	gotoxy(33,17); printf("10            10        10 10    00     10");
	gotoxy(33,18); printf("010101        100101   01   01   10     01\033[0m");

	gotoxy(45,19);printf("1 / 2 / 99 (M O R E)");
	gotoxy(43,20);printf("\033[1;37m+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &permainan.input_awal);getchar();
}

/*prosedur ini untuk mencetak keluar permainan dengan tujuan untuk memanggil prosedur yang ada dibawah
  IS : Opsi untuk keluar permainan belum ada
  FS : Opsi untuk keluar permainan sudah ada 
*/
void keluar_permainan(){
	system("cls");
	
	gotoxy(20,2);printf("\033[1;37m101010   10  01     101     101   00   11  10   10    11   101001   01  11");
	gotoxy(22,3);printf("10     01  10    10 10    0101  10   01 01     10  01    01  00   10  00");
	gotoxy(22,4);printf("10     110101   1110011   01 11 10   1001       0101     10  10   01  10");
	gotoxy(22,5);printf("01     01  10   10   10   11  0100   00 10       01      01  10   10  01");
	gotoxy(22,6);printf("00     00  10   01   00   01   101   10  10      00      101001   100101");

	gotoxy(45,8);printf("011010   000101   100110");
	gotoxy(45,9);printf("00       10  01   01  10");
	gotoxy(45,10);printf("111011   10  01   100011");
	gotoxy(45,11);printf("01       01  10   10 11 ");
	gotoxy(45,12);printf("01       101001   01  00");

	gotoxy(27,14); printf("101011   10         010     01    01   01   011   01   0111010");
	gotoxy(27,15); printf("01  01   01        10 11     10  11    11   1100  11   11     ");
	gotoxy(27,16); printf("101110   11       1000101     1001     11   01 10 01   10  111");
	gotoxy(27,17); printf("10       01       10   01      10      01   01  1001   01   01");
	gotoxy(27,18); printf("01       110100   00   11      01      10   10   001   1010101\033[0m");
}

/*prosedur ini untuk menampilkan opsi dari how to play dan high score dari game tersebut
  IS : Opsi untuk melihat how to play dan high score belum ada
  FS : Opsi untuk melihat how to play dan high score sudah ada 
*/
void more(){
	system("cls");
	do{
		tampilan_tiktaktoe();
		tampilan_more();
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
		if (permainan.input_more == 1){
			how_to_play();break;
		}
		if (permainan.input_more == 2){
			tampilkan_highscore();break;
		}
	}while((permainan.input_more != 1) || (permainan.input_more != 2));
}
/*prosedur ini untuk menampilkan teks 1 how to play dan 2 high score
  IS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" belum tertampil
  FS : Tampilan teks "1 HOW TO PLAY" dan "2 HIGH SCORE" sudah tertampil 
*/
void tampilan_more(){
	gotoxy(18,8);printf("\033[1;34m11      01  10 110101 10     01   110110 010001   1010011 01       1000   11    11");
	gotoxy(18,9);printf("01      01  11 10  11 10     01     10   11  11   01   10 10     01  10    10  01");
	gotoxy(18,10);printf("00      101011 00  00 10  1  11     00   01  11   0010101 01     10101001   1101");
	gotoxy(18,11);printf("01      10  10 01  10 11 101 11     11   01  01   10      00     10    01    01");
	gotoxy(18,12);printf("10      11  11 011101  111 101      01   110011   01      101010 00    10    10");

	gotoxy(23,14); printf("\033[0;33m010101      01  11 10 101011 10  00   010011 010010 100010 10100  111110");
	gotoxy(23,15); printf("    10      10  00 11 00     00  11   10     11     11  01 11  10 00");
	gotoxy(23,16); printf("010101      001101 01 11 111 110011   010010 00     00  10 01010  010010 ");
	gotoxy(23,17); printf("10          10  01 01 01  01 10  10       11 10     11  11 11 10  11");
	gotoxy(23,18); printf("010101      10  01 10 100101 01  01   101001 110101 010101 10  11 101001");

	gotoxy(52,19);printf("\033[1;37m1 / 2 ");
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &permainan.input_more);getchar();
}

/*prosedur ini digunakan untuk menampilkan tata cara bermain game ini
  IS : Tatacara bermain game belum ada
  FS : Tatacara bermain game sudah ada 
*/
void how_to_play(){
	system("cls");
	int back;
	gotoxy(47,2);printf("H O W  T O  P L A Y !!\n");
	gotoxy(18,3);printf("===============================================================================\n");
	gotoxy(18,4);printf("|| 1. Pilih cara bermain apakah ingin single player atau multi player.       ||\n");
	gotoxy(18,5);printf("|| 2. Pilih papan yang ingin dimainkan apakah 3 x 3, 5 x 5, 7 x 7            ||\n");
	gotoxy(18,6);printf("|| 3. Masukan nama player                                                    ||\n");
	gotoxy(18,7);printf("|| 4. Pemain pertama bermain terlebih dahulu dengan simbol X                 ||\n");
	gotoxy(18,8);printf("|| 5. Pemain kedua bermain dengan simbil O dan tidak boleh menempati tempat  ||\n");
	gotoxy(18,9);printf("||    yang sama baik itu dengan pemain X atau tempat yang diisikan sebelumnya||\n");
	gotoxy(18,10);printf("|| 6. Teruslah bergiliran menggambar simbol masing-masing sampai salah satu  ||\n");
	gotoxy(18,11);printf("||    pemain telah menggambar tiga, empat atau lima simbol dalam satu deret  ||\n");
	gotoxy(18,12);printf("||    atau sampai tidak ada pemain yang dapat menang                         ||\n");
	gotoxy(18,13);printf("|| 7. Apabila terdapat pemenang maka highscore akan bertambah 1              ||\n");
	gotoxy(18,14);printf("|| 8. Apabila papan terpenuhi dan tidak ada yang membentuk deret maka        ||\n");
	gotoxy(18,15);printf("||    permainan dikatakan seri                                               ||\n");
	gotoxy(18,16);printf("|| 9. Teruslah berlatih dan jadilah JUARA                                    ||\n");
	gotoxy(18,17);printf("===============================================================================\n\n");
	do{
	gotoxy(49,19);printf("99 (B A C K)");
	gotoxy(43,20);printf("\033[1;37m+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &back);getchar();
	gotoxy(43,23);printf("I N V A L I D  C O D E !!");
	}while (back != 99);
	system("cls");
}

/*prosedur pilih pemain dengan tujuan player memilih dengan siapa dia bermain singgle atau multiplayer 
  IS : Belum dapat menentukan mode permainan (singgle atau multiplayer)
  FS : Sudah dapat menentukan mode permainan (singgle atau multiplayer)
*/
void pilih_pemain(){
	system("cls");
	do{
	tampilan_tiktaktoe();
	tampilan_pilih_pemain();
	}while(permainan.penentu_player);
}
/*prosedur ini untuk mencetak tampilan dari 1 single ,2 multi, dan kotak persegi panjang untuk inputan
  IS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan belum tertampil
  FS : Tampilan teks "1 SINGLE", "2 MULTI" dan kotak persegi panjang untuk inputan sudah tertampil
*/
void tampilan_pilih_pemain(){
	gotoxy(31,8);printf("\033[1;32m11        100011  01  011   01  1000010  01      101010");
	gotoxy(31,9);printf("01        01      10  1010  10  01       01      10");
	gotoxy(31,10);printf("00        000101  01  10 01 01  10  101  10      011010");
	gotoxy(31,11);printf("01            10  00  01  1001  10   01  11      10");
	gotoxy(31,12);printf("10        100100  11  10   001  0100110  100101  010110\033[0m");

	gotoxy(31,14); printf("\033[1;34m010101        010   100  01  11  00      101000  10");//51
	gotoxy(31,15); printf("    10        1010 1011  10  00  01        01    01");
	gotoxy(31,16); printf("010101        11 101 01  11  01  01        00    10");
	gotoxy(31,17); printf("10            10     10  10  10  00        10    10");
	gotoxy(31,18); printf("010101        10     01  100101  101001    11    01\033[0m");

	gotoxy(52,19);printf("\033[1;37m1 / 2 ");
	gotoxy(43,20);printf("+----------------------+");
	gotoxy(43,21);printf("|                      |");
	gotoxy(43,22);printf("+----------------------+");
	gotoxy(54,21);scanf("%d", &permainan.input_cara_bermain);getchar();
	if((permainan.input_cara_bermain == 1) || (permainan.input_cara_bermain == 2)){
		permainan.penentu_player = false;
	} else {
		permainan.penentu_player = true;
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
	
	}
}

/*prosedur pilih dimensi papan untuk mencetak papan yang sesuai inputannya yang menjadi sebuah jenis papan
  IS : Belum memilih dimensi / jenis papan yang dimainkan
  FS : Sudah memilih dimensi / jenis papan yang dimainkan
*/
void pilih_dimensi_papan(){
	system("cls");
	do{
	tampilan_pilih_dimensi_papan();
	}while(permainan.penentu_dimensi);
}
/*prosedur ini untuk mencetak tampilan dari jenis papan dan memilih dimensi papan
  IS : Tampilan dari jenis papan dan memilih dimensi papan belum ada
  FS : Tampilan dari jenis papan dan memilih dimensi papan sudah ada
*/
void tampilan_pilih_dimensi_papan(){
	gotoxy(40,2);printf("\033[1;32m1010101      01   10      0101011");
	gotoxy(43,3);printf("110       10 01           110");
	gotoxy(37,4);printf("0101001        011        1101011");
	gotoxy(40,5);printf("010       10 01           101");
	gotoxy(35,6);printf("1101001      01   10      0101000\033[0m");

	gotoxy(39,8);printf("\033[0;33m11010101      01   10     00101011");
	gotoxy(38,9);printf("110            10 01      110");
	gotoxy(37,10);printf("00110101        011       01110101");
	gotoxy(41,11);printf("010       10 01           101");
	gotoxy(35,12);printf("11010001      01   10     10111000\033[0m");

	gotoxy(39,14); printf("\033[0;31m11010101      01   10     10101011");
	gotoxy(43,15); printf("110       10 01           110");
	gotoxy(42,16); printf("001        011            011");
	gotoxy(41,17); printf("010       10 01           101");
	gotoxy(40,18); printf("001      01   10          000\033[0m");

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
		gotoxy(43,23);printf("I N V A L I D  C O D E !!");
	}
}

/*prosedur ini untuk menginputkan nickname pemain
  IS : Belum dapat untuk memberikan nickname pemain
  FS : Dapat memberikan nickname pemain
*/
void tampilan_nickname(){
	for(int i = 1; i <= permainan.input_cara_bermain; i++){
		system("cls");
		tampilan_tiktaktoe();
		tampilan_input_nickname();
		if(i == 1){
			gotoxy(50,15);scanf("%s", pemain1.nama);
		}
		if(i == 2){
			gotoxy(50,15);scanf("%s", pemain2.nama);
		}
	}
}
/*prosedur ini untuk mencetak tampilan dari persegi inputan dan memanggil beberapa modul sebelumnya sebagai tampilan
  IS : Tampilan tempat untuk menginputkan pemilihan ukuran papan belum ada
  FS : Tampilan tempat menginputkan pemilihan ukuran papan sudah ada
*/
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

/*prosedur mulai permaian prosedur adalah sebuah alur dari sebuah permaianan mulai dari cetak papan hingga penampilan high score
  IS : Belum dapat memulai permainan
  FS : Permainan sudah dapat dimulai
*/
void mulai_permainan(){
	/*deklarasi*/
	int ulangi;
	pemain1.simbol = 'X';
	pemain2.simbol = 'O';
	computer.simbol = 'O';
	pemain1.score = 0;
	pemain2.score = 0;
	computer.score = 0;
	char winner = ' ';//untuk mendeklarasikan char pemenang masih kosong
	pthread_t timer_1, timer_2;
	/*Algoritma*/
	do{
	system("cls");
	cetak_papan();
	hapus_papan();
		while((winner = ' ') && (cek_papan_penuh())){
			permainan.stoptimer1 = false;
			pthread_create(&timer_1, NULL, *timer_pemain1, NULL);
			pthread_join(&timer_1, NULL);
			do{
			game_board_permainan();
			giliran_pemain(pemain1);
			}while(permainan.invalid_move);
			permainan.stoptimer1 = true;
			winner = cek_menang();
			if((winner != ' ') || cek_papan_penuh() == false){
				game_board_permainan();
				if(cek_papan_penuh() == false){
					gotoxy(46,18);printf("G A M E  T I E !");
				} else {
					gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
				}
				sleep(5);
				break;
			}
			if(permainan.input_cara_bermain == 1){
				giliran_computer(computer);
				winner = cek_menang();
				if((winner != ' ') || cek_papan_penuh() == false){
					game_board_permainan();
					if(cek_papan_penuh() == false){
						gotoxy(46,18);printf("G A M E  T I E !");
					} else {
						gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
					}
					sleep(5);
					break;
				}		
			} else {	
				permainan.stoptimer2 = false;
				pthread_create(&timer_2, NULL, *timer_pemain2, NULL);
				pthread_join(&timer_2, NULL);
				do{
				game_board_permainan();
				giliran_pemain(pemain2);
				}while(permainan.invalid_move);
				permainan.stoptimer2 = true;
				winner = cek_menang();
				if((winner != ' ') || cek_papan_penuh() == false){
					if(cek_papan_penuh() == false){
						gotoxy(46,18);printf("G A M E  T I E !");
					} else {
						gotoxy(41,18); printf("W E  H A V E  W I N N E R !");
					}
					sleep(5);
					break;
				}
			}
		}
	ulangi_permainan(winner);
	}while(permainan.main_lagi == 1);
	if(pemain1.score!=0){
	masukkan_score_baru (pemain1);
	}
	if(pemain2.score!=0){
	masukkan_score_baru (pemain2);
	}
	tampilkan_highscore();
}
/*================================================================================================================*/

/*prosedur ini untuk menghapus papan menjadi ' ' atau kotak kosong 
  IS : Papan masih terisi
  FS : Papan sudah menjadi kosong
*/
void hapus_papan(){
	for (int i = 0; i < papan.ukuran; i++){
		for(int j=0; j < papan.ukuran; j++){
			papan.kotak[i][j] = ' ';
		}
	}
}
/*prosedur ini berfungsi untuk mencetak alur permaianan dan desain dari sebuah permainan
  IS : Tampilan-tampilan pada gameboard belum ada
  FS : Tampilan-tampilan pada gameboard sudah ada
*/
void game_board_permainan(){
	//cetak_papan();
	tampilan_color_X_O();
	tampilan_player_biner();
	tampilan_nama_player();
	tampilan_score();
	tampilan_aksesoris_tiktaktoe();
}
/*prosedur ini untuk mencetak tampilan dari papan game yang dipilih
  IS : Papan yang sudah dipiih belum muncul atau belum tercetak
  FS : Papan yang sudah dipiih sudah muncul atau tercetak
*/
void cetak_papan(){
	int l;
	for(int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if((papan.kotak[i][j] != ' ') || (papan.kotak[i][j] != 'X') || (papan.kotak[i][j] != 'O')){
			papan.kotak[i][j] = '0';
			}
		}
	}
	switch (papan.ukuran){
		case 3 :/*Cetak papan 3 x 3*/
				for (int i = 7; i <= 13; i++){
					if (i % 2 == 1){
						gotoxy(48,i);printf("+---+---+---+");
					}
					if (i % 2 == 0){
						gotoxy(48,i);printf("|   |   |   |");
					}
				}
				l = 1;
				printf("\033[1;31m");
				gotoxy(49,5); printf("C O L U M S");
				gotoxy(49,6); printf(" 1   2   3");
				gotoxy(44,8); printf("R");
				gotoxy(44,10); printf("O");
				gotoxy(44,12); printf("W");
				for (int i = 7; i <= 13;i++){
					if(i % 2 == 0){
						gotoxy(46,i);printf("%d", l);
					l++;
					}
				}break;
		case 5 : /*Cetak papan 5 x 5*/
				for (int i = 5; i <= 15; i++){
					if (i % 2 == 1){
						gotoxy(44,i);printf("+---+---+---+---+---+");
					}
					if (i % 2 == 0){
						gotoxy(44,i);printf("|   |   |   |   |   |");
					}
				}
				l = 1;
				printf("\033[1;31m");
				gotoxy(49,3); printf("C O L U M S");
				gotoxy(45,4); printf(" 1   2   3   4   5");
				gotoxy(40,8); printf("R");
				gotoxy(40,10); printf("O");
				gotoxy(40,12); printf("W");
				for (int i = 5; i <= 15;i++){
					if(i % 2 == 0){
						gotoxy(42,i);printf("%d", l);
					l++;
					}
				}break;
		case 7 : /*Cetak papan 7 x 7*/
				for (int i = 3; i <= 17; i++){
					if (i % 2 == 1){
						gotoxy(40,i);printf("+---+---+---+---+---+---+---+");
					}
					if (i % 2 == 0){
						gotoxy(40,i);printf("|   |   |   |   |   |   |   |");
					}
				}
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
				}break;
	}
}
/*prosedur ini sebagai tampilan warna dalam simbol X berwarna merah dan simbol O berwarna hijau
  IS : Warna simbol belum berubah atau masih putih
  FS : Warna simbol menjadi memiliki warna (simbol X berwarna merah dan simbol O berwarna hijau)
*/
void tampilan_color_X_O(){
	int a, b;
	switch (papan.ukuran){
		case 3 : /*warna X dan O untuk papan 3 x 3*/
				a = 0;
				for (int i = 7; i <= 13; i++){
					b = 0;
					for (int j = 48; j <= 58; j++){
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
				}break;
		case 5 : /*warna X dan O untuk papan 5 x 5*/
				a = 0;
				for (int i = 5; i <= 15; i++){
					b = 0;
					for (int j = 44; j <= 64; j++){
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
				}break;
		case 7 : /*warna X dan O untuk papan 7 x 7*/
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
				}break;
	}
}
/*prosedur ini untuk mencetak tampilan dari emotikon dari orang atau computer yang didesain menggunakan angka 0 dan 1
  IS : Tidak aaa emotikon dari player
  FS : Ada emotikon dari player
*/
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
/*prosedur ini untuk mencetak tampilan dari nama player yang sudah diinputkan
  IS : Tampilan nama player belum muncul
  FS : Tampilan nama player muncul
*/
void tampilan_nama_player(){
	gotoxy(16,4); printf("\033[1;37m%s", pemain1.nama);
	if (permainan.input_cara_bermain == 1){
		gotoxy(84,4); printf("C O M P U T E R");	
	} else {
		gotoxy(86,4); printf("%s", pemain2.nama);
	}
}
/*prosedur ini untuk mencetak tampilan dari score dari tiap pemain
  IS : Tampilan score dari tiap player belum muncul
  FS : Tampilan score dari tiap player muncul
*/
void tampilan_score(){
	gotoxy(14,15); printf("S C O R E : %d", pemain1.score);
	if (permainan.input_cara_bermain == 1){
		gotoxy(84,15); printf("S C O R E : %d", computer.score);
	} else {
		gotoxy(84,15); printf("S C O R E : %d", pemain2.score);
	}
}
/*prosedur ini untuk mencetak tampilan dari teks tik tak toe
  IS : Tampilan teks "TIK TAK TOE" tidak ada
  FS : Tampilan teks "TIK TAK TOE" ada
*/
void tampilan_aksesoris_tiktaktoe(){
	gotoxy(8,20);
	printf("010101 01 101010    010101   1001   101010    101010 0110010 010101      +--------------------+\n");
	printf("         10   10 01          10    01  10  01          01   10   01 10           |ROW    :            |\n");
	printf("        01   01 10          01   10101001 10          10   01   10 011001        +--------------------+\n");
	printf("       10   10 01          10   01    10 01          01   10   01 10             |COLUMS :            |\n");
	printf("      01   01 101010      01   10    01 101010      10   0101010 010101          +--------------------+\n");
}
/*prosedur ini berfungsi untuk menentukan giliran pemain bermain untuk bergerak (antara player 1 dan 2)
  IS : Tidak ada pergiliran move dari player 1 dan 2
  FS : Ada pergiliran move dari player 1 dan 2
*/	
void giliran_pemain(Pemain pemain){
	permainan.invalid_move = false;
	int baris, kolom;
	gotoxy(91,19); 
	if(pemain.simbol == 'X'){
		printf("\033[0;31m%c\033[0m", pemain.simbol);
	} else {
		printf("\033[0;32m%c\033[0m", pemain.simbol);
	}
	gotoxy(91,21);permainan.cursor = true;scanf("%d", &baris);
	baris--;
	gotoxy(91,23); permainan.cursor = false;
	scanf("%d", &kolom);
	kolom--;
	getchar();
	
	if(cek_tempat_kosong(baris, kolom)){
		papan.kotak[baris][kolom] = pemain.simbol;
		gotoxy(83,25);printf("                     ");
	} else if (papan.kotak[baris][kolom] == '0'){
			gotoxy(83,25);printf("                     ");
			gotoxy(86,25);printf("Invalid Move!");
			permainan.invalid_move = true;
		} else {
			gotoxy(83,25);printf("                      ");
			gotoxy(83,25);printf("Box Has been Placed");
			permainan.invalid_move = true;
		}
}
/*prosedur ini berfungsi untuk membuat pergerakan komputer
  IS : Tidak ada pergerakan dari komputer
  FS : Ada pergerakan dari komputer
*/	
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
/*function ini berfungsi untuk mengecek apakah kotak yang di inputkan oleh pemain itu kosong atau tidak
  IS : Belum mengetahui apakah kotak itu terisi apa tidak
  FS : Mengetahui apakah kotak itu terisi apa tidak
*/
bool cek_tempat_kosong(int baris, int kolom){
	if(papan.kotak[baris][kolom] == ' '){
		return true;
	}else{
		return false;
	}
}
/*function ini berfungsi untuk mengecek pemenang dari game sesuai dengan dimensi papan
  IS : Belum mengetahui siapa pemenang game
  FS : Mengetahui siapa pemenang game
*/
char cek_menang(){
    switch (papan.ukuran){
        case 3 : /*Cek Winner 3 x 3*/ 
				/*Check Row*/
				for (int i = 0; i < 3; i++){
					if((papan.kotak[i][1] != ' ') && (papan.kotak[i][0] == papan.kotak[i][1])&&(papan.kotak[i][1] == papan.kotak[i][2])){
						return papan.kotak[i][0];break;
					}
				}
				/*Check Colums*/
				for (int i = 0; i < 3; i++){
					if((papan.kotak[1][i] != ' ') && (papan.kotak[0][i] == papan.kotak[1][i])&&(papan.kotak[1][i] == papan.kotak[2][i])){
						return papan.kotak[0][i];break;
					}
				}
				/*Check Diagonals*/
				if((papan.kotak[1][1] != ' ') && (papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][2])){
					return papan.kotak[0][0];break;
				}
				if((papan.kotak[1][1] != ' ') && (papan.kotak[0][2] == papan.kotak[1][1]) && (papan.kotak[1][1] == papan.kotak[2][0])){
					return papan.kotak[0][2];break;
				}
				return ' '; break;
        case 5 : /*Cek Winner 5 x 5*/ 
				/*Cek Row */
    			for(int i = 0; i < 5; i++){
       				if(((papan.kotak[i][0] == papan.kotak[i][2]) || (papan.kotak[i][4] == papan.kotak[i][2])) && (((papan.kotak[i][1] == papan.kotak[i][2]) && (papan.kotak[i][2] == papan.kotak[i][3])) && (papan.kotak[i][2] != ' '))){
        				return papan.kotak[i][2];break;
					}
    			}
    			/*Cek Colums*/
				for (int i = 0; i < 5; i++){
        			if(((papan.kotak[0][i] == papan.kotak[2][i]) || (papan.kotak[4][i] == papan.kotak[2][i])) && (((papan.kotak[1][i] == papan.kotak[2][i]) && (papan.kotak[2][i] == papan.kotak[3][i])) && (papan.kotak[2][i] != ' '))){
					return papan.kotak[2][i];break;
    				}
				}
    			/*Cek Diagonals\*/
    			if((papan.kotak[1][0] != ' ') && (((papan.kotak[1][0] == papan.kotak[2][1]) && (papan.kotak[2][1] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][3])) && (papan.kotak[4][3] == papan.kotak[1][0]))){
    				return papan.kotak[1][0];break;
				}
				if((papan.kotak[0][1] != ' ') && (((papan.kotak[0][1] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][3])) && ((papan.kotak[2][3] == papan.kotak[3][4])) && (papan.kotak[3][4] == papan.kotak[0][1]))){
    				return papan.kotak[0][1];break;
				}
				if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][0] == papan.kotak [2][2]) || (papan.kotak[4][4] == papan.kotak [2][2])) && (((papan.kotak[1][1] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][3])) && (papan.kotak[3][3] == papan.kotak [1][1])))){
					return papan.kotak[2][2];break;
				}
				/*Cek Diagonals/*/
				if((papan.kotak[0][3] != ' ') && (((papan.kotak[0][3] == papan.kotak[1][2]) && (papan.kotak[1][2] == papan.kotak[2][1])) && ((papan.kotak[2][1] == papan.kotak[3][0]) && (papan.kotak[3][0] == papan.kotak[0][3])))){
    				return papan.kotak[0][3];break;
				}
				if((papan.kotak[1][4] != ' ') && (((papan.kotak[1][4] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][2])) && ((papan.kotak[3][2] == papan.kotak[4][1])) && (papan.kotak[4][1] == papan.kotak[1][4]))){
    				return papan.kotak[1][4];break;
				}
				if((papan.kotak[2][2] != ' ') && (((papan.kotak[0][4] == papan.kotak [2][2]) || (papan.kotak[4][0] == papan.kotak [2][2])) && (((papan.kotak[1][3] == papan.kotak [2][2]) && (papan.kotak[2][2] == papan.kotak [3][1])) && (papan.kotak[3][1] == papan.kotak [1][3])))){
					return papan.kotak[2][2];break;
				}
    			return ' ';break;
        case 7 :/*Cek Winner 7 x 7*/
				/*Cek Row */
    			for (int i = 0; i < 7; i++){
    				if((papan.kotak[i][3] != ' ') && ((papan.kotak[i][6] == papan.kotak[i][5]) && (papan.kotak[i][5] == papan.kotak[i][3]) || (papan.kotak[i][5] == papan.kotak[i][1]) && (papan.kotak[i][1] == papan.kotak[i][3]) || (papan.kotak[i][0] == papan.kotak[i][1]) && (papan.kotak[i][1] == papan.kotak[i][3])) && (papan.kotak[i][2] == papan.kotak[i][3]) && (papan.kotak[i][3] == papan.kotak[i][4]) && (papan.kotak[i][4] == papan.kotak[i][2])){
    					return papan.kotak[i][3];break;
					}
				}
    			/*Cek Diagonal\*/
				for (int i = 0; i < 7; i++){
    				if((papan.kotak[3][i] != ' ') && ((papan.kotak[6][i] == papan.kotak[5][i]) && (papan.kotak[5][i] == papan.kotak[3][i]) || (papan.kotak[5][i] == papan.kotak[1][i]) && (papan.kotak[1][i] == papan.kotak[3][i]) || (papan.kotak[0][i] == papan.kotak[1][i]) && (papan.kotak[1][i] == papan.kotak[3][i])) && (papan.kotak[2][i] == papan.kotak[3][i]) && (papan.kotak[3][i] == papan.kotak[4][i]) && (papan.kotak[4][i] == papan.kotak[2][i])){
    					return papan.kotak[3][i];break;
					}
				}
				/*Cek Diagonal/*/
				if((papan.kotak[4][2] != ' ') && (papan.kotak[2][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[4][2]) && (papan.kotak[4][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[6][4]) && (papan.kotak[6][4] == papan.kotak[2][0])){
					return papan.kotak[4][2];break;
				}
				if((papan.kotak[3][2] != ' ') && ((papan.kotak[1][0] == papan.kotak[3][2]) || (papan.kotak[6][5] == papan.kotak[3][2])) && ((papan.kotak[2][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[5][4]) && (papan.kotak[5][4] == papan.kotak[2][1]))){
					return papan.kotak[3][2];break;
				}
				if ((papan.kotak[3][3] != ' ') && (((papan.kotak[0][0] == papan.kotak[1][1]) && (papan.kotak[0][0] == papan.kotak[3][3])) || ((papan.kotak[1][1] == papan.kotak[5][5]) && (papan.kotak[5][5] == papan.kotak[3][3])) || ((papan.kotak[5][5] == papan.kotak[6][6]) && (papan.kotak[6][6] == papan.kotak[3][3]))) && (papan.kotak[2][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[2][2])){
					return papan.kotak[3][3];break;
				}
				if((papan.kotak[2][3] != ' ') && ((papan.kotak[0][1] == papan.kotak[2][3]) || (papan.kotak[5][6] == papan.kotak[2][3])) && ((papan.kotak[1][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[4][5]) && (papan.kotak[4][5] == papan.kotak[1][2]))){
					return papan.kotak[2][3];break;
				}
				if((papan.kotak[2][4] != ' ') && (papan.kotak[0][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[4][6]) && (papan.kotak[4][6] == papan.kotak[0][2])){
					return papan.kotak[2][4];break;
				}
				/*Cek Diagonal.*/
				if((papan.kotak[2][2] != ' ') && (papan.kotak[4][0] == papan.kotak[3][1]) && (papan.kotak[3][1] == papan.kotak[2][2]) && (papan.kotak[2][2] == papan.kotak[1][3]) && (papan.kotak[1][3] == papan.kotak[0][4]) && (papan.kotak[0][4] == papan.kotak[4][0])){
					return papan.kotak[2][2];break;
				}
				if((papan.kotak[3][2] != ' ') && ((papan.kotak[5][0] == papan.kotak[3][2]) || (papan.kotak[0][5] == papan.kotak[3][2])) && ((papan.kotak[4][1] == papan.kotak[3][2]) && (papan.kotak[3][2] == papan.kotak[2][3]) && (papan.kotak[2][3] == papan.kotak[1][4]) && (papan.kotak[1][4] == papan.kotak[4][1]))){
					return papan.kotak[3][2];break;
				}
				if ((papan.kotak[3][3] != ' ') && (((papan.kotak[6][0] == papan.kotak[5][1]) && (papan.kotak[6][0] == papan.kotak[3][3])) || ((papan.kotak[5][1] == papan.kotak[1][5]) && (papan.kotak[5][1] == papan.kotak[3][3])) || ((papan.kotak[1][5] == papan.kotak[0][6]) && (papan.kotak[0][6] == papan.kotak[3][3]))) && (papan.kotak[4][2] == papan.kotak[3][3]) && (papan.kotak[3][3] == papan.kotak[2][4]) && (papan.kotak[2][4] == papan.kotak[4][2])){
					return papan.kotak[3][3];break;
				}
				if((papan.kotak[4][3] != ' ') && ((papan.kotak[6][1] == papan.kotak[4][3]) || (papan.kotak[1][6] == papan.kotak[4][3])) && ((papan.kotak[5][2] == papan.kotak[4][3]) && (papan.kotak[4][3] == papan.kotak[3][4]) && (papan.kotak[3][4] == papan.kotak[2][5]) && (papan.kotak[2][5] == papan.kotak[5][2]))){
					return papan.kotak[4][3];break;
				}
				if((papan.kotak[4][4] != ' ') && (papan.kotak[6][2] == papan.kotak[5][3]) && (papan.kotak[5][3] == papan.kotak[4][4]) && (papan.kotak[4][4] == papan.kotak[3][5]) && (papan.kotak[3][5] == papan.kotak[2][6]) && (papan.kotak[2][6] == papan.kotak[6][2])){
					return papan.kotak[4][4];break;
				}
    			return ' ';break;
    }
}
/*function ini berfungsi untuk mengecek papan apakah papan tersebut sudah terisi semua atau tidak
  IS : Belum mengetahui papan tersebut sudah terisi semua atau tidak
  FS : Mengetahui papan tersebut sudah terisi semua atau tidak
*/
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

/*prosedur ini berfungsi untuk mengulangi permainan berdasarkan input yang di masukan
  IS : Belum ada opsi pengulangan permainan
  FS : Terdapat opsi pengulangan permainan
*/
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
/*prosedur ini untuk mencetak tampilan dari teks wins jika ada pemenang
  IS : Tidak ada tampilan teks "WIN'S"
  FS : Tampilan teks "WIN'S" tertampil
*/
void tampilan_wins(Pemain player){
	gotoxy(31,7); printf("%s", player.nama);
	gotoxy(19,9); printf("\033[1;37m00     11  10  101   01  01 101001");
	gotoxy(19,10); printf("10     00  11  0001  11   0 01");
	gotoxy(19,11); printf("01 100 10  00  11 01 01     101111");
	gotoxy(19,12); printf("1010 1011  10  00  1010         01");
	gotoxy(19,13); printf("100   111  00  10   110     101010");
}
/*prosedur ini untuk mencetak tampilan dari teks tie jika seri
  IS : Tidak ada tampilan teks "TIE"
  FS : Tampilan teks "TIE" tertampil
*/
void tampilan_tie(){
	gotoxy(15,9); printf("01  000101 00  010011     010111  01  010010");
	gotoxy(15,10); printf("11    00    1  01           10    10  10");
	gotoxy(15,11); printf("11    11       111011       01    11  011101");
	gotoxy(15,12); printf("00    01           00       00    11  01");
	gotoxy(15,13); printf("01    00       101011       11    01  100001\033[0m");
}
/*prosedur ini untuk mencetak tampilan piala
  IS : Tidak ada tampilan piala
  FS : Tampilan piala tertampil
*/
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
/*prosedur ini untuk mencetak tampilan dari emotikon memberikan jempol dengan arti goodjob
  IS : Tidak ada tampilan jempol
  FS : Tampilan jempol tertampil
*/
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
/*prosedur ini untuk mencetak dan membaca masukan dari player apakah ingin bermain lagi atau tidak
  IS : Tidak ada opsi untuk bermain lagi
  FS : Ada opsi untuk bermain lagi
*/
void tampilan_input_main_lagi(){
	gotoxy(23,16); printf("1. Y A");
	gotoxy(23,17); printf("2. T I D A K");
	gotoxy(23,15); printf("M A I N  L A G I ? ");scanf("%d", &permainan.main_lagi);getchar();
	if((permainan.main_lagi == 1) || (permainan.main_lagi == 2)){
		permainan.penentu_main_lagi = false;
	} else {
		permainan.penentu_main_lagi = true;
	}
}

/*prosedur ini untuk mencetak tampilan dari high score yang pernah bermain
  IS : Tampilan high score dalam game belum tertampil
  FS : Tampilan high score dalam game tertampil
*/
void tampilkan_highscore(){
	system("cls");
	tampilan_champion();
	int j = 1;
	
	Pemain data_file[10];
	FILE *fp;
	int total=0,banyak_data;
	int posisi=0;
	int kesamaan_nama;
	bool pernah_bermain = false;
	char ch = 0; 
 
	fp=fopen("HighScore.txt","r");
		while(ch!=EOF && total < 10){
			fscanf(fp,"%s%d",&data_file[total].nama,&data_file[total].score);  
			ch=fgetc(fp);
			total++;  
		}
	fclose(fp);
	total--;
	
	gotoxy(13,2); printf(" N O       N I C K N A M E       S C O R E");
	for (int i = 3; i < 24; i++){
		if (i % 2 == 1){
			gotoxy(13,i); printf("+-----+-------------------------+----------+");
		} else if (j < 10){
			gotoxy(13,i); printf("| %d.  |                         |          |", j);
				if(j-1<total){
					gotoxy(22,i); printf("%s", data_file[j-1].nama);
					gotoxy(50,i); printf("%d", data_file[j-1].score);
				}
			j++;
		} else {
			gotoxy(13,i); printf("| %d. |                         |          |", j);
		}
	}
	sleep(10);
	system("cls");
}
/*prosedur ini untuk memasukkan score pemain setelah selesai bermain ke dalam file
  IS : Tidak ada tempat untuk menyimpan score pemain
  FS : Ada tempat untuk menyimpan score pemain
*/
void masukkan_score_baru (Pemain pemain_baru){
	Pemain data_file[100];
	FILE *fp;
	int i=0,banyak_data=0;
	int posisi=0;
	int kesamaan_nama=1;
	bool pernah_bermain=false;
	char ch=0; 
 
	fp=fopen("HighScore.txt","r");
		while(ch!=EOF){
			fscanf(fp,"%s%d",&data_file[i].nama,&data_file[i].score);  
			ch=fgetc(fp);
			i++;  
		}
	fclose(fp);
	banyak_data=i-1;
	for (i=0; i < banyak_data; i++){
		kesamaan_nama=strcmp(pemain_baru.nama,data_file[i].nama);
		if (kesamaan_nama==0){
			data_file[i].score = data_file[i].score + pemain_baru.score;
			pernah_bermain = true;
			posisi = i; break;
		}
	}
	
	if(pernah_bermain == false){
		if(banyak_data!=0){
			posisi = banyak_data;
			banyak_data++;
		}
		data_file[posisi] = pemain_baru;
	}
	
	for (i=posisi; i>0; i--){
		if (data_file[i].score > data_file[i-1].score){
			tukar_posisi_pemain(&data_file[i], &data_file[i-1]);
		}
	}
	
	fp=fopen("HighScore.txt","w");
	i=0;
	do{
		fprintf(fp,"%s %d\n",data_file[i].nama,data_file[i].score);
		i++;
	}while(i<banyak_data);
	fclose(fp);
}
/*prosedur ini untuk menukar isi dua tipe data Pemain sesuai tingginya score
  IS : Posisi pemain belum tertukar
  FS : Posisi pemain sudah tertukan
*/
void tukar_posisi_pemain(Pemain *pemain1, Pemain *pemain2){
	Pemain temp;
	temp = *pemain1;
	*pemain1 = *pemain2;
	*pemain2 = temp;
}
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 1
  IS : Tampilan dari timer untuk pemain 1 belum tertampil
  FS : Tampilan dari timer untuk pemain 1 tertampil
*/
void *timer_pemain1(){
	for(Timer.second = 10;Timer.second >= 0;Timer.second--){
		sleep(1);
		gotoxy(51,18);printf("00:%.2d",Timer.second);
		//Timer.second--;
		if (permainan.cursor){
			gotoxy(91,21);
		} else {
			gotoxy(91,23);
		}
		if(permainan.stoptimer1){
			break;
		}
	}
	return NULL;
}
/*prosedur ini untuk mencetak tampilan dari timer untuk pemain 2
  IS : Tampilan dari timer untuk pemain 2 belum tertampil
  FS : Tampilan dari timer untuk pemain 2 tertampil
*/
void *timer_pemain2(){
	for(Timer.second = 10;Timer.second >= 0;Timer.second--){
		sleep(1);
		gotoxy(51,18);printf("00:%.2d",Timer.second);
		//Timer.second--;
		if (permainan.cursor){
			gotoxy(91,21);
		} else {
			gotoxy(91,23);
		}
		if(permainan.stoptimer2){
			break;
		}
	}
	return NULL;
}

/*prosedur ini untuk menentukan tata letak sesuai koordinat x dan y yang diberikan
  IS : Tampilan tata letak masih default atau masih diujung kiri atas
  FS : Tampilan tata letak sudah sesuai dengan koordinat (x dan y) yang dimasukkan
*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}