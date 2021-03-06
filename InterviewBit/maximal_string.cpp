// Maximal String
/*

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.
Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254'
B = 2


Example Output
Output 1:

 524
Output 2:

 542

*/

void getmax(string A, int B, string& m){
    if(B==0)
        return;
    for(int i=0;i<A.size()-1;i++)
        for(int j=i+1;j<A.size();j++){
            if(A[j]>A[i]){
                swap(A[j], A[i]);
                if(A>m)
                    m = A;
                getmax(A, B-1, m);
            swap(A[j], A[i]);
            }
        }
}

string Solution::solve(string A, int B) {
    string m = A;
    getmax(A, B, m);
    return m;
}
