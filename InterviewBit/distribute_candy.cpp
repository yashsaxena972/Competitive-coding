// Distribute Candy
/*

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]

*/

int Solution::candy(vector<int> &A) {
    int n=A.size();
    vector<int>candies(n);
    
    for(int i=0;i<n;i++){
        candies[i]=1;
    }
    for(int i=1;i<n;i++){
        if(A[i]==A[i-1]) continue;
    
        else if(A[i]>A[i-1]&&candies[i]<=candies[i-1])
         candies[i]=candies[i-1]+1;
        else{
            int j=i-1;
            while(j>=0&&A[j]>A[j+1]&candies[j]<=candies[j+1]){
             candies[j]=candies[j+1]+1;
             j--;
            }
        }
    }
    int ans=candies[0];
    for(int i=1;i<n;i++)
        ans+=candies[i];
    return ans;
}
