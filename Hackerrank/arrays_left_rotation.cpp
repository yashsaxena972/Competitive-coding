// Arrays: Left Rotation
/*

A left rotation operation on an array shifts each of the array's elements  
unit to the left. For example, if  left rotations are performed on array , 
then the array would become .

Given an array  of  integers and a number, , perform  left rotations on the 
array. Return the updated array to be printed as a single line of space-separated integers.

*/

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    d = d%n;
    int greatestCommonDivisor = gcd(d,n);
    for(int i=0;i<greatestCommonDivisor;i++){
        int temp = a[i];
        int j = i;

        while(1){
            int k = j+d;
            if(k >= n){
                k = k-n;
            }
            if(k == i){
                break;
            }

            a[j] = a[k];
            j = k;
        }

        a[j] = temp;
    }

    return a;
}