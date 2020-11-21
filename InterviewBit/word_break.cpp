// Word Break
/*

Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words
Input 1:
    A = "myinterviewtrainer",
    B = ["trainer", "my", "interview"]

Output 1:
    1

Explanation 1:
    Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    
Input 2:
    A = "a"
    B = ["aaa"]

Output 2:
    0

Explanation 2:
    Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".

*/

bool search(string A, vector<string> B){
    for(int i = 0; i < B.size(); i++){
        if(B[i] == A){
            return true;
        }
    }
    
    return false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    int n = A.size();
 
    vector<int> temp(n+1, 0);
    temp[n] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string s = A.substr(i, j-i+1);
            if(search(s, B) && temp[j+1] == 1){
                temp[i] = 1;
                break;
            }
        }
    }
    
    return temp[0];
}
