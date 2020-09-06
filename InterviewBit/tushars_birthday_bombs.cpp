// Tushar's Birthday Bombs
/*

It’s Tushar’s birthday today and he has N friends.
Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].
Today being his birthday, his friends have planned to give him birthday bombs (kicks).
Tushar's friends know Tushar's pain bearing limit and would hit accordingly.
If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.
Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)
Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

Input 1:
 A = 12
 B = [3, 4]
Input 2:
 A = 11
 B = [6, 8, 5, 4, 7]

Output 1:
 [0, 0, 0, 0]
Output 2:
 [0, 2]

*/

vector<int> Solution::solve(int A, vector<int> &B) {
    map<int,int> s;

    for(int i=0;i<B.size();i++){
        if(s[B[i]]!=0){
            s[B[i]]=min(s[B[i]],i);  
        }
        else{
            s[B[i]]=i;    
        }    
    }
  
    int idx=min_element(B.begin(),B.end())-B.begin();
    int mini=*min_element(B.begin(),B.end());
    int x=A/mini;
    vector<int> ans;
    for(int i=0;i<x;i++){
        ans.push_back(mini);    
    }
 
    int sum=mini*x;
    int j=0;
    
    for(int i=0;i<idx;i++){ 
        //  deb(sum);
        while(j<ans.size() && sum+B[i]-mini<=A){
            ans[j]=B[i];
            sum=sum+B[i]-mini;
            //deb(sum);
            j++;
        }
    }
    
    for(int i=0;i<ans.size();i++){
        ans[i]=s[ans[i]];    
    }
    
    return ans;
}
