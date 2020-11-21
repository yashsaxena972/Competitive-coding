// 4 Sum
/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    int size = A.size();
    for (int i = 0; i<size-3; ++i)
    {
        if (i>0 && A[i] == A[i-1])
            continue;
        for (int j = i+1; j<size-2; ++j)
        {
            if (j>i+1 && A[j] == A[j-1])
                continue;
                
            int ptr1 = j+1, ptr2 = size-1;
            while (ptr1 < ptr2)
            {
                int sum = A[i] + A[j] + A[ptr1] + A[ptr2];
                if (sum == B)
                {
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(A[ptr1]);
                    temp.push_back(A[ptr2]);
                    ans.push_back(temp);
                    ++ptr1;
                    while (ptr1<ptr2 && A[ptr1] == A[ptr1-1])
                        ++ptr1;
                }
                else if (sum > B)
                    --ptr2;
                else if (sum < B)
                    ++ptr1;
            }
        }
    }
    return ans;
}
