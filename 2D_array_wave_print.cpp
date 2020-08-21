/*
Iterating over columns, for even columns, iterate over rows starting from top to bottom
and for odd columns, iterate over rows starting from bottom to top 
*/

#include <iostream>
using namespace std;
int main() {
    int r,c,ar[10][10];
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ar[i][j];
        }
    }

    for(int i=0;i<c;i++){
        if(i%2 == 0){
            for(int j=0;j<r;j++){
                cout<<ar[j][i]<<" ";
            }
        }
        else{
            for(int j=r-1;j>=0;j--){
                cout<<ar[j][i]<<" ";
            }
        }
    }

     
}
