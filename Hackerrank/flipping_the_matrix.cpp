// Flipping the Matrix
/*

Sean invented a game involving a 2n*2n matrix where each cell of the matrix contains an integer. 
He can reverse any of its rows or columns any number of times. The goal of the game is to maximize 
the sum of the elements in the n*n submatrix located in the upper-left quadrant of the matrix.

Given the initial configurations for  matrices, help Sean reverse the rows and columns of each 
matrix in the best possible way so that the sum of the elements in the matrix's upper-left quadrant is maximal.

*/

// Complete the flippingMatrix function below.
int flippingMatrix(vector<vector<int>> mat) {
    long long total  = 0;
    int n = (mat.size())/2;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            total += max(max(mat[i][j],mat[2*n-1-i][j]),max(mat[i][2*n-1-j],mat[2*n-1-i][2*n-1-j]));
        }
    }

    return total;
}