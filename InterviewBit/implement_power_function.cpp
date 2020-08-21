// Implement power function
// Implement pow(x, n) % d.

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if (n == 0){
        return 1 % d;
    } 

    long long int ans = 1, base = x;
    while (n > 0) 
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % d;
            n--;
        } 
        else
        {
            base = (base * base) % d;
            n /= 2;
        }
    }
    if (ans < 0) {
        ans = (ans + d) % d;
    }
        
    return ans;
}
