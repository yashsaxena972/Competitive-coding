// NQueens

bool isSafe(vector<vector<string> >& board, int row, int col, int N)
{
    //check left side rows
    for (int j = 0; j<col; ++j)
        if (board[row][j] == "Q")
            return false;
    
    //check top left side diagonal
    for (int i = row, j = col; i>-1 && j>-1; --i, --j)
        if (board[i][j] == "Q")
            return false;
            
    //check bottom left side diagonal
    for (int i = row, j = col; i<N && j>-1; ++i, --j)
        if (board[i][j] == "Q")
            return false;
    
    return true;
}

bool backtracking(vector<vector<string> >& board, int col, vector<vector<string> >& testboard, int N)
{
    if (col == N)
    {
        vector<string> emptyRow;
        board.emplace_back(emptyRow);
        int size = board.size();
        
        for (int i = 0; i<N; ++i)
        {
            string row = "";
            for (auto j = 0; j<N; ++j)
                row += testboard[i][j];
            
            board[size-1].push_back(row);
        }
        return false;
    }
    
    for (int i = 0; i<N; ++i)
    {
        if (isSafe(testboard, i, col, N))
        {
            testboard[i][col] = "Q";
            
            if (!backtracking(board, col+1, testboard, N))
                testboard[i][col] = ".";
            else
                return true;
        }
    }
    return false;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string> > testboard;
    
    if (A==2 || A==3)
        return testboard;
    
    vector<string> row(A, ".");
    
    for (int i = 0; i<A; ++i)
        testboard.push_back(row);
    
    vector<vector<string> > board;
    backtracking(board, 0, testboard, A);
    return board;
}
