// Print the spelling of the number

#include <iostream>
using namespace std;

char word[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpelling(int n){
    // base case
    if(n == 0){
        return;
    }

    //recursive case
    printSpelling(n/10);
    int digit = n%10;
    cout<<word[digit]<<" ";
}

int main() {
    int n;
    cin>>n;
    printSpelling(n);
}
