// Power of 2
// Check if the number(since the number can be out of range of long long int, it is taken as string) is a power of 2

string multiplyBy2(string s){
    int n = s.length();
    int temp, carry = 0;
    
    for(int i=n-1;i>=0;i--){
        temp = (s[i] - '0')*2;
        s[i] = '0' + ((temp+carry)%10);
        carry = (temp+carry)/10;
    }
    if(carry){
        s.insert(0,1,carry+'0');
    }
    return s;
}

int Solution::power(string A) {
    string s = "1";
    while(true){
        s = multiplyBy2(s);
        
        if(s == A){
            return 1;
        }
        if(s.length() > A.size()){
            return 0;
        }
    }
}
