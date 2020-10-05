// Larry's Array
/*

Larry has been given a permutation of a sequence of natural numbers incrementing 
from  as an array. He must determine whether the array can be sorted using the 
following operation any number of times:

Choose any  consecutive indices and rotate their elements in such a way that .
For example, if :

A		rotate 
[1,6,5,2,4,3]	[6,5,2]
[1,5,2,6,4,3]	[5,2,6]
[1,2,6,5,4,3]	[5,4,3]
[1,2,6,3,5,4]	[6,3,5]
[1,2,3,5,6,4]	[5,6,4]
[1,2,3,4,5,6]

YES

*/

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    int inv = 0;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i] > A[j]){
                inv++;
            }
        }
    }

    if(inv%2 == 0){
        return "YES";
    }
    return "NO";
}