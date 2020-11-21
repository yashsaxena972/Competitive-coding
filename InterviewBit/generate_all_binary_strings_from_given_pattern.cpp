// Generate all binary strings from given pattern
/*
Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary 
strings that can be formed by replacing each wildcard character by ‘0’ or ‘1’.
Example :

Input str = "1??0?101"
Output: 
        10000101
        10001101
        10100101
        10101101
        11000101
        11001101
        11100101
        11101101
*/        


// Recursive C++ program to generate all binary strings 
// formed by replacing each wildcard character by 0 or 1 
#include <iostream> 
using namespace std; 
  
// Recursive function to generate all binary strings 
// formed by replacing each wildcard character by 0 or 1 
void print(string str, int index) 
{ 
    if (index == str.size()) 
    { 
        cout << str << endl; 
        return; 
    } 
  
    if (str[index] == '?') 
    { 
        // replace '?' by '0' and recurse 
        str[index] = '0'; 
        print(str, index + 1); 
  
        // replace '?' by '1' and recurse 
        str[index] = '1'; 
        print(str, index + 1); 
  
        // No need to backtrack as string is passed 
        // by value to the function 
    } 
    else
        print(str, index + 1); 
} 
  
// Driver code to test above function 
int main() 
{ 
    string str = "1??0?101"; 
  
    print(str, 0); 
  
    return 0; 
} 