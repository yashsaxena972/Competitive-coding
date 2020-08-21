/*
Applicable only for 2D-arrays that are sorted along both columns and rows
*/
#include <iostream>
using namespace std;
int main() {
    int ar[10][10],i,j,r,c,key,found=0;
    cin>>r>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>ar[i][j];
        }
    }
    cin>>key;
    
    i=0, j=c-1;
    while(i<r && j>=0){
        if(ar[i][j] == key){
            cout<<"Found at position : "<<i+1<<","<<j+1;
            found++;
            break;
        }
        else if(key < ar[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    if(found == 0){
        cout<<"Not found";
    }
 return 0;
}
