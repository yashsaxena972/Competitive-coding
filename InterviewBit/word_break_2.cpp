// Word Break II
/*

Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"]

*/

vector<string> rec(const string& sentence, const vector<string>& dict,
    unordered_map<string, vector<string>>& found) {
    
    if(found.count(sentence)) {
        return found[sentence];
    }

    int n = sentence.size();
    vector<string> result;
    for(int i = 1; i <= n; i++) {
        string word = sentence.substr(0, i);
        string rem = sentence.substr(i);
        if(find(dict.begin(), dict.end(), word) != dict.end()) {
            if(rem.empty()) {
                result.push_back(word);
            }
            else {
                for(auto& s: rec(rem, dict, found)) {
                    result.push_back(word + " " + s);
                }
            }
        }
    }

    found[sentence] = result;
    return result;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string, vector<string>> found;
    return rec(A, B, found);
}
