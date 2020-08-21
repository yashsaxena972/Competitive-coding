// Generate the subsequences of a string 
// eg. if the input string is "abc",
// then it will have 8 subsequences (since each letter will either be in the output or won't be)
// output. '','a','b','c','ab','ac','bc','abc'

#include <iostream>
using namespace std;

void generate_subsequences(char input[], char output[], int i, int j){
    // base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }

    // recursive case 1
    // when the letter is to be included
    output[j] = input[i];
    generate_subsequences(input,output,i+1,j+1);

    //recursive case 2
    // when letter is not to be included
    generate_subsequences(input,output,i+1,j);
}

int main() {
    char input[10],output[10]="\0";
    cin>>input;
    generate_subsequences(input,output,0,0);
}
