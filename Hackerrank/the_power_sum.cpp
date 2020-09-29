// The Power Sum
/*

Find ways an Integer can be expressed as sum of n-th power of unique natural numbers
Given two numbers x and n, find number of ways x can be expressed as sum of n-th power of unique natural numbers.

*/

int power(int num, unsigned int n){
    if(n == 0){
        return 1;
    }
    else if(n%2 == 0){
        return power(num,n/2)*power(num,n/2);
    }
    else{
        return num*power(num,n/2)*power(num,n/2);
    }
}

// Complete the powerSum function below.
int powerSum(int X, int N, int currNum = 1, int  currSum = 0) {
    int results = 0;
    int p = power(currNum,N);

    while(p + currSum < X){
        results += powerSum(X,N,currNum+1,p+currSum);
        currNum++;
        p = power(currNum,N);
    }

    if(p + currSum == X){
        results++;
    }

    return results;
}