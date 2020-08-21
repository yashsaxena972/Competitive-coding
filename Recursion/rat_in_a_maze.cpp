// Rat in a maze problem

#include <iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int solution[][10], int i, int j, int m, int n){
    // base case
    if(i==m && j==n){
        solution[m][n] = 1;
        // Print the solution
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    // recursive cases
    if(i>m || j>n){
        return false;
    }

    if(maze[i][j] == 'X'){
        return false;
    }

    // If these conditions are false, assume that soluyion exists
    solution[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, solution, i, j+1, m, n);
    bool downSuccess = ratInMaze(maze, solution, i+1, j, m, n);

    // rewrite the value to zero, to allow other paths
    solution[i][j] = 0;

    if(rightSuccess || downSuccess){
        return true;
    }
    return false;
}

int main() {
    char maze[10][10] = {"0000",
                        "00X0",
                        "000X",
                        "0X00"};

    int solution[10][10] = {0};
    int m=4,n=4;
    bool ans = ratInMaze(maze,solution,0,0,m-1,n-1);
    if(ans == false){
        cout<<"No solution exists";
    }
    return 0;
}
