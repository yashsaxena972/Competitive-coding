// Convert binary to decimal using Bitwise operators

#include <iostream>
using namespace std;
int main() {
    int n,ans=0,p=1,last_bit;
    cin>>n;  // Enter the decimal number
    while(n>0){
        last_bit = n&1;
        ans += p*last_bit;
        p = p*10;
        n = n>>1;
    }
    cout<<ans;
}
