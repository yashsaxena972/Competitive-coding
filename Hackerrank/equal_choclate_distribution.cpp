// Equal
/*


Christy is interning at HackerRank. One day she had to distribute some chocolates to 
her colleagues. Biased as she was towards her friends, she may have distributed the 
chocolates unequally. One of the program managers on getting to know this ordered Christy 
to make sure everyone got equal number of chocolates.
But to make things difficult for the intern, she was ordered to equalize the number of 
chocolates for every colleague in the following manner,
For every operation, she can choose one of her colleagues and can do one of the three things.
(i) She can give one chocolate to every colleague other than chosen one.
(ii) She can give two chocolates to every colleague other than chosen one.
(iii) She can give five chocolates to every colleague other than chosen one.
You have to calculate minimum number of such operations needed before every colleague will 
have the same number of chocolates.

*/

int solve(int a, vector<int> arr){
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        int temp = arr[i]-a;
        ans += temp/5 + temp%5/2 + temp%5%2;
    }

    return ans;
}

// Complete the equal function below.
int equal(vector<int> arr) {
    int mi = 1000;
    for(int i=0;i<arr.size();i++){
        mi = min(mi,arr[i]);
    }

    int res = INT_MAX;

    for(int i=0; i<5; i++){
        res = min(res,solve(mi-i,arr));
    }

    return res;
}