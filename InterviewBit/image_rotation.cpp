#include <iostream>
using namespace std;
int main() {
    int r,c,ar[10][10],t,i,j,k;
    cin>>r>>c;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>ar[i][j];
        }
    }

    // Step 1: Reflection about diagonal
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(i > j){
                t = ar[i][j];
                ar[i][j] = ar[j][i];
                ar[j][i] = t;
            }
        }
    }

    // Step 2: Reversing each row
    for(i=0;i<r;i++){
        for(j=0,k=c-1;j<(c/2);j++,k--){
            t = ar[i][j];
            ar[i][j] = ar[i][k];
            ar[i][k] = t;
        }
    }

    // Output
    for(i=0;i<r;i++){
        cout<<endl;
        for(j=0;j<c;j++){
            cout<<ar[i][j]<<"   ";
        }
    }
}

