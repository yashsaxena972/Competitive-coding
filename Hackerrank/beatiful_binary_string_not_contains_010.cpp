// Beautiful Binary String
/*

Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring "010".
In one step, Alice can change a 0 to a 1 or vice versa. Count and print the minimum number of steps needed to make 
Alice see the string as beautiful.

*/

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    int ans = 0;

    for(int i=0;i<b.length()-2;i++){
        if(b[i] == '0' && b[i+1] == '1' && b[i+2] == '0'){
            ans++;
            i+=2;
        }
    }

    return ans;
}