// Replace every occurrence of 'pi' in a string with 3.14

#include <iostream>
using namespace std;

void replacePi(char a[], int i){
    // base case
    if(a[i]=='\0' || a[i+1]=='\0'){
        return;
    }

    if(a[i]=='p' && a[i+1]=='i'){
        // pi found
        // shifting + replacement
        int j = i+2;
        while(a[j]!='\0'){
            j++;
        }
        // j reaches the end of the character array
        while(j >= i+2){
            a[j+2] = a[j];
            j--;
        }
        // shifting done
        // now replace
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        
        // calling the function for other occurrences of 'pi'
        replacePi(a,i+4);
    }
    else{
        // go to next position
        replacePi(a,i+1);
    }
}

int main() {
    char a[100];
    cin>>a;
    replacePi(a,0);
    cout<<a;
}
