// Flipping bits
/*

You will be given a list of 32 bit unsigned integers. Flip all the bits ( and ) 
and print the result as an unsigned integer.

*/

// Complete the flippingBits function below.
unsigned int flippingBits(unsigned int n) {
    long long int num = (1<<32)-1;
    n = num - n;
    return n;
}