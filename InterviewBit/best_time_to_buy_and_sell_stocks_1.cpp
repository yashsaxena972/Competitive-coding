// Best Time to Buy and Sell Stocks I
/*

Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

Return the maximum possible profit.

*/

int Solution::maxProfit(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    
    int sol = 0, min_p = A[0];
    
    for(int i = 1; i < A.size(); i++){
        if(A[i] < min_p){
            min_p = A[i];
        }
        sol = max(sol, A[i] - min_p);
    }
    
    return sol;
}
