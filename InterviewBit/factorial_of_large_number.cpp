// Factorial of a large number using array

string Solution::solve(int A) {
    string output;
    int MAX = 500;
    int res[MAX]; 
  
    // Initialize result 
    res[0] = 1; 
    int res_size = 1; 
  
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for (int x=2; x<=A; x++){
        int carry = 0;  // Initialize carry 
  
        // One by one multiply n with individual digits of res[] 
        for (int i=0; i<res_size; i++) 
        { 
            int prod = res[i] * x + carry; 
            res[i] = prod % 10;   
            carry  = prod/10;     
        } 
  
        // Put carry in res and increase result size 
        while (carry) 
        { 
            res[res_size] = carry%10; 
            carry = carry/10; 
            res_size++; 
        } 
    } 
        
    for (int i=res_size-1; i>=0; i--) {
        char ch = res[i] + '0';
        output+=ch;
    }
    return output;
        
}
