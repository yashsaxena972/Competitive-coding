// Integer to roman

string Solution::intToRoman(int A) {
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int n = sizeof(num)/sizeof(int);
    string rom[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string ans;
    int i = n-1;
    while(A > 0){
        int d = A/num[i];
        A = A%num[i];
        while(d > 0){
            ans +=  rom[i];
            d--;
        }
        i--;
    }
    return ans;
}
