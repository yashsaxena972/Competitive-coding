// To count the number of set bits in the binary representation of a number
// Approach 1
// or
// In built function
// cout<<__builtin_popcount(n)

#include <iostream>
using namespace std;
int main() {
    int n,i,count = 0;
    cin>>n;
    while(n>0){
        count += (n & 1);   // AND the last bit of the number with 1
        n = n>>1;           // Right shift the number by 1 so that in the next iteration, the next bit is checked
    }
    cout<<count;
}
