// Queen's Attack II
/*

You will be given a square chess board with one queen and a number of obstacles 
placed on it. Determine how many squares the queen can attack.

A queen is standing on an  chessboard. The chess board's rows are numbered from  
to , going from bottom to top. Its columns are numbered from  to , going from left 
to right. Each square is referenced by a tuple, , describing the row, , and column, , 
where the square is located.

The queen is standing at position . In a single move, she can attack any square in any 
of the eight directions (left, right, up, down, and the four diagonals). In the diagram 
below, the green circles denote all the cells the queen can attack from :

Given the queen's position and the locations of all the obstacles, find and print the 
number of squares the queen can attack from her position at . In the board above, there 
are  such squares.

*/

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int dist[8];
    dist[0] = c_q-1;
    dist[1] = n-r_q;
    dist[2] = n-c_q;
    dist[3] = r_q-1;

    dist[4] = min(dist[0],dist[1]);
    dist[5] = min(dist[1],dist[2]);
    dist[6] = min(dist[2],dist[3]);
    dist[7] = min(dist[3],dist[0]);

    int x,y;
    while(--k >=0){
        y = obstacles[k][0] - r_q;
        x = obstacles[k][1] - c_q;
        if(x == 0){
            if(y>0){
                dist[1] = min(dist[1],y-1);
            }
            else{
                dist[3] = min(dist[3],-(y+1));
            }
        }
        else if(y == 0){
            if(x>0){
                dist[2] = min(dist[2],x-1);
            }
            else{
                dist[0] = min(dist[0],-(x+1));
            }
        }
        else{
            float m = (float)y/x;
            if(m == 1.0){
                if(x>0){
                    dist[5] = min(dist[5],x-1);
                }
                else{
                    dist[7] = min(dist[7],-y-1);
                }
            }
            else if(m == -1.0){
                if(x>0){
                    dist[6] = min(dist[6],x-1);
                }
                else{
                    dist[4] = min(dist[4],y-1);
                }
            }
        }
    }

    int res = 0;
    for(int i=0;i<8;i++){
        res += dist[i];
    }
    return res;
}