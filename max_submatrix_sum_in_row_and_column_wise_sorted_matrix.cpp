// Max submatrix sum in a row and colimn wise sorted matrix 
// Convert into suffix matrix and output the max element

#include <iostream>
using namespace std;
int main() {
    int ar[10][10],r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ar[i][j];
        }
    }

    // Converting to suffix matrix by adding elements column wise and row wise
    for(int i=r-1;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            ar[i][j] += ar[i][j+1];
        }
    }
    for(int i=c-1;i>=0;i--){
        for(int j=r-2;j>=0;j--){
            ar[j][i] += ar[j+1][i];
        }
    }

    int result = INT8_MIN;  // Setting the result to be minus infinity
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result = max(result,ar[i][j]);
        }
    }

    cout<<"Max submatrix sum is: "<<result;
    return 0;
}
