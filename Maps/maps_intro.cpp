// Maps STL
#include<iostream>
#include<map>
using namespace std;

int main() {
    string fruit;
    cin>>fruit;
    
    map<string,int> m;
    
    // 1st way to insert
    m.insert(make_pair("Mango",100));

    // 2nd way to insert 
    m["Banana"] = 20;

    // Search in maps
    auto it = m.find(fruit);
    if(it != m.end()){
        cout<<m[fruit];
    }
    else{
        cout<<"Fruit not present";
    }
    return 0;
}
