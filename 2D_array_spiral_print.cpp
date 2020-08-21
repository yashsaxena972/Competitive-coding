#include <iostream>
using namespace std;
int main() {
    int ar[10][10],r,c,startRow,endRow,startCol,endCol;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ar[i][j];
        }
    }

    startRow = 0, endRow = r-1, startCol = 0, endCol = c-1;
    while(startRow<=endRow && startCol<=endCol){

        // Print the startRow
        for(int j=startCol;j<=endCol;j++){
            cout<<ar[startRow][j]<<" ";
        }
        startRow++;

        // Print the endCol
        for(int i=startRow;i<=endRow;i++){
            cout<<ar[i][endCol]<<" ";
        }
        endCol--;
        
        // Print the endCol -- make sure that startRow < endRow
        if(startRow<endRow){
            for(int j=endCol;j>=startCol;j--){
            cout<<ar[endRow][j]<<" ";
            }
        endRow--;       
        }
        

        // Print the startCol -- make sure that startCol < endCol
        if(startCol<endCol){
            for(int i=endRow;i>=startRow;i--){
            cout<<ar[i][startCol]<<" ";
            }
        startCol++;      
        }
        

    }


    return 0;

}
