// Convert string to integer recursively

#include <bits/stdc++.h>
using namespace std;

int stringToInt(char a[], int n){
    if(n==0){
        return 0;
    }

    // Exracting the first digit from right,ie, the least significant digit
    int digit = a[n-1] - '0';
    // Recursively calling the function on the smaller string
    int small_ans = stringToInt(a,n-1);

    return (small_ans*10)+digit;
}

int main() {
    char a[10];
    int n;
    cin>>a;
    n = strlen(a); 
    int x = stringToInt(a,n);
    cout<<x<<endl;
    cout<<x+1;
}
