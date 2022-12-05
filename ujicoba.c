#include<stdio.h>
#include<stdlib.h>

int main(){
	long int pass, username, ID, password;
	password = 12345678;
	ID = 12345678;
	do {
		printf("Masukan ID: ");
		scanf("%i", &username); // input username dengan angka "12345678"
		printf("Masukan password: ");
		scanf("%i", &pass); // input password dengan angka "12345678"
		if ((password == pass) && (username == ID)){
			printf("Password anda benar!\n\n");
		} else 	{
			printf("Password anda salah\n\n");
		}
	} while ((pass !=password)&&(username !=ID));
	
	return 0;
}
