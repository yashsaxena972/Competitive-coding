// Target sum triplets, ie, print those triplets from an array whose sum is equal to the target

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,ar[1000],i,l,r,target;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	cin>>target;
	sort(ar,ar+n);
	for(i=0;i<n-1;i++){
		l = i+1;
		r = n-1;
		while(l<r){
			if(ar[i] + ar[l] + ar[r] == target){
				cout<<ar[i]<<", "<<ar[l]<<" and "<<ar[r]<<endl;
				l++;
				r--;
			}
			else if(ar[i] + ar[l] + ar[r] > target){
				r--;
			}
			else{
				l++;
			}
		}
	}
	return 0;
}