// Search for a Range
/*

Given a sorted array of integers A(0 based index) of size N, find the starting and 
ending position of a given integar B in array A.
Your algorithm’s runtime complexity must be in the order of O(log n).
Return an array of size 2, such that first element = starting position of B in A and 
second element = ending position of B in A, if B is not found in A return [-1, -1].

Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]

Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1]

*/

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start = 0, end = A.size() - 1, mid;
    vector<int> result(2, -1);
    while(start <= end){
        mid = start + (end - start) / 2;
        if(A[mid] == B){
            result[0] = mid;
            end = mid - 1;
        }
        else if(A[mid] < B){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    if(result[0] == -1)
        return result;

    start = result[0];
    end = A.size() - 1;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(A[mid] == B){
            result[1] = mid;
            start = mid + 1;
        }
        else if(A[mid] < B){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
    return result;
}
