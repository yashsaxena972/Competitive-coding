// Sum Of Fibonacci Numbers
/*

How many minimum numbers from fibonacci series are required such that sum of 
numbers should be equal to a given Number N?
Note : repetition of number is allowed.

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

*/

int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(0); 
    fib.push_back(1);  
    int i=2, val;

    // fill the value of in dp fib[i] till number exceeds k
    while (true) { 
    val = fib[i - 1] + fib[i - 2];
    if (val>A) 
        break;
     fib.push_back(val); 
     i++; 
     }

     int count = 0; // steps
     int j = fib.size()-1;   // index to last element
  
     while(A>0) { 
         count += (A / fib[j]); // take maximum number first to decrease the sum 
         A = A%(fib[j]);  
         j--;
     }   
     return count;
}
