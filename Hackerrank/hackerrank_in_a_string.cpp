// HackerRank in a String!
/*


We say that a string contains the word hackerrank if a subsequence of its 
characters spell the word hackerrank. For example, if string s = haacckkerrannkk  it 
does contain hackerrank, but s = haacckkerannk does not. In the second case, the 
second r is missing. If we reorder the first string as , it no longer contains the subsequence due to ordering.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

*/

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string target = "hackerrank";
    int index = 0;
    for(auto c:s){
        if(c == target[index]){
            index++;
        }
        if(index == target.length()){
            return "YES";
        }
    }
    return "NO";
}