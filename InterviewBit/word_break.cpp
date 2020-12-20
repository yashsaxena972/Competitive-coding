// Word Break
/*

Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

*/

int Solution::wordBreak(string str, vector<string> &v) {
    int n = v.size(),i,j;
    int size = str.size();
    if(size==0 || n==0)
        return 0;
    string s;
    vector<int> ans(size,0);
    for(i=0;i<size;i++){
        ans[i]=0;
        for(j=i;j>=0;j--){
            if(ans[i])
                break;
            s = str.substr(j,i-j+1);
            if(find(v.begin(),v.end(),s)!=v.end()){
                if(j-1>=0){
                    ans[i] = ans[j-1];
                }
                else{
                    ans[i] = 1;
                }
            }
        }
    }
    return ans[size-1];
}
