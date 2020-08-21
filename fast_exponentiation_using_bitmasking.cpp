// Power exponentiation using Bitmasking
// Efficient way of raising a number to a power
// 3^5 can be written as 3^101

#include <iostream>
using namespace std;
int main() {
    int a,n,ans = 1;
    cin>>a>>n;
    while(n>0){
        int last_bit = (n&1);
        if(last_bit == 1){
            ans = ans * a;  // If the last bit is set, then multiply the answer with the current value of the number
        }
        a = a * a;  // In each iteration, change the value of a by multiplying it with itself
        n = n>>1;  // In each iteration, right shift n to get the new last bit
    }
    cout<<ans;
}
