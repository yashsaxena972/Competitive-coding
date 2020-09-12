// Bulbs    or     Count minimum right flips to set all values in an array
/*

N light bulbs are connected by a wire. Each bulb has a switch associated with it, 
however due to faulty wiring, a switch also changes the state of all the bulbs to the right 
of current bulb. Given an initial state of all bulbs, find the minimum number of switches you
 have to press to turn on all the bulbs. You can press the same switch multiple times.
Note: 0 represents the bulb is off and 1 represents the bulb is on.
Examples:

Input :  [0 1 0 1]
Output : 4
Explanation :
    press switch 0 : [1 0 1 0]
    press switch 1 : [1 1 0 1]
    press switch 2 : [1 1 1 0]
    press switch 3 : [1 1 1 1]

Input : [1 0 0 0 0] 
Output : 1

*/

int Solution::bulbs(vector<int> &A) {
    
    int n = A.size();
    // To keep track of switch presses so far 
    int count = 0; 
  
    int res = 0; 
    for (int i = 0; i < n; i++) 
    { 
        /* if the bulb's original state is on and count 
        is even, it is currently on...*/
        /* no need to press this switch */
        if (A[i] == 1 && count % 2 == 0) 
            continue; 
  
        /* If the bulb's original state is off and count 
        is odd, it is currently on...*/
        /* no need to press this switch */
        else if(A[i] == 0 && count % 2 != 0) 
            continue; 
  
        /* if the bulb's original state is on and count     
        is odd, it is currently off...*/
        /* Press this switch to on the bulb and increase 
        the count */
        else if (A[i] == 1 && count % 2 != 0) 
        { 
            res++; 
            count++; 
        } 
          
        /* if the bulb's original state is off and 
        count is even, it is currently off...*/
        /* press this switch to on the bulb and 
        increase the count */
        else if (A[i] == 0 && count % 2 == 0) 
        { 
            res++; 
            count++; 
        } 
    } 
    return res;
}
