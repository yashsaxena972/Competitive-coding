// Snake Ladder Problem!
/*

The board is always 10 x 10 with squares numbered from 1 to 100.
The board contains N ladders given in a form of 2D matrix A of size N * 2 
where (A[i][0], A[i][1]) denotes a ladder that has its base on square A[i][0] and end at square A[i][1].
The board contains M snakes given in a form of 2D matrix B of size M * 2 
where (B[i][0], B[i][1]) denotes a snake that has its mouth on square B[i][0] and tail at square B[i][1].

*/

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    int start = 1, dest = 100;
    unordered_map<int, int> ladders, snakes;
    vector dist(101, INT_MAX);
    vector dice = {1, 2, 3, 4, 5, 6};
    queue<int> q;

    for(auto l : A) 
        ladders[l[0]] = l[1];
    for(auto s : B) 
        snakes[s[0]] = s[1];

    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        auto currPos = q.front(); q.pop(); 
        for(auto roll : dice) {
            int newPos = roll + currPos;
            if(newPos <= dest) {
                if(ladders.find(newPos) != ladders.end()) 
                    newPos = ladders[newPos];
                else if(snakes.find(newPos) != snakes.end()) 
                    newPos = snakes[newPos];
            
                if(dist[newPos] == INT_MAX) {
                    dist[newPos] = dist[currPos] + 1;
                    q.push(newPos);
                }
            }
        }
    }

    auto ans = dist[dest];
    if(ans == INT_MAX) 
        ans = -1;

return ans;
}
