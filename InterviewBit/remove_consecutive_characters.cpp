// Remove Consecutive Characters
/*

Input 1:

A = "aabcd"
B = 2
Input 2:

A = "aabbccd"
B = 2


Example Output
Output 1:

 "bcd"
Output 2:

 "d"

*/

string Solution::solve(string A, int B) {
    string ans;
    for(int i=0;i<A.size();i++){
        int count=1;
        while(A[i]==A[i+1]){
            count++;
            i++;
        }
        if(count==B)
            continue;
        else
            ans+=A[i];
    }
    return ans;
}
