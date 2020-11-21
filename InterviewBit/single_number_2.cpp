// Single Number 2
// Given an array of integers, every element appears thrice except for one which occurs once.
// Find that element which does not appear thrice.
// https://online.codingblocks.com/app/player/58423/content/151583/6662/lecture

int Solution::singleNumber(const vector<int> &A) {
    
    int cnt_of_set_bits[64] = {0};
    int n = A.size();
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = A[i];
    }
    
    for(int i=0;i<n;i++){
        int j = 0;
        while(arr[i] > 0){
            int last_bit = arr[i] & 1;
            cnt_of_set_bits[j++] += last_bit;
            arr[i] = arr[i]>>1;
        }
    }
    
    int p = 1;
    int ans = 0;
    for(int i=0;i<64;i++){
        cnt_of_set_bits[i] %=3;
        ans += (cnt_of_set_bits[i]*p);
        p *=2;
    }
    return ans;
    
}
