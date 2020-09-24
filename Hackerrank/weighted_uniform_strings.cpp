// Weighted Uniform Strings
/*

Given a string, , let  be the set of weights for all possible uniform contiguous 
substrings of string . You have to answer  queries, where each query  consists of a 
single integer, . For each query, print Yes on a new line if ; otherwise, print No instead.

Note: The  symbol denotes that  is an element of set .

*/

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    unordered_set<int> values;
    vector<string> ans;
    int n = queries.size();
    int k = 0;
    int last = 0;
    int sum = 0;

    for(auto c:s){
        int x = c-'a'+1;
        values.insert(x == last? sum+x : x);
        sum = x == last ? sum+x: x;
        last = x;
    }

    while(k<n){
        ans.push_back(values.find(queries[k++]) == values.end()?"No":"Yes");
    }

    return ans;
}