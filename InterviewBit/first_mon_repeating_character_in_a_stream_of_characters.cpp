// First non-repeating character in a stream of characters
// Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
// B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the 
// end 
// to B. If no non-repeating character is found then append '#' at the end of B.

string Solution::solve(string A) {
    queue<char> q; 
    string b;
    
    int charCount[26] = { 0 }; 
    
    // traverse whole stream 
    for (int i = 0; A[i]; i++) { 
  
        // push each character in queue 
        q.push(A[i]); 
  
        // increment the frequency count 
        charCount[A[i] - 'a']++; 
  
        // check for the non pepeating character 
        while (!q.empty()) { 
            if (charCount[q.front() - 'a'] > 1) 
                q.pop(); 
            else { 
                b.push_back(q.front());
                break; 
            } 
        } 
  
        if (q.empty()) 
            b.push_back('#'); 
    } 
    return b;
}
