#include<stdio.h>

char cek_menang(char flag);

char cek_menang_3x3();

char cek_menang_5x5();

char cek_menang_7x7();

int main(){

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