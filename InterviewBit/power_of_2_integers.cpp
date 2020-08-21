// Power of 2 integers
// Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be 
// integers.
// Input : 4
// Output : True  
// as 2^2 = 4. 

int Solution::isPower(int A) {
    
    if(A==1||A==0){
        return 1;  
    } 
    int p=2;
    float x=pow(A,1.0/p);
    while((int)x>1){
        
        if(x-(int)x==0){
            return 1;   
        }
        p++;
        x=pow(A,1.0/p);
    }
    return 0;
}
