// Min Cost Path
/*

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.
Your target is to go from top left corner to the bottom right corner of the matrix.
But there are some restrictions while moving along the matrix:
If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.
So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.

*/

#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pi pair<int,int>
const int maxn=1009;
int dist[maxn][maxn];
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
char dir[]={'R','D','U','L'};

bool safe(int x,int y,int n,int m)
{
  if(x>=0 && x<n && y>=0 && y<m)return true;
  return false;
}

void bfs(vector<string>&arr,int n,int m)
{
    dist[0][0]=0;
    deque<pi >q;
    q.push_front({0,0});
    while(q.empty()==false){
        pi temp=q.front();
        q.pop_front();
        int x=temp.ff;
        int y=temp.ss;
        rep(i,4)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!safe(nx,ny,n,m))continue;
            int newCost=(dir[i]==arr[x][y])?0:1;
            //If newCost=0 then we are moving to the same direction as written on the cell.
            if(dist[x][y]+newCost<dist[nx][ny])
            {
             dist[nx][ny]=dist[x][y]+newCost;
             if(newCost==1)q.push_back({nx,ny});
             else q.push_front({nx,ny});
            }
        }
    }
}

int Solution::solve(int A, int B, vector<string> &C) {
    rep(i,maxn)rep(j,maxn)dist[i][j]=INT_MAX;
    bfs(C,A,B);
    return dist[A-1][B-1];
}
