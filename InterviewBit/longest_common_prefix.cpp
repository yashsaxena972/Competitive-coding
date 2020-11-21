// Longest Common Prefix 

string Solution::longestCommonPrefix(vector<string> &A) {
    string s1 = A[0];
    int n = A.size();
    if(n == 1){
        return s1;
    }
    
    int x1 = INT_MAX;
    int x;
    for(int i=1;i<n;i++){
        x=0;
        while(s1[x] == A[i][x]){
            x++;
        }
        if(x <= x1){
            x1 = x;
        }
    }
    
    string ans = s1.substr(0,x1);
    return ans;
}
