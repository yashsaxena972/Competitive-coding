// Minimum characters required to make a string palindrome

bool ispalindrome(string s) 
{ 
    int l = s.length(); 
    int j; 
      
    for(int i = 0, j = l - 1; i <= j; i++, j--) 
    { 
        if(s[i] != s[j]) 
            return false; 
    } 
    return true; 
} 

int Solution::solve(string A) {
    int cnt = 0; 
    int flag = 0; 
      
    while(A.length()>0) 
    { 
        // if string becomes palindrome then break 
        if(ispalindrome(A)) 
        { 
            flag = 1; 
            break; 
        } 
        else
        { 
            cnt++; 
          
            // erase the last element of the string 
            A.erase(A.begin() + A.length() - 1); 
        } 
    } 
      
    return cnt;
}
