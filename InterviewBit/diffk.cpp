// Diffk
/*

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 
2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
Output : YES as 5 - 1 = 4

*/

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0, j = 1;
    
    while(i < A.size() && j < A.size())
    {
        if(i != j && A[j]-A[i] == B)
            return 1;
        else if(A[j]-A[i] < B)
            j++;
        else 
            i++;
    }
    
    return 0;
}
