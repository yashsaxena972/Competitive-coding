// Mark and Toys
/*

Mark and Jane are very happy after having their first child. Their son loves toys, 
so Mark wants to buy some. There are a number of different toys lying in front of him, 
tagged with their prices. Mark has only a certain amount to spend, and he wants to 
maximize the number of toys he buys with this money.

Given a list of prices and an amount to spend, what is the maximum number of toys Mark 
can buy? For example, if  and Mark has  to spend, he can buy items  for , or  for  units 
of currency. He would choose the first group of  items.

*/

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    
    int n = prices.size();
    sort(prices.begin(),prices.end());
    int count = 0;
    while(k - prices[count] >= 0 && count < n){
        k -= prices[count];
        count++;
    }

    return count;
}