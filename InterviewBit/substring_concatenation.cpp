// Substring Concatenation
// 1000 point question on InterviewBit

/*

You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    // Number of a characters of a word in list L. 
    int size_word = B[0].size(); 
  
    // Number of words present inside list L. 
    int word_count = B.size(); 
  
    // Total characters present in list L. 
    int size_L = size_word * word_count; 
  
    // Resultant vector which stores indices. 
    vector<int> ans;
    
    // If the total number of characters in list L 
    // is more than length of string S itself. 
    if (size_L > A.size()) {
        return ans; 
    }
    
    // Map stores the words present in list L 
    // against it's occurrences inside list L 
    unordered_map<string, int> hash_map;
    
    for (int i = 0; i < word_count; i++)  
        hash_map[B[i]]++;    
        
    for (int i = 0; i <= A.size() - size_L; i++) { 
        unordered_map<string, int> temp_hash_map(hash_map); 
        
        int j = i,count=word_count; 
    
        // Traverse the substring 
        while (j < i + size_L) { 
  
            // Extract the word 
            string word = A.substr(j, size_word); 
  
  
            // If word not found or if frequency of current word is more than required simply break. 
            if (hash_map.find(word) == hash_map.end()||temp_hash_map[word]==0) 
                break; 
  
            // Else decrement the count of word from hash_map 
            else
               { temp_hash_map[word]--;count--;}  
  
  
            j += size_word; 
        }
        
        // Store the starting index of that substring when all the words in the list are in substring 
        if (count == 0) 
            ans.push_back(i); 
    }
    
    return ans;
}
