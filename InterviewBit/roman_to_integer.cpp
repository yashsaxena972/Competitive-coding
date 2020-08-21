// Roman to integer

int value(char c){
    if(c == 'I'){
        return 1;
    }


    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    else{
        return 1000;
    }
}

int Solution::romanToInt(string A) {
    int ans=0,last,secondLast;
    for(int i=A.length()-1;i>=0;i--){
        char c = A[i];
        last = value(c);
        if(i != 0){
            secondLast = value(A[i-1]);
        }
        ans += last;
        if(secondLast < last){
            ans -= secondLast;
            i--;
        }
        secondLast = 0;
        last = 0;
    }
    return ans;
}
