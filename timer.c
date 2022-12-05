
#include <stdio.h>
#include <windows.h>

main(){
 int i, j, k, x, y;

 scanf("%d", &x);
 printf("\nTekan Ctrl + C atau Ctrl + Pause Break untuk berhenti !!\n");
 system("pause");
 for(i = 0; i <= 60;){//jam
  for(j = 0; j <= 60;){//menit
   for(k = x; k <= 60;){//detik
    Sleep(100);
    printf("Stopwatch = %d : %d : %d\n", i, j, k);
    Sleep(900);
    system("cls");
    k--;
    if(k == 60){
     k = 0;
     j--;
    }
    if(j == 60){
     j = 0;
     i--;
    }
    if(k==0){
    	return 0;
	}
   }
  }
 scanf("%d", &y);
 }
}