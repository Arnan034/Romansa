#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y);
int main() {
	int i,j;
	int ukuran;
	scanf("%d", &ukuran);
	for(i = 0; i < ukuran * 3 ; i++) {
		for(j = 0; j < ukuran; j++) {
2			if(j == 0) printf("\n");
			if(i % 3 == 2 ) {
				printf("___");
			} else if( i % 3 == 1) {
				printf("   %c   |");
			} else {
				printf("       |");
			}
		}
	}
	return 0;
}


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}