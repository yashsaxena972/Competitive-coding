// City Tour
/*

There are A cities numbered from 1 to A. You have already visited M cities, the indices of which 
are given in an array B of M integers.

If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or the 
city with index i+1 (i < A) if they are not already visited.
Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves, you can either visit 2 or 5.

You keep visiting cities in this fashion until all the cities are not visited.
Find the number of ways in which you can visit all the cities modulo 10^9+7.

*/

#define ll long long
#define MOD 1000000007

ll powmod(ll base,ll exponent)
{
    if(exponent<0) exponent+=MOD-1;
    ll ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%MOD;
        base=(base*base)%MOD;
        exponent/=2;
    }
    return ans;
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(),B.end());
    long long fact[10000];
    fact[0] = 1;
    
    for(int i = 1;i < 10000;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    vector<long long> vs;
    long long n = B.size();
    vs.push_back(B[0]-1);
    for(int i = 1;i < n;i++){
        vs.push_back(B[i]-B[i-1]-1);
    }
    vs.push_back(A-B[n-1]);
    long long ans = 1;
    long long sum = 0,pro = 1;
    for(int i = 0;i < vs.size();i++){
        if(vs[i] == 0) continue;
        if(i != 0 && i != vs.size()-1) ans = (ans*powmod(2,vs[i]-1))%MOD;
        sum = (sum + vs[i])%MOD;
        pro = (pro*fact[vs[i]])%MOD;
    }
    ans = (ans * fact[sum])%MOD;
    ans = (ans * powmod(pro,MOD-2))%MOD;
    return ans;
}
