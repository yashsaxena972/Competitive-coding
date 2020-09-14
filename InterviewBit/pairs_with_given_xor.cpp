// Pairs With Given Xor
/*

Given an 1D integer array A containing N distinct integers.
Find the number of unique pairs of integers in the array whose XOR is equal to B.
NOTE:
Pair (a, b) and (b, a) is considered to be same and should be counted once.

*/

int Solution::solve(vector<int> &A, int B) {
    map<int,int>mp;
    for(int i=0;i<A.size();i++){
	    mp[A[i]]=1;
    }
    
    int count = 0;
    
    for(int i=0;i<A.size();i++){
	    int required=A[i]^B;
	    if(mp.find(required)!=mp.end()){
		    count++;
	    }
    }
    
    return count/2;
}
