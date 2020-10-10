// String Construction
/*

Amanda has a string of lowercase letters that she wants to copy to a new string. 
She can perform the following operations with the given costs. She can perform them any 
number of times to construct a new string :

Append a character to the end of string  at a cost of  dollar.
Choose any substring of  and append it to the end of  at no charge.
Given  strings , find and print the minimum cost of copying each  to  on a new line.

*/

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    bool newChar[26] = {false};
    int count = 0;

    for(int i=0;i<s.size();i++){
        if(!newChar[s[i]-'a']){
            newChar[s[i]-'a'] = true;
            count++;
        }
    }

    return count;
}