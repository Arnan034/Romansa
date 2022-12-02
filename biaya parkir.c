#include<stdio.h>
#include<math.h>

//Bhisma

typedef struct{
	int hour, minute, second;
}Jam; // jam menggunakan format 24 Jam

typedef struct{
	char tipeKendaraan; // A
	int nomorPlat;
	Jam jamMasuk; // 8:35:59
	Jam jamKeluar; // 10:00:00
}Kendaraan;

void readKendaraanMasuk(Kendaraan *Kdrn);
/*Prosedur mencatat kendaraan masuk melalui pembacaan program
I.S.: kendaraan belum tercatat
F.S. : kendaraan sudah tercatat dengan mengisi informasi tipe kendaraan (A untuk motor dan B untuk mobil), 
       jam masuk dan jam keluar melalui pembacaan program. Jam masuk dan jam keluar menggunakan prosedure create jam.
	   Pada saat sebelum create jam, nilai atribut divalidasi dahulu sesuai dengan range jam yang valid. 
	   Jika input atribut jam tidak valid akan mengulang terus sampai semua nilai atribut jam valid.
*/

void readJam(Jam *J);
/* Prosedur membentuk jam berdasarkan berdasarkan pembacaan program
I.S. : Jam belum terbentuk
F.S. : Jam sudah terbentuk dengan membaca artibut jam dan memanggil createJam untuk membentuk jam
       Pada saat sebelum create jam, nilai atribut divalidasi dahulu sesuai dengan range jam yang valid. 
	   Jika input atribut jam tidak valid akan mengulang terus sampai semua nilai atribut jam valid.
*/

void createJam(int hh, int mm, int ss, Jam *J);
/* Prosedur membentuk jam berdasarkan parameter hh (hour), mm (minute) dan ss (second)
I.S. : Jam belum terbentuk
F.S. : Jam sudah terbentuk dengan mengisi atribut jam, yaitu hour = hh, minute = mm, dan second = ss
*/

int isValidJam(int hh, int mm, int ss);
/*Fungsi mengembalikan true jika atribut jam yang diinput sudah valid, yaitu 0<=hh<24, 0<=mm<60 dan 0<=ss<60*/

void setJamKeluarKendaraan(Kendaraan *Kdrn, Jam J);
/* Prosedur mengganti atribut Jam keluar berdasarkan parameter masukan Jam
I.S. : Kendaraan udah berisi nilai sembarang
F.S. : atribut Jam keluar pada kendaraan diganti dengan parameter masukan Jam
*/

void catatKendaraanMasuk(Kendaraan daftarKdrn[], Kendaraan Kdrn, int *sizeKendaraan);
/*Prosedur memasukan kendaraan yang baru masuk ke dalam daftar kendaraan yang sudah parkir
I.S. : daftar kendaraan belum bertambah
F.S. : daftar kendaraan sudah bertambah pada bagian elemen terakhir
*/

void cetakMenuSistemKendaraan();
/*Prosedur menampilkan menu sistem kendaraan
I.S. : Layar belum menampilkan pilihan menu
F.S. : Layar menampilkan pilihan menu antara 1 - 4 dan 99 untuk keluar dari menu, 
       jika tidak ada opsi yang sesuai maka menampilkan "Masukan tidak Valid"
       1 : Melihat Kendaraan yang parkir
       2 : Mencatat Kendaraan Baru Parkir
       3 : Mencatat Kendaraan Keluar
       4 : Melihat Daftar Tarif Parkir
       99 : Keluar Program
*/

void LihatKendaraan(Kendaraan daftarKendaraan[], int sizeKendaraan);
/*Prosedur melihat daftar kendaraan yang terparkir
I.S. : belum menampilkan daftar kendaraan
F.S. : menampilkan semua kendaraan yang terparkir dengan memanggil prosedur cetak kendaraan, 
       setiap kendaraan dipisahkan dengan bar
*/

void cetakKendaraan(Kendaraan Kdrn);
/*Prosedur melihat informasi kendaraan yang terparkir
I.S. : belum menampilkan informasi kendaraan
F.S. : menampilkan informasi kendaraan yang terparkir dengan format Tipe Kendaraan Nomor Plat, Jam Masuk dan Jam Keluar
*/

int cariKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan);
/*Fungsi mengembalikan true jika noor plat yang diinputkan ketemu pada daftar kendaraan, sebaliknya false*/

Kendaraan getKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan);
/*Fungsi mengembalikan kendaran sesuai dengan nomot plat
prekondisi : nomor plat dipastikan ada pada daftar kendaraan
*/

int getPosisiKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan);
/*Fungsi mengembalikan posisi kendaran sesuai dengan nomot plat
prekondisi : nomor plat dipastikan ada pada daftar kendaraan
*/

int calculationParkir(Kendaraan kendaraan);
/*Fungsi mengembalikan total harga parkir berdasarkan aturan berikut
Kendaraan    Lama Parkir (Jam)    Harga Parkir
A (Motor)   1 Jam Pertama          1000
A (Motor)   Jam Berikutnya         1500
B (Mobil)   1 Jam Pertama          3000
B (Mobil)   Jam Berikutnya         3500
*/

void hapusKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int *sizeKendaraan);
/*Prosedur menghapus kendaraan di daftar list kendaraan
I.S. : Kendaraan belum dihapus
F.S. : Kendaraan sudah dihapus, elemen kendaraan selanjutnya bergeser ke kiri
*/

void hapusKendaraanByPosisi(Kendaraan daftarKendaraan[], int posisiKdrn, int *sizeKendaraan);
/*Prosedur menghapus kendaraan di daftar list kendaraan
I.S. : Kendaraan belum dihapus
F.S. : Kendaraan sudah dihapus, elemen kendaraan selanjutnya bergeser ke kiri
*/

void cetakKendaraanKeluar(Kendaraan Kdrn, int hargaParkir);
/*Prosedur mencetak kendaraan yang keluar parkir
I.S. : Info kendaraan belum ditampilkan
F.S. : menampikan info kendaraan dengan memanggil cerakKendaraan dan harga parkirnya
*/

void cetakTarif();
/*Prosedur cetak daftar tarif
I.S. : Info tarif belum ditampilkan
F.S. : menampikan info tarif parkir kendaraan dengan ketentuan berikut
Kendaraan    Lama Parkir (Jam)    Harga Parkir
A (Motor)   1 Jam Pertama          1000
A (Motor)   Jam Berikutnya         1500
B (Mobil)   1 Jam Pertama          3000
B (Mobil)   Jam Berikutnya         3500
*/


void readKendaraanMasuk(Kendaraan *Kdrn){
	char type;
	int nPlat, hour, minute, second;
	Jam JMasuk, JKeluar;
	
	do {
		printf("\nTipe Kendaraan (A (Motor) / B (Mobil)): ");
		scanf("%c", &type);
	}while(type !='A' && type != 'B');
	
	printf("Nomor Plat: ");
	scanf("%d", &nPlat);
	
	do {
		printf("Jam Masuk (hh mm ss): ");
		scanf("%d %d %d", &hour, &minute, &second);
	}while(!isValidJam(hour, minute, second));
	
	createJam(hour, minute, second, &JMasuk);
	
	(*Kdrn).tipeKendaraan = type;
	(*Kdrn).nomorPlat = nPlat;
	(*Kdrn).jamMasuk = JMasuk;
	
}

/* Prosedur membentuk jam berdasarkan berdasarkan pembacaan program
I.S. : Jam belum terbentuk
F.S. : Jam sudah terbentuk dengan membaca artibut jam dan memanggil createJam untuk membentuk jam
       Pada saat sebelum create jam, nilai atribut divalidasi dahulu sesuai dengan range jam yang valid. 
	   Jika input atribut jam tidak valid akan mengulang terus sampai semua nilai atribut jam valid.
*/
void readJam(Jam *J){
	int hour, minute, second;
	do {
		printf("\nJam (hh mm ss): ");
		scanf("%d %d %d", &hour, &minute, &second);
	}while(!isValidJam(hour, minute, second));
	
	createJam(hour, minute, second, &(*J));
}

int isValidJam(int hh, int mm, int ss){
	if((hh>=0 && hh<24) && (mm>=0 && mm<60) && 
	    (ss>=0 && ss<60)){ //0<=hh<24, 0<=mm<60 dan 0<=ss<60
		return 1;
	}else{
		return 0;
	}
}

void createJam(int hh, int mm, int ss, Jam *J){
	(*J).hour = hh;
	(*J).minute = mm;
	(*J).second = ss;
}

/* Prosedur mengganti atribut Jam keluar berdasarkan parameter masukan Jam
I.S. : Kendaraan udah berisi nilai sembarang
F.S. : atribut Jam keluar pada kendaraan diganti dengan parameter masukan Jam
*/
void setJamKeluarKendaraan(Kendaraan *Kdrn, Jam J){
	(*Kdrn).jamKeluar = J;
}


void catatKendaraanMasuk(Kendaraan daftarKdrn[], Kendaraan Kdrn, int *sizeKendaraan){
    daftarKdrn[*sizeKendaraan] = Kdrn;
	(*sizeKendaraan) = (*sizeKendaraan) + 1;
}

menampilkan_menu_kendaraan(){
	
}

/*Prosedur menampilkan menu sistem kendaraan
I.S. : Layar belum menampilkan pilihan menu
F.S. : Layar menampilkan pilihan menu antara 1 - 4 dan 99 untuk keluar dari menu, 
       jika tidak ada opsi yang sesuai maka menampilkan "Masukan tidak Valid"
       1 : Melihat Kendaraan yang parkir
       2 : Mencatat Kendaraan Baru Parkir
       3 : Mencatat Kendaraan Keluar
       4 : Melihat Daftar Tarif Parkir
       99 : Keluar Program
*/
void cetakMenuSistemKendaraan(){
	printf("\n 1 : Melihat Kendaraan yang parkir");
	printf("\n 2 : Mencatat Kendaraan Baru Parkir");
	printf("\n 3 : Mencatat Kendaraan Keluar");
	printf("\n 4 : Melihat Daftar Tarif Parkir");
	printf("\n 99 : Keluar Program");
}

void LihatKendaraan(Kendaraan daftarKendaraan[], int sizeKendaraan){
	int i;
	if(sizeKendaraan > 0){
		printf("\nDaftar Kendaraan");
		printf("\n--------------------------");
		for(i=0; i<sizeKendaraan; i++){
			cetakKendaraan(daftarKendaraan[i]);
			printf("\n");
		}
	}else{
		printf("\nTidak ada Kendaraan pada Lahan Parkir\n");
	}
	
}

/*Prosedur melihat informasi kendaraan yang terparkir
I.S. : belum menampilkan informasi kendaraan
F.S. : menampilkan informasi kendaraan yang terparkir dengan format Tipe Kendaraan Nomor Plat, Jam Masuk dan Jam Keluar
*/
void cetakKendaraan(Kendaraan Kdrn){
	printf("\nTipe Kendaraan : %c", Kdrn.tipeKendaraan );
	printf("\nNomor Plat : %d", Kdrn.nomorPlat );
	printf("\nJam Masuk : %d : %d : %d", Kdrn.jamMasuk.hour, Kdrn.jamMasuk.minute, Kdrn.jamMasuk.second  );
}

/*Fungsi mengembalikan true jika noor plat yang diinputkan ketemu pada daftar kendaraan, sebaliknya false*/
int cariKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan){
	int index = 0;
	int result = 0;
	while(index < sizeKendaraan && result == 0){
		if (daftarKendaraan[index].nomorPlat == NPlat){
			result = 1;
		}
		index++;
	}
	return result;
}

/*Fungsi mengembalikan kendaran sesuai dengan nomot plat
prekondisi : nomor plat dipastikan ada pada daftar kendaraan
*/
Kendaraan getKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan){
	int index = 0;
	int result = 0;
	while(index < sizeKendaraan && result == 1){
		if (daftarKendaraan[index].nomorPlat == NPlat){
			result = index;
		}
		index++;
	}
	return daftarKendaraan[result];
}

/*Fungsi mengembalikan posisi kendaran sesuai dengan nomot plat
prekondisi : nomor plat dipastikan ada pada daftar kendaraan
*/
int getPosisiKendaraanByPlat(Kendaraan daftarKendaraan[], int NPlat, int sizeKendaraan){
	int index = 0;
	int result = 0;
	while(index < sizeKendaraan && result == 1){
		if (daftarKendaraan[index].nomorPlat == NPlat){
			result = index;
		}
		index++;
	}
	return result;
}


int calculationParkir(Kendaraan kendaraan){
	int harga = 0;
	int jamPertama = 0;
	int jamSelanjutnya = 0;
	switch(kendaraan.tipeKendaraan){
		case 'A': jamPertama = 1000;
		          jamSelanjutnya = 1500;
				  break;
		case 'B': jamPertama = 3000;
		          jamSelanjutnya = 3500;
				  break;
	}
	int totalSecondMasuk = kendaraan.jamMasuk.hour * 3600;
	totalSecondMasuk = totalSecondMasuk + (kendaraan.jamMasuk.minute * 60);
	totalSecondMasuk = totalSecondMasuk + (kendaraan.jamMasuk.second);

	int totalSecondKeluar = kendaraan.jamKeluar.hour * 3600;
	totalSecondKeluar = totalSecondKeluar + (kendaraan.jamKeluar.minute * 60);
	totalSecondKeluar = totalSecondKeluar + (kendaraan.jamKeluar.second);

	double totalParkir = (double) (totalSecondKeluar - totalSecondMasuk)/3600;
	int jamParkir = (int) ceil(totalParkir);
	return jamPertama + ((jamParkir - 1) * jamSelanjutnya);
}

/*Prosedur menghapus kendaraan di daftar list kendaraan
I.S. : Kendaraan belum dihapus
F.S. : Kendaraan sudah dihapus, elemen kendaraan selanjutnya bergeser ke kiri
*/
void hapusKendaraanByPosisi(Kendaraan daftarKendaraan[], int posisiKdrn, int *sizeKendaraan){
	int idx;
	for(idx = posisiKdrn; idx<(*sizeKendaraan); idx++){
		if ((idx + 1) < (*sizeKendaraan)){
			daftarKendaraan[idx] = daftarKendaraan[idx+1] ;
		}
	}
	(*sizeKendaraan) = (*sizeKendaraan) - 1;
}


void cetakKendaraanKeluar(Kendaraan Kdrn, int hargaParkir){
	printf("Tipe Kendaraan : %c \n", Kdrn.tipeKendaraan );
	printf("Nomor Plat : %d \n", Kdrn.nomorPlat );
	printf("Jam Masuk : %d : %d : %d \n", Kdrn.jamMasuk.hour, Kdrn.jamMasuk.minute, Kdrn.jamMasuk.second  );
	printf("Jam Keluar : %d : %d : %d \n", Kdrn.jamKeluar.hour, Kdrn.jamKeluar.minute, Kdrn.jamKeluar.second  );
    printf("Harga Parkir : %d \n\n", hargaParkir);
}

/*Prosedur cetak daftar tarif
I.S. : Info tarif belum ditampilkan
F.S. : menampikan info tarif parkir kendaraan dengan ketentuan berikut
Kendaraan    Lama Parkir (Jam)    Harga Parkir
A (Motor)   1 Jam Pertama          1000
A (Motor)   Jam Berikutnya         1500
B (Mobil)   1 Jam Pertama          3000
B (Mobil)   Jam Berikutnya         3500
*/
void cetakTarif(){
	printf("\nKendaraan    Lama Parkir (Jam)    Harga Parkir");
	printf("\nA (Motor)   Jam Berikutnya         1500");
	printf("\nA (Motor)   Jam Berikutnya         1500");
	printf("\nB (Mobil)   1 Jam Pertama          3000");
	printf("\nB (Mobil)   Jam Berikutnya         3500\n");
}

int main(){
	Kendaraan daftarKendaraan[100]; // maksimal jumlah kendaraan yang diparkir adalah 100 untuk mobil dan motor
	Kendaraan kendaraan;
	int opsi, NPlat, hargaParkir, posisiKendaraanKeluar;
	int ketemu, lagi; // 0 : false, 1 : true
	int sizeKendaraan = 0;
	Jam jKluar;
	
	cetakMenuSistemKendaraan();
	printf("\n\nPilih Opsi Menu: ");
	scanf("%d", &opsi);
	while(opsi != 99){
		switch(opsi){
			case 1: LihatKendaraan(daftarKendaraan, sizeKendaraan);
					break;
			case 2: readKendaraanMasuk(&kendaraan);
					catatKendaraanMasuk(daftarKendaraan, kendaraan, &sizeKendaraan);
					break;
			case 3: do{
						printf("\nNomor Plat Motor: ");
						scanf("%d", &NPlat);
						ketemu = cariKendaraanByPlat(daftarKendaraan, NPlat, sizeKendaraan);
						lagi = 0;
						if(ketemu==0){
							printf("\nKendaraan Tidak Ketemu");
							printf("\nMau Cari Plat Nomor Lagi(1(Ya), Selain 1 (Tidak)))): ");
							scanf("%d", &lagi);		
						}
					}while(lagi==1);
					if(ketemu==1){
						posisiKendaraanKeluar = getPosisiKendaraanByPlat(daftarKendaraan, NPlat, sizeKendaraan);
						kendaraan = getKendaraanByPlat(daftarKendaraan, NPlat, sizeKendaraan);
						readJam(&jKluar);
						setJamKeluarKendaraan(&kendaraan,jKluar);
						hargaParkir = calculationParkir(kendaraan);
						hapusKendaraanByPosisi(daftarKendaraan, posisiKendaraanKeluar, &sizeKendaraan);
						cetakKendaraanKeluar(kendaraan, hargaParkir);
					}else{
						printf("\nKendaraan yang dicari tidak ada");	
					}
					break;
			case 4: cetakTarif(); 
			        break;
			default: printf("\nMasukan Tidak Valid");
		}
		cetakMenuSistemKendaraan();
		printf("\n\nPilih Opsi Menu: ");
		scanf("%d", &opsi);
	}
}
