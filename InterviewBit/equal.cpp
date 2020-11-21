// Equal
/*

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array
Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

*/

vector<int> Solution::equal(vector<int> &A) {
    if (A.empty())
        return {};
    
    map<int, pair<int, int> > sum;
    vector<int> ans;
    int size = A.size();
    
    for (int i = 0; i<size; ++i)
    {
        for (int j = i+1; j<size; ++j)
        {
            int sumab = A[i] + A[j];
            
            if (sum.find(sumab) == sum.end())
                sum[sumab] = make_pair(i, j);
            else
            {
                pair<int, int> p = sum[sumab];

                if (p.first < i && p.second != i && p.second != j)
                {
                    vector<int> temp;
                    temp.push_back(p.first);
                    temp.push_back(p.second);
                    temp.push_back(i);
                    temp.push_back(j);
                    
                    if (ans.size() == 0)
                        ans = temp;
                    else
                    {
                        for (int t = 0; t<ans.size(); ++t)
                        {
                            if (ans[t] < temp[t])
                                break;
                            if (ans[t] > temp[t])
                            {
                                ans.clear();
                                ans = temp;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}
