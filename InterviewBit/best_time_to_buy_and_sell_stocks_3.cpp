// Best Time to Buy and Sell Stocks III
/*

Say you have an array, A, for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most 2 transactions.
Return the maximum possible profit.
Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

int Solution::maxProfit(const vector<int> &A) {
    
    if(A.size()<2){
        return 0;    
    } 
    
    int n = A.size();
    int best_from_left[n];
    int best_from_right[n];
    
    int mini = A[0];
    int a=0;
    
    for(int i=0;i<n;i++)
    {
        a = max(A[i]-mini,a);
        mini = min(A[i],mini);
        best_from_left[i] = a;
    }
    a=0;
    
    int maxi = A[n-1];
    for(int i=n-1;i>=0;i--)
    {
        a = max(maxi-A[i],a);
        maxi = max(A[i],maxi);
        best_from_right[i] = a;
    }
    
    int res=best_from_right[0];
    
    for(int i=0;i<n-1;i++){
        res = max(res,(best_from_left[i]+best_from_right[i+1]));    
    }
    
    
    res = max(res,best_from_left[n-1]);
    
    return res;
}
