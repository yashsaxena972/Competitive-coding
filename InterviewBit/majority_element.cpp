// Majority Element
/*

Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.
Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

*/

int Solution::majorityElement(const vector<int> &A) {
    
    int maj = A[0], maj_count = 1;
    
    for(int i = 1; i < A.size(); i++){
        if(A[i] == maj){
            maj_count++;
        }
        else{
            maj_count--;
            if(maj_count == 0){
                maj = A[i];
                maj_count = 1;
            }
        }
    }
    
    return maj;
}
