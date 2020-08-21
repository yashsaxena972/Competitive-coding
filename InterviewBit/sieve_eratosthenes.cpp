// Find all the prime numbers from 2 to the given number
// Sieve Eratosthenes algorithm
// https://www.youtube.com/watch?v=eKp56OLhoQs&feature=emb_err_woyt

vector<int> Solution::sieve(int A) {
    // In Sieve Eratosthenes algorithm, 
    // initially we assume all the numbers to be prime
    // then we strike off all the multiples of prime numbers
    int primes[100000];
    for(int i=0;i<=A;i++){
        primes[i] = 1;
    }
    vector<int> ans;
    primes[0] = 0;
    primes[1] = 0;
    
    for(int i=2;i<=pow(A,0.5);i++){
        if(primes[i] == 1){
            for(int j=2;i*j<=A;j++){
                primes[i*j] = 0;
            }
        }
    }
    
    for(int i=0;i<=A;i++){
        if(primes[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}
