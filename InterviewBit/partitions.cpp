// Partitions
/*

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])

*/

int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for (int i = 0; i < A; i++){
        sum=sum+B[i];   
    }
 
    if(sum%3!=0){
        return 0;
    }
    int oneThird = sum/3;
    vector<int> temp(A,0);
 
    int tempSum=0;
    for(int i=A-1;i>=0;i--){
        tempSum += B[i];
        if(tempSum==oneThird){
            temp[i]=1;
        }
    }
 
    tempSum=0;
    int total=0;
    for(int i=0; i <A; i++){
        tempSum += B[i];
        if(tempSum == oneThird){
            for(int j=i+2;j<A;j++){
                if(temp[j]==1){
                    total+=1;
                }
            }
        }
     
    }
    return total;
}
