// Max Rectangle in Binary Matrix
/*

Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
Bonus if you can solve it in O(n^2) or less.
Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

*/

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size(),ans=0;
    vector<int>B(m,-1);
    for(int i=0;i<n;i++){
        vector<int>l(m,-1),r(m,m);
        for(int j=0;j<m;j++){
            if(A[i][j]==0)B[j]=i;
        }
        stack<int>s;
        for(int j=0;j<m;j++){
            while(s.empty()==0 and B[s.top()]<=B[j])s.pop();
            if(s.empty()==0)l[j]=s.top();
                s.push(j);
        }
        s=stack<int>();
        for(int j=m-1;j>-1;j--){
            while(s.empty()==0 and B[s.top()]<=B[j])s.pop();
            if(s.empty()==0)r[j]=s.top();
            s.push(j);
        }
        for(int j=0;j<m;j++)
            ans=max(ans,(r[j]-l[j]-1)*(i-B[j]));
    }
    return ans;
}
