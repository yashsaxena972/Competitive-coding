// Maximum Size Square Sub-matrix
// Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.

int Solution::solve(vector<vector<int> > &A) {
    int R = A.size();
    int C = A[0].size();
    int i,j;  
    int ans = 0;
    int S[R][C];  
    int max_of_s, max_i, max_j;  
      
    /* Set first column of S[][]*/
    for(i = 0; i < R; i++)  
        S[i][0] = A[i][0];  
      
    /* Set first row of S[][]*/
    for(j = 0; j < C; j++)  
        S[0][j] = A[0][j];  
          
    /* Construct other entries of S[][]*/
    for(i = 1; i < R; i++)  
    {  
        for(j = 1; j < C; j++)  
        {  
            if(A[i][j] == 1)  
                S[i][j] = min(S[i][j-1],min( S[i-1][j],  
                                S[i-1][j-1])) + 1;  
            else
                S[i][j] = 0;  
        }  
    }  
      
    /* Find the maximum entry, and indexes of maximum entry  
        in S[][] */
    max_of_s = S[0][0]; max_i = 0; max_j = 0;  
    for(i = 0; i < R; i++)  
    {  
        for(j = 0; j < C; j++)  
        {  
            if(max_of_s < S[i][j])  
            {  
                max_of_s = S[i][j];  
                max_i = i;  
                max_j = j;  
            }  
        }              
    }  
  
    for(i = max_i; i > max_i - max_of_s; i--)  {
        for(j = max_j; j > max_j - max_of_s; j--)  {  
            ans++;
        }  
    }
    
    return ans;
}
