// Gray Code

int binaryToGray(int num)
{
    return num ^ (num >> 1);
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> res;
    for (int i = 0; i<pow(2, A); ++i)
        res.push_back(binaryToGray(i));
    return res;
}
