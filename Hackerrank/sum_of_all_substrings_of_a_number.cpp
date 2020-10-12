// Sam and substrings   or    Sum of all substrings of a string representing a number
/*


Input : s = "6759"
Output : 8421
sum = 6 + 7 + 5 + 9 + 67 + 75 + 
      59 + 675 + 759 + 6759
      = 8421

Input : s = "16"
Output : 23
sum = 1 + 6 + 16 = 23

*/

// Complete the substrings function below.
int substrings(string n) {
    long long int mod = 1000000007;
    long long int sum = 0;
    long long int multiplyingFactor = 1;

    for(int i=n.length()-1;i>=0;i--){
        sum = (sum+(n[i]-'0')*(i+1)*multiplyingFactor)%mod;
        multiplyingFactor = (multiplyingFactor*10+1)%mod;
    }

    return sum;
}