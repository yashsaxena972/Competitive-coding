// Almost Sorted
/*

Given an array of integers, determine whether the array can be sorted in ascending 
order using only one of the following operations one time.

Swap two elements.
Reverse one sub-segment.
Determine whether one, both or neither of the operations will complete the task. If 
both work, choose swap. For instance, given an array  either swap the  and , or reverse 
them to sort the array. Choose swap. The Output Format section below details requirements.

*/

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int sorted[100000];
    int n = arr.size();
    for(int i=0;i<n;i++){
        sorted[i] = arr[i];
    }

    sort(sorted,sorted+n);
    vector<int> diff;
    for(int i=0;i<n;i++){
        if(sorted[i] != arr[i]){
            diff.push_back(i);
        }
    }

    if(diff.size() == 0){
        cout<<"yes\n";
    }
    else if(diff.size() == 2){
        cout<<"yes\nswap "<<diff[0]+1<<" "<<diff[1]+1<<"\n";
    }
    else{
        int st = diff[0],ed = diff[diff.size()-1];
        while(st<ed){
            swap(arr[st],arr[ed]);
            st++;
            ed--;
        }
        int flag = 1;
        for(int i=0;i<n;i++){
            if(sorted[i] != arr[i]){
                cout<<"no\n";
                return;
            }
        }
        cout<<"yes\nreverse "<<diff[0]+1<<" "<<diff[diff.size()-1]+1<<"\n";
    }
}