// Black Shapes
/*

Given N x M character matrix A of O's and X's, where O = white, X = black.
Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X

*/

vector<string>v;
void dfs(int i,int j){
    if(i>=v.size()||i<0||j>=v[i].size()||j<0)
        return;
    if(v[i][j]!='X')
        return;
    v[i][j]='0';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int Solution::black(vector<string> &A) {
    v=A;
    int r=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='X'){
                dfs(i,j);
                r++;
            }
                
        }
    }
    return r;
}
