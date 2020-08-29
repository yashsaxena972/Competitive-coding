// Knight On Chess Board

/*

Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.

*/


// structure for storing a cell's data 
struct cell { 
    int x, y; 
    int dis; 
    cell() {} 
    cell(int x, int y, int dis) 
        : x(x), y(y), dis(dis) 
    { 
    } 
};

// Utility method returns true if (x, y) lies 
// inside Board 
bool isInside(int x, int y, int A, int B) 
{ 
    if (x >= 1 && x <= A && y >= 1 && y <= B) 
        return true; 
    return false; 
} 

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    // x and y direction, where a knight can move 
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
  
    // queue for storing states of knight in board 
    queue<cell> q; 
  
    // push starting position of knight with 0 distance 
    q.push(cell(C, D, 0)); 
  
    cell t; 
    int x, y; 
    bool visit[A + 1][B + 1]; 
  
    // make all cell unvisited 
    for (int i = 1; i <= A; i++) 
        for (int j = 1; j <= B; j++) 
            visit[i][j] = false; 
  
    // visit starting state 
    visit[C][D] = true; 
  
    // loop untill we have one element in queue 
    while (!q.empty()) { 
        t = q.front(); 
        q.pop(); 
  
        // if current cell is equal to target cell, 
        // return its distance 
        if (t.x == E && t.y == F) 
            return t.dis; 
  
        // loop for all reachable states 
        for (int i = 0; i < 8; i++) { 
            x = t.x + dx[i]; 
            y = t.y + dy[i]; 
  
            // If reachable state is not yet visited and 
            // inside board, push that state into queue 
            if (isInside(x, y, A, B) && !visit[x][y]) { 
                visit[x][y] = true; 
                q.push(cell(x, y, t.dis + 1)); 
            } 
        } 
    }
    
    return -1;
}
