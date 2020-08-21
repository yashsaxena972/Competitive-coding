// N Queens problem

#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    // checking for upper rows in the same column
    for(int row=0;row<i;row++){
        if(board[row][j] == 1){
            return false;
        }
    }

    // chacking for upper left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    // chacking for upper right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    // base case
    if(i == n){
        // successfully placed all the queens. Now print
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    // recursive case
    // try to put the queen in each column, and check if safe
    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j] = 1; // place the queen assuming it to be safe position. It might not be safe but we will figure that with backtracking
            
            bool nextQueenRakhPaye = solveNQueen(board,i+1,n);
            if(nextQueenRakhPaye){
                return true;
            }
            // means that we could not place the queen anywhere in the next row, so the position of this queen is wrong. Therefore, backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    int board[10][10];
    cin>>n;
    solveNQueen(board, 0, n);
    return 0;
}
