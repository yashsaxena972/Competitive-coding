// Palindrome Partitioning
// Given a string s, partition s such that every string of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// For example, given s = "aab",
// Return
//   [
//     ["a","a","b"]
//     ["aa","b"],
//   ]
// Asked in HyperVerge

bool isPalindrome(const string s, int i, int j)
{
    while (i<j)
    {
        if (s[i] == s[j])
        {
            ++i; --j;
        }
        else
            return false;
    }
    return true;
}

void backtracking(const string& s, int i, vector<string>& row, vector<vector<string> >& res)
{
    if (i == s.length())
    {
        res.emplace_back(row); 
        return;
    }
       
    for (int x = i; x < s.length(); ++x)
    {        
        if (isPalindrome(s, i, x))
        {
            row.push_back(s.substr(i, x-i+1));
            backtracking(s, x+1, row, res);
            row.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> row;
    vector<vector<string> > res;
    backtracking(A, 0, row, res);
    return res;
}
