// Counting Triangles
/*

You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of 
triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths 
doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/

int Solution::nTriang(vector<int> &A) {
    int ans = 0, n = A.size(), num = pow(10, 9) + 7;
    
    if(!n){
        return ans;
    }
    
    sort(A.begin(), A.end());
    
    for(int k = n - 1; k >= 0; k--){
        int i = 0, j = k - 1;
        while(i < j){
            long int miniSum = A[i] + A[j], maxi = A[k];
            if(miniSum > maxi){
                ans = (ans + (j - i)%num)%num;
                j--;
            }   
            else{
                i++;    
            }
        }
    }
    
    return ans;
}
