// Print the shortest window in the string which contains all the characters of Pattern string 
// Known as Sliding Window problem

#include <bits/stdc++.h>
using namespace std;

string findWindow(string s, string pattern){
    int SL = s.length();
    int PL = pattern.length();

    // 1. Corner case
    if(PL > SL) {
        return "None";
    }

    // 2. Freq maps
    int FS[256] = {0};
    int FP[256] = {0};

    for(int i=0;i<PL;i++){
        char ch = pattern[i];
        FP[ch]++;
    }

    // 3. Sliding window (expansion and contraction) + update the minimum length window
    int cnt = 0;
    int start = 0;
    int min_length = INT_MAX;
    int start_index = -1;
    for(int i=0;i<SL;i++){
        char ch = s[i];
        FS[ch]++;

        // Maintain the count of characters matched
        if(FP[ch]!=0 && FS[ch] <= FP[ch]){
            cnt++;
        }

        // If all characters match, start contracting
        if(cnt == PL){
            // start srinking the window
            char temp = s[start];
            // Loop to remove all unwanted characters
            while(FP[temp]==0 || FS[temp]>FP[temp]){
                FS[temp]--;
                start++;
                temp = s[start];
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
        return "None";
    }
    string ans = s.substr(start_index,min_length);
    return ans;

}

int main() {
    string s = "heelloaeo world";
    string pattern = "eelo";

    cout<<findWindow(s,pattern);
}
