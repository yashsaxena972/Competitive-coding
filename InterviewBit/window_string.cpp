// Window String
// Same as in CB Maps shortest_window_in_string_containing_all_characters_of_pattern_string

/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

*/

string Solution::minWindow(string A, string B) {
    int SL = A.length();
    int PL = B.length();

    // 1. Corner case
    if(PL > SL) {
        return "";
    }

    // 2. Freq maps
    int FS[256] = {0};
    int FP[256] = {0};

    for(int i=0;i<PL;i++){
        char ch = B[i];
        FP[ch]++;
    }

    // 3. Sliding window (expansion and contraction) + update the minimum length window
    int cnt = 0;
    int start = 0;
    int min_length = INT_MAX;
    int start_index = -1;
    for(int i=0;i<SL;i++){
        char ch = A[i];
        FS[ch]++;

        // Maintain the count of characters matched
        if(FP[ch]!=0 && FS[ch] <= FP[ch]){
            cnt++;
        }

        // If all characters match, start contracting
        if(cnt == PL){
            // start srinking the window
            char temp = A[start];
            // Loop to remove all unwanted characters
            while(FP[temp]==0 || FS[temp]>FP[temp]){
                FS[temp]--;
                start++;
                temp = A[start];
            }

            // current window size
            int window_length = i - start + 1;
            if(window_length < min_length){
                min_length = window_length;
                start_index = start;
            }
        }
    }

    if(start_index == -1){
        return "";
    }
    string ans = A.substr(start_index,min_length);
    return ans;
}
