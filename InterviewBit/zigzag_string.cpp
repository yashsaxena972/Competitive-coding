// Zigzag string
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed 
// font for better legibility)

// P.......A........H.......N
// ..A..P....L....S....I...I....G
// ....Y.........I........R
// And then read line by line: PAHNAPLSIIGYIR
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

string Solution::convert(string A, int B) {
    int n = A.length();
    if(B==1){
        return A;
    }
        
    string arr[B];
    int row=0;
    bool down=true;
    
    for(int i=0; i<n; i++){
        arr[row].push_back(A[i]);
        if(row==B-1){
            down=false;
        }
        else if(row==0){
            down=true;
        }
        if(down){
            row++;
        }
        else{
            row--;
        }
    }
    
    string ans;
    for(int i=0; i<B; i++){
        ans+=arr[i];
    }
    
    return ans;  
}

