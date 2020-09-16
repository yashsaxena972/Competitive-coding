// Time Conversion
/*

Given a time in 12 -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */

    string ans; 
    // Get hours 
    int h1 = (int)s[1] - '0'; 
    int h2 = (int)s[0] - '0'; 
    int hh = (h2 * 10 + h1 % 10); 

    // If time is in "AM" 
    if(s[8] == 'A'){
        if(hh == 12){
            ans+="00";
            for(int i=2; i<=7; i++){
                ans+=s[i];
            }
        }
        else{
            for(int i=0; i<=7; i++){
                ans+=s[i];
            }
        }
    }
    // If time is in "PM"
    else{
        if(hh == 12){
            ans+="12";
            for(int i=2; i<=7; i++){
                ans+=s[i];
            }
        }
        else{
            hh += 12;
            ans = ans + to_string(hh);
            for(int i=2; i<=7; i++){
                ans+=s[i];
            }
        }
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
