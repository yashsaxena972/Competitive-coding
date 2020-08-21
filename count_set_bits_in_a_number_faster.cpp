// To count the number of set bits in the binary representation of a number
// Approach 2 Faster
// or
// In built function
// cout<<__builtin_popcount(n)

#include <iostream>
using namespace std;
int main() {
    int n,ans = 0;
    cin>>n;
    while(n>0){
        n = n & (n-1);
        ans++;
    }
    cout<<ans;
}
