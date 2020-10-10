// Sherlock and Array   or   Find if there is an element in array such that sum of left array is equal to sum of right array
/*

Watson gives Sherlock an array A of length N. Then he asks him to determine if 
there exists an element in the array such that the sum of the elements on its left is 
equal to the sum of the elements on its right. If there are no elements to the left/right, 
then the sum is considered to be zero.
Formally, find an i, such that, A1+A2…Ai-1 =Ai+1+Ai+2…AN

*/

// Complete the balancedSums function below.
string balancedSums(vector<int> arr) {
    
    int n = arr.size();
    int leftIndex = 0, rightIndex = n-1;
    int rightSum = arr[rightIndex], leftSum = arr[leftIndex];

    while(leftIndex != rightIndex){
        if(leftSum < rightSum){
            leftIndex++;
            leftSum += arr[leftIndex];
        }
        else{
            rightIndex--;
            rightSum += arr[rightIndex];
        }
    }

    if(leftSum == rightSum){
        return "YES";
    }
    return "NO";
}