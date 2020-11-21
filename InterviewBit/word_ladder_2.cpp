// Word Ladder II
/*

Given two words (start and end), and a dictionary, find the shortest transformation 
sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
If there are multiple such sequence of shortest length, return all of them. Refer to 
the example for more details.

Note:

All words have the same length.
All words contain only lowercase alphabetic characters.

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]


*/

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    queue<vector<string> >paths;
    vector<vector<string> >ans;
    paths.push({start});
    
   if(start==end){
       ans.push_back({start});
       return ans;
   }
   
   unordered_set<string>dict;
   for(int i=0; i<d.size(); i++){
       dict.insert(d[i]);
   }
   int level = 1;
   int min_level = INT_MAX;
   unordered_set<string>visited;
   while(!paths.empty()){
       vector<string> path = paths.front();
       paths.pop();
       if(path.size()>level){
           for(auto w: visited){
               dict.erase(w);
           }
           visited.clear();
           if(path.size()>min_level)
           break;
           else
           level = path.size();
       }
       string last = path.back();
       for(int i=0; i<last.length(); i++){
           string news = last;
           for(int j='a'; j<='z'; j++){
               news[i] = j;
               if(dict.find(news)!=dict.end()){
                   vector<string>newpath = path;
                   newpath.push_back(news);
                   visited.insert(news);
                   if(news==end){
                       min_level = level;
                       ans.push_back(newpath);
                   }
                   else{
                       paths.push(newpath);
                   }
               }
           }
       }
   }
   return ans;
}
