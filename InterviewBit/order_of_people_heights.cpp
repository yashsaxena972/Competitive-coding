// Order of People Heights
/*

You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4

*/

bool comp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first){
        return p1.second<p2.second;    
    }
    return p1.first>p2.first;
} 

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<pair<int,int>>v(n);
    vector<int>res;
    
    for(int i=0;i<n;i++){
        v[i]={A[i],B[i]};    
    }
    
    sort(v.begin(),v.end(),comp);
    
    for(int i=0;i<n;i++){
        res.insert(res.begin()+v[i].second,v[i].first);    
    }
    return res;
}
