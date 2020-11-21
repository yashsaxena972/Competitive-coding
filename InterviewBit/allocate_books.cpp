// Allocate Books
/*

Given an array of integers A of size N and an integer B.
College library has N bags,the ith book has A[i] number of pages.
You have to allocate books to B number of students so that maximum number 
of pages alloted to a student is minimum.

Input 1:
    A = [12, 34, 67, 90]
    B = 2
Output 1:
    113
Explanation 1:
    There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

        Of the 3 cases, Option 3 has the minimum pages = 113.

Input 2:
    A = [5, 17, 100, 11]
    B = 4
Output 2:
    100

*/

bool isPossible(vector<int> &A,long long int X,int B){
    int n=A.size();
    long long int sum=X;
    int stdcnt=1,i=0;
    while(i<n){
        if(sum-A[i]<0){
            stdcnt++;
            sum=X;
        }
        else {
            sum-=A[i];
            i++;
        }
        
        if(stdcnt>B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(n<B) 
        return -1;
        
    long long int pages=0;
    
    for(int i=0;i<n;i++){
        pages+=A[i];   
    }
     
    long long int low=0,high=pages;
    long long int mid,ans=-1;
    
    while(low<=high){
        mid=low+(high-low)/2;
        if(isPossible(A,mid,B)){
         ans=mid;
         high=mid-1;
        }
        else
         low=mid+1;
    }
    return ans;
}
