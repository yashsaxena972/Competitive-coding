// 0-1 Knapsack Problem through recursion
// Calculate th max. profit

#include <iostream>
using namespace std;

int profit(int n, int c, int profits[], int weights[]){
    // base case
    if(n==0 || c==0){
        return 0;
    }

    // recursive case
    int ans=0,include=0,exclude=0;

    // If the last item, ie, (n-1)th item is to be included
    if(weights[n-1] <= c){
        include = profits[n-1] + profit(n-1, c-weights[n-1], profits, weights);
    }

    // If the last item, ie, (n-1)th item is to be excluded
    exclude = profit(n-1,c,profits,weights);

    ans = max(include,exclude);
    return ans;
}

int main() {
    int n, c, profits[10], weights[10];
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>profits[i];
    }
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    cout<<profit(n,c,profits,weights);

}
