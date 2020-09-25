// Funny String
/*

In this challenge, you will determine whether a string is funny or not. To determine 
whether a string is funny, create a copy of the string in reverse e.g. . Iterating 
through each string, compare the absolute difference in the ascii values of the characters 
at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is 
the same for both strings, they are funny.

Determine whether a give string is funny. If it is, return Funny, otherwise return Not Funny.

For example, given the string , the ordinal values of the charcters are .  and the ordinals are . 
The absolute differences of the adjacent elements for both strings are , so the answer is Funny.

*/

// Complete the funnyString function below.
string funnyString(string s) {
    int j = s.length()-1;
    bool state = true;
    for(int i=1;i<s.length();i++,j--){
        if(abs(s[i]-s[i-1]) != abs(s[j]-s[j-1])){
            state = false;
            break;
        }
    }

    if(state){
        return "Funny";
    }
    else{
        return "Not Funny";
    }
}