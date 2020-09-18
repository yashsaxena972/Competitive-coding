// Forming a Magic Square
/*

We define a magic square to be an  matrix of distinct positive integers from  to  where 
the sum of any row, column, or diagonal of length  is always equal to the same number: the magic constant.

You will be given a  matrix  of integers in the inclusive range . We can convert any digit  
to any other digit  in the range  at cost of . Given , convert it into a magic square at minimal 
cost. Print this cost on a new line.

Note: The resulting magic square must contain distinct integers in the inclusive range .

*/

// Return if given vector denotes magic square or not
bool isMagicSquare(vector<int> v){
    int a[3][3];

    // convert vector into 3x3 metrix
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j] = v[3*i+j];
        }
    }

    int s = 0;
    for(int j=0;j<3;j++){
        s += a[0][j];
    }

    // Checking if each row sum is same
    for(int i=0; i<3; i++){
        int temp = 0;
        for(int j=0; j<3;j++){
            temp += a[i][j];
        }
        if(temp != s){
            return 0;
        }
    }

    // Checking if each column sum is same
    for(int i=0; i<3; i++){
        int temp = 0;
        for(int j=0; j<3; j++){
            temp += a[j][i];
        }
        if(temp != s){
            return 0;
        }
    }

    // Checking if diagonal 1 sum is same
    int temp = 0;
    for(int i=0; i<3; i++){
        temp += a[i][i];
    } 
    if(temp != s){
        return 0;
    }   

    // Checking fi diagonal 2 sum is same
    temp = 0;
    for(int i=0;i<3;i++){
        temp += a[2-i][i];
    }
    if(temp != s){
        return 0;
    }

    return 1;
}

// Generating all magic squares
void findAllMagicSquares(vector<vector<int>> &magic_squares){
    vector<int> v(9);

    // Initialising the vector
    for(int i=0;i<9;i++){
        v[i] = i + 1;
    }

    // Producing all permutations of vector
    // and checking if it denotes the magic square or not
    do{
        if(isMagicSquare(v)){
            magic_squares.push_back(v);
        }
    }while(next_permutation(v.begin(), v.end()));
}

// Return sum of difference between each element of 2 vectors
int diff(vector<int> a, vector<int> b){
    int res = 0;

    for(int i=0;i<9;i++){
        res += abs(a[i] - b[i]);
    }

    return res;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int res = INT_MAX;
    
    vector<int>v;
    int r = s.size();
    int c = s[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            v.push_back(s[i][j]);
        }
    }

    vector<vector<int>> magic_squares;

    // generating all magic squares
    findAllMagicSquares(magic_squares);

    for(int i=0; i<magic_squares.size(); i++){
        // Finding the difference with each magic square 
        // and assigning the minimum value
        res = min(res,diff(v,magic_squares[i]));
    }

    return res;
}