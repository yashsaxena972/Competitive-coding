// Spiral Order Matrix I
/*

Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example:
Given the following matrix:
[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return
[1, 2, 3, 6, 9, 8, 7, 4, 5]

*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int r = A.size();
    int c = A[0].size();
    int startRow = 0, endRow = r-1, startCol = 0, endCol = c-1;
    int dir = 1;
    
    vector<int> ans;
    
    while(startRow<=endRow && startCol<=endCol){

        if(dir == 1){
            // Print the startRow
            for(int j=startCol;j<=endCol;j++){
                ans.push_back(A[startRow][j]);
            }
            startRow++;   
            dir = 2;
        }
        
        else if(dir == 2){
            // Print the endCol
            for(int i=startRow;i<=endRow;i++){
                ans.push_back(A[i][endCol]);
            }
            endCol--;    
            dir = 3;
        }
        
        else if(dir == 3){
            for(int j=endCol;j>=startCol;j--){
                ans.push_back(A[endRow][j]);
            }
            endRow--;   
            dir = 4;
        }

        else if(dir == 4){
            for(int i=endRow;i>=startRow;i--){
                ans.push_back(A[i][startCol]);
            }
            startCol++;   
            dir = 1;
        }
        
    }
    
    return ans;
}
