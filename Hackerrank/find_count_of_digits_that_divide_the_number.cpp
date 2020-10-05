// Find Digits    or    Find count of digits in a number that divide the number
/*

Given a positive integer n. The task is to find count of digits of number which evenly divides the number n.

*/

// Complete the findDigits function below.
int findDigits(int n) {
    int temp = n, count = 0;
    while(temp != 0){
        int d = temp%10;
        temp /= 10;

        if(d>0 && n%d == 0){
            count++;
        }
    }

    return count;
}