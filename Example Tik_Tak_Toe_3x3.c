#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char Player1 = 'X';
const char Player2 = 'O';


void reset_board();
void print_board();
int check_free_spaces();
void player_move_x();
void player_move_o();
char check_winner();
void print_winner(char winner);

int main(){
	char response[2];
	do{
	char winner = ' ';
	
	reset_board();
	
	while(winner == ' ' && check_free_spaces() != 0){
		print_board();
		player_move_x();
		winner = check_winner();
		if(winner != ' ' || check_free_spaces() == 0){
			break;
		}
		print_board();
		player_move_o();
		winner = check_winner();
		if(winner != ' ' || check_free_spaces() == 0){
			break;
		}	
	}
	print_board();
	print_winner(winner);
	printf("\n\ndo you wanna play again? (Y/N): ");
	scanf("%c ", &response[1]);fflush(stdin);
	response[1] = toupper(response[1]);
	}while(response[1] == 'Y');
	
	return 0;	
}

void reset_board(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
		board [i][j] = ' ';	
		}	
	}
}

void print_board(){
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---+---+---\n");
	printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n---+---+---\n");
	printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}

int check_free_spaces(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (board[i][j] = ' '){
				return 1;
			}
		}	
	}
}

void player_move_x(){
	int x;
	int y;
	
	do{	
		printf("Enter row #(1-3): ");
		scanf("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf("%d", &y);
		y--;
		
		if(board [x][y] != ' '){
			printf("Invalid Move!\n");
		} else {
			board [x][y] = Player1;
			break;
		}
	}while(board [x][y] != ' ');
}
void player_move_o(){
		int x;
	int y;
	
	do{	
		printf("Enter row #(1-3): ");
		scanf("%d", &x);
		x--;
		printf("Enter column #(1-3): ");
		scanf("%d", &y);
		y--;
		
		if(board [x][y] != ' '){
			printf("Invalid Move!\n");
		} else {
			board [x][y] = Player2;
			break;
		}
	}while(board [x][y] != ' ');	
}

char check_winner(){
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

void print_winner(char winner){
	if (winner == Player1){
		printf("PLAYER X WIN!");
	} else 	if(winner == Player2){
			printf("PLAYER O WIN!");
		} else {
			printf("IT'S A TIE");
		}
}