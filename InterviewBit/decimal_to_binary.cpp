// Decimal to binary

string Solution::findDigitsInBinary(int A) {
    stack<int> s;
    string ans;
    
    if(A == 0){
        return "0";    
    }
    
    while(A > 0){
        int i = A%2;
        A = A/2;
        s.push(i);
    }
    
    while(!s.empty()){
        int i = s.top();
        char ch = i + '0';
        s.pop();
        ans += ch;
    }
    return ans;
}
