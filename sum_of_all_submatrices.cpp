// Calculate the sum of all possible submatrices of the given matrix

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

    int sum = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int topLeft = (i+1)*(j+1);
            int bottomRight = (r-i)*(c-j);
            sum += ar[i][j]*topLeft*bottomRight;
        }
    }

    cout<<sum;
}
