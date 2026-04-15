#include <iostream>
using namespace std;
bool isValid(char board[9][9]) {
    for(int k = 0; k < 9; k++){
        for(int i = 0; i < 9; i++){
            for(int j = i + 1; j < 9; j++){
                if(board[k][i] == '.' || board[i][k] == '.'){
                    continue;
                }
                if(board[k][i] == board[k][j]){
                    return false;
                }
                if(board[i][k] == board[j][k]){
                    return false;
                }
                
            }
        }}
    for()
    return true;
}
int main() {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << isValid(board);
    return 0;
}