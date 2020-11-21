// Matrix Search    or    Staircase Search
/*

Given a matrix of integers A of size N x M and an integer B.
Write an efficient algorithm that searches for integar B in matrix A.
This matrix A has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.
Note: Rows are numbered from top to bottom and columns are numbered from left to right.

*/


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size();
    int c = A[0].size();
    int found = 0;
    
    int i=0, j=c-1;
    while(i<r && j>=0){
        if(A[i][j] == B){
            found++;
            break;
        }
        else if(B < A[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
 
    return found;
}
