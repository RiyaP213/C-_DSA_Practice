#include<iostream>
#include<vector>
using namespace std;

bool IsSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();
    //horizontal check
     for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertical check
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //diagonal right check
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    //diagonal left check
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void printBoard(vector<vector<char>>board){
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void NQueens(vector<vector<char>> &board, int row){
    int n = board.size();
    if(row==n){
        printBoard(board);
        return;}
    
    for(int j=0;j<n;j++){
        if(IsSafe(board,row,j)){
            board[row][j]='Q';
            NQueens(board,row+1);
            board[row][j]='.';
        }
    }
}   


int main(){
    vector<vector<char>> board;
    int n=2;
    
    for(int i=0;i<n;i++){
        vector<char> newRow;
        for(int j=0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    NQueens(board,0);
    return 0;
}
// The N-Queens problem is a classic backtracking problem where the goal is to place N queens on an N x N chessboard such that no two queens threaten each other. This means that no two queens can be in the same row, column, or diagonal. The provided code implements a solution to this problem using backtracking.
// The time complexity of the N-Queens problem is O(N!), where N is the size of the chessboard. This is because, in the worst case, we may have to explore all possible arrangements of queens on the board. The space complexity is O(N^2) due to the storage of the chessboard in a 2D vector.