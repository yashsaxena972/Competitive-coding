/*
https://hack.codingblocks.com/app/practice/1/p/104
*/

#include <iostream>
using namespace std;
int main() {
    int t,c1,c2,c3,c4,n,m,rick[1000],cab[1000];
    cin>>t;

    for(int i =0;i<t;i++){
        cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;

        for(int j=0;j<n;j++){
            cin>>rick[j];
        }

        for(int j=0;j<m;j++){
            cin>>cab[j];
        }
        // End of input 

        int rickshawCost=0;
        for(int j=0;j<n;j++){
            rickshawCost = rickshawCost + min(c1*rick[j],c2); 
        }
        rickshawCost = min(rickshawCost,c3);

        int cabCost=0;
        for(int j=0;j<m;j++){
            cabCost = cabCost + min(c1*cab[j],c2); 
        }
        cabCost = min(cabCost,c3);

        int answer = min(c4,rickshawCost + cabCost);
        cout<<answer<<endl;

    }

    return 0;
}
