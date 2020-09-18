// Word Ladder I
/*

Given two words A and B, and a dictionary, C, find the length of shortest 
transformation sequence from A to B, such that:
You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
*/


// Editorial Solution
void transform(string temp,queue<string> &q,unordered_map<string,int> &mp,unordered_map<string,int> &vis)
{
    for(int i=0;i<temp.size();i++)
    {
        string s=temp;
        for(int j=0;j<26;j++)
        {
            s[i]='a'+j;
            if(mp.find(s)!=mp.end() && vis.find(s)==vis.end())
            {
                q.push(s);
                vis[s]=1;
            }
        }
    }
}

int Solution::solve(string A, string B, vector<string> &C) {
    int steps=0;
    if(A==B)return 0;
    
    unordered_map<string,int> mp;
    for(auto x:C)
    mp[x]=1;
    
    if(mp.find(B)==mp.end())
    return steps;
    
    queue<string> q;
    q.push(A);
    unordered_map<string,int> vis;
    vis[A]=1;
    steps=1;
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            auto temp=q.front();
            q.pop();
            if(temp==B)return steps;
            transform(temp,q,mp,vis);
        }
        steps++;
    }
    return steps;
}





// Understood Solution
bool checker(string &s1, string &s2){
    int count=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            count++;
        }
        if(count>1)
            return false;
    }
    return true;
}

int bfs(string & s, string &e, vector<string> &dic){
    queue<pair<string, int> >q;
    unordered_set<string > sety;
    q.push(make_pair(s, 1));
    sety.insert(s);
    while(!q.empty()){
        pair<string , int > temp = q.front();
        if(temp.first.compare(e)==0)
            return temp.second;
        q.pop();
        for(string str : dic){
            if(sety.find(str)==sety.end()&&checker(str, temp.first)){
                sety.insert(str);
                q.push(make_pair(str, temp.second+1));
            }
        }
    }
    
    return 0;
}

int Solution::solve(string A, string B, vector<string> &C) {
    C.push_back(B);
    return bfs(A, B, C);
}
