// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 
//0.

//Note: This will be evaluated on the extra memory used. Try to minimize the space and time 
//complexity.

// Solution:
// https://www.programcreek.com/2012/12/leetcode-set-matrix-zeroes-java/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c = A[0].size();
    int r = A.size();
    bool firstRowZero = false;
    bool firstColZero = false;
    
    // Checck for first row zero
    for(int i=0;i<c;i++){
        if(A[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }
    
    // Checck for first col zero
    for(int i=0;i<r;i++){
        if(A[i][0] == 0){
            firstColZero = true;
            break;
        }
    }
    
    // Mark rows and columns with zeros
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    // Use the marks to set zeros
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(A[i][0] == 0 || A[0][j] == 0){
                A[i][j] = 0;
            }
        }
    }
    
    // Set first row and column zero
    if(firstRowZero){
        for(int i=0;i<c;i++){
            A[0][i] = 0;
        }
    }
    
    if(firstColZero){
        for(int i=0;i<r;i++){
            A[i][0] = 0;
        }
    }
    
}
