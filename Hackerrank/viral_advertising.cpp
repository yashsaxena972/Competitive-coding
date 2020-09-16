// Viral Advertising
/*

HackerLand Enterprise is adopting a new viral advertising strategy. When they launch 
a new product, they advertise it to exactly  people on social media.

On the first day, half of those  people (i.e., ) like the advertisement and each 
shares it with  of their friends. At the beginning of the second day,  people receive the advertisement.

Each day,  of the recipients like the advertisement and will share it with  friends on 
the following day. Assuming nobody receives the advertisement twice, determine how many 
people have liked the ad by the end of a given day, beginning with launch day as day .

For example, assume you want to know how many have liked the ad by the end of the  day.

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int shared = 5;
    int cumulative = 0;

    for(int i=1; i<=n; i++){
        int liked = shared/2;
        cumulative += liked;
        shared = liked*3;
    }

    return cumulative;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
