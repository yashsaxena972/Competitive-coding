// Generate brackets
// eg. for n=2, (()),()()
// eg. for n=3, ((())),()()(),(())(),()(()),(()())

#include <iostream>
using namespace std;

void generate_brackets(char output[], int n, int i, int open, int close){
    // base case 
    // when the entire string is filled then print the string
    if(i == 2*n){
        output[i] = '\0';
        cout<<output<<endl;
        return;
    }

    // recursive cases
    // there are 2 conditions that should always be met
    // 1. open<n for adding another opening bracket
    if(open < n){
        output[i] = '(';
        generate_brackets(output,n,i+1,open+1,close);
    }
    // 2. closed<open for adding another closing bracket
    if(close < open){
        output[i] = ')';
        generate_brackets(output,n,i+1,open,close+1);
    }
    return;
}

int main() {
    int n;
    char output[100];
    cin>>n;
    generate_brackets(output,n,0,0,0);
}
