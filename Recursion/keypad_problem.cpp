// Phone keypad problem
// Generate all possible strings corresponding to the string of numbers entered

#include <iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate_names(char input[], char output[], int i, int j){
    // base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }

    // extracting the digit from the character array
    int digit = input[i] - '0';

    if(digit==1 || digit==0){
        generate_names(input,output,i+1,j);
    }

    // now we will add all possible letters corresponding to the digit and then recursively call the function for the next digit in the input string
    for(int k=0;keypad[digit][k]!='\0';k++){
        output[j] = keypad[digit][k];
        // recursively call the function for the next digit in th einput string
        generate_names(input,output,i+1,j+1);
    }

}

int main() {
    char input[10], output[10];
    cin>>input;
    generate_names(input, output, 0, 0);
}
