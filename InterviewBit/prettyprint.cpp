// Prettyprint
// Input: A = 4.
// Output:

// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 

vector<vector<int> > Solution::prettyPrint(int A) {
    
    int size = 2*A-1;
    int limit = size;
    int temp = 0;
    
    vector<vector<int> > ans(size, vector<int>(size));
    
    while(A>0){
        for(int i=temp;i<limit;i++){
            for(int j=temp;j<limit;j++){
                ans[i][j] = A;
            }
        }
        A--;
        temp++;
        limit--;
    }
    return ans;
}
