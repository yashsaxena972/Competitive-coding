// Circular Array Rotation
/*

John Watson knows of an operation called a right circular rotation on an array of integers. One 
rotation operation moves the last array element to the first position and shifts all remaining 
elements right one. To test Sherlock's abilities, Watson provides Sherlock with an array of integers. 
Sherlock is to perform the rotation operation a number of times then determine the value of the element at a given position.

For each array, perform a number of right circular rotations and return the value of the element at a given index.

*/


// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {

    int n = a.size();
    while(k > n){
        k = k - n;
    }

    vector<int> b;
    for(int i=n-k; i<n; i++){
        b.push_back(a[i]);
    }
    for(int i=0; i<n-k; i++){
        b.push_back(a[i]);
    }

    vector<int> ans;
    for(int i=0; i<queries.size(); i++){
        int index = queries[i];
        int val = b[index];
        ans.push_back(val);
    }

    return ans;
}