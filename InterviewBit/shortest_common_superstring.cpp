// Shortest common superstring
/*

Given a set of strings, A of length N.
Return the length of smallest string which has all the strings in the set as substring.

Input 1:
    A = ["aaaa", "aa"]

Output 1:
    4

Explanation 1:
    Shortest string: "aaaa"

Input 2:
    A = ["abcd", "cdef", "fgh", "de"]

Output 2:
    8

Explanation 2:
    Shortest string: "abcdefgh"
*/

int overlap[20][20];
int ovp(string &a ,string & b){
    int n1 = a.size(),n2 = b.size();
    for(int i=0;i<n1;++i){
        int  j = i,k = 0;
        while(j<n1 && k<n2 && a[j] == b[k]){
            ++j,++k;
        }
        if(j == n1){
            return (k);
        }
    }
    return 0;
}

int f(vector<string> &A,int prev,int mask,vector<vector<int>> &dp){
    int n = A.size();
    if(mask == (1<<n)-1){
        return 0;
    }
    if(dp[mask][prev] != -1){
        return dp[mask][prev];
    }
    int val,res = INT_MAX;
    for(int i =0;i<n;++i){
        int ava = (mask>>i)&1;
        if(!ava){
            if(prev == 0){
                val = A[i].size();
            }
            else{
                val = A[i].size() - overlap[prev-1][i];
            }
            val += f(A,i+1,mask|(1<<i),dp);
            res = min(res,val);
        }
    }
    dp[mask][prev]=res;
    return res;
}

int Solution::solve(vector<string> &A) {
    int n = A.size();
    for(int i =0;i<n;++i){
        for(int j = 0;j<n;++j){
            overlap[i][j] = ovp(A[i],A[j]);
        }
    }
    vector<vector<int>> dp((1<<n),vector<int>(n+1,-1));
    // mask and previous string for better use.
    int ans = f(A,0,0,dp);
    return ans;
}
