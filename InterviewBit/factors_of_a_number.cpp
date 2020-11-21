// Find all the factors of a number A
// Optimized approach
// https://www.youtube.com/watch?v=dolcMgiJ7I0&feature=emb_err_woyt

vector<int> Solution::allFactors(int A) {
    vector<int> ans;
    for(int i=1;i<=pow(A,0.5);i++){
        if(A%i == 0){
            ans.push_back(i);
            if(i != pow(A,0.5)){
                ans.push_back(A/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

