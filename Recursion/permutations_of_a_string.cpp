// Print all the permutations of a string
// Backtracking

#include <iostream>
using namespace std;

void permute(char input[], int i){
    // base case
    if(input[i] == '\0'){
        cout<<input<<",";
        return;
    }

    // recursive case
    for(int j=i; input[j]!='\0'; j++){
        swap(input[i],input[j]); 
        permute(input,i+1);
        // backtracking step
        swap(input[i],input[j]);
    }
}

int main() {
    char input[10];
    cin>>input;
    permute(input, 0);
}
