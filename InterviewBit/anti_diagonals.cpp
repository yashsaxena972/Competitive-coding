// Anti diagonals
// Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

int x=A.size();
    vector<vector<int> >res(2*x-1);
    int count=0;
    for(int i=0;i<x;i++){
        int a=0,y=i;
        while(a<x&&y>=0){
            res[count].push_back(A[a][y]);
            a++;
            y--;
        }
        count++;
    }
    for(int i=1;i<x;i++){
        int a=i,y=x-1;
        while(a<x&&y>=0){
            res[count].push_back(A[a][y]);
            a++;
            y--;
        }
        count++;
    }
    return res;