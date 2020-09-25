// Separate the Numbers
/*

https://www.hackerrank.com/challenges/separate-the-numbers/problem


A numeric string, , is beautiful if it can be split into a sequence of two or more 
positive integers, , satisfying the following conditions:

 for any  (i.e., each element in the sequence is  more than the previous element).
No  contains a leading zero. For example, we can split  into the sequence , but it is 
not beautiful because  and  have leading zeroes.
The contents of the sequence cannot be rearranged. For example, we can split  into the 
sequence , but it is not beautiful because it breaks our first constraint (i.e., ).
The diagram below depicts some beautiful strings:

image

You must perform  queries where each query consists of some integer string . For each query, 
print whether or not the string is beautiful on a new line. If it's beautiful, print YES x, 
where  is the first number of the increasing sequence. If there are multiple such values of , 
choose the smallest. Otherwise, print NO.

*/

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    long int d1 = 0, d2 = 0, d3, f;
    long int len = s.length();

    for(long int i=0; i<=len/2; i++){
        d1 = d1*10+(int)(s[i]-'0');
        d3 = d1;
        d2 = 0;
        f = 0;
        for(long int j=i+1; j<len; j++){
            d2 = d2*10+(int)(s[j]-'0');  // second digit
            if(d2 == 0 || (d2-d1) > 1){
                f = 0;
                break;
            }
            if(d2-d1 == 1){
                f = 1;
                d1 = d2;
                d2 = 0;
            }
            else{
                f = 0;
            }
        }

        if(f){
            cout<<"YES "<<d3<<endl;
            break;
        }
        d1 = d3;
    }

    if(f == 0){
        cout<<"NO"<<endl;
    }
}