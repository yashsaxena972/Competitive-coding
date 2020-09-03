// Distinct Subsequences
/*

Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.

*/

int Solution::numDistinct(string S, string T) {
    int rows = T.size(), cols = S.size();

    if(rows > cols){
        return 0;
    }
    
    vector<vector<int> > temp(rows+1, vector<int>(cols+1, 0));
    
    for(int i = 0; i <= cols; i++){
        temp[0][i] = 1;
    }
    
    for(int i = 1; i <= rows; i++){
        for(int j = i; j <= cols; j++){
            if(S[j-1] == T[i-1]){
                temp[i][j] = temp[i-1][j-1] + temp[i][j-1];
            }
            else{
                temp[i][j] = temp[i][j-1];
            }
        }
    }
    
    return temp[rows][cols];
}
