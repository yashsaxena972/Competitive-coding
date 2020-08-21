// Ladder problem
// There's a ladder of n steps, and you can make jumps of 1,2,...k steps
// How many ways of reaching the top step,ie, nth step

// Solution
// If the person has reached the nth step, it would have been from either (n-1)th step or (n-2)th step or .... (n-k)th step
// So the number of steps to each n f(n) = f(n-1) + f(n-2) + .... + f(n-k)

#include <iostream>
using namespace std;

int numberOfSteps(int n, int k){
    // base case
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans = 0;
    for(int i = 1; i<=k; i++){
        ans += numberOfSteps(n-i,k);
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<numberOfSteps(n,k);
}
