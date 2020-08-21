// Fast power recursive
// In calculating the power recursively, the complexity is O(n)
// We can reduce it to O(n/2)
// The concept is that any even power can be represented as a^8 = (a^4)^2
// And any odd power can be represented as a^9 = a.(a^4)^2

#include <iostream>
using namespace std;

int fast_power(int a, int n){
    // base case
    if(n==0){
        return 1;
    }
    int small_ans = fast_power(a,n/2);
    small_ans *= small_ans;
    if(n&1){ // if n is odd 
        return a*small_ans;
    }
    return small_ans;
}

int main() {
    int a,n;
    cin>>a>>n;
    cout<<fast_power(a,n);
}
