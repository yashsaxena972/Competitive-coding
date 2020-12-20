// Paint House!
/*

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.

*/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n==0){
        return 0;
    }
    int red = A[0][0];
    int blue = A[0][1];
    int green = A[0][2];
    
    for(int i=1; i<n; ++i){
        int newred = min(blue, green) + A[i][0];
        int newblue = min(red, green) + A[i][1];
        int newgreen = min(blue, red) + A[i][2];
        
        red = newred;
        blue = newblue;
        green = newgreen;
    }
    
    return min(min(red, blue), green);
}
