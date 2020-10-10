// Recursive Digit Sum
/*


We define super digit of an integer xx using the following rules:

Given an integer, we need to find the super digit of the integer.

If xx has only 11 digit, then its super digit is xx.
Otherwise, the super digit of xx is equal to the super digit of the sum of the digits of xx.
For example, the super digit of 98759875 will be calculated as:

super_digit(9875)       9+8+7+5 = 29 
super_digit(29)     2 + 9 = 11
super_digit(11)     1 + 1 = 2
super_digit(2)      = 2  

You are given two numbers nn and kk. The number pp is created by concatenating the string nn kk times. Continuing 
the above example where n=9875n=9875, assume your value k=4k=4. Your initial p= 9875\, 9875\, 9875\, 
9875p=9875987598759875(spaces added for clarity).

    superDigit(p) = superDigit(9875987598759875)
                  5+7+8+9+5+7+8+9+5+7+8+9+5+7+8+9 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)
All of the digits of pp sum to 116116. The digits of 116116 sum to 88. 88 is only one digit, so it's the super digit.

*/

int super(long long x){
    if(x < 10){
        return x;
    }
    int newX = 0;
    while(x){
        newX += x%10;
        x /= 10;
    }
    return super(newX);
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    long long p = 0;
    for(int i=0;i<n.size();i++){
        p += n[i] - '0';
    }
    p *= k;

    return super(p);
}