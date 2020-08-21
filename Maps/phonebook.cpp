#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, vector<string>> phonebook;

    phonebook["Saxena"].push_back("9911560972");
    phonebook["Saxena"].push_back("9779736972");
    phonebook["Sharma"].push_back("9825426634");
    phonebook["Sharma"].push_back("8156562656");
    phonebook["Pratap"].push_back("5548754215");

    for(auto p:phonebook){
        cout<<p.first<<"->";
        for(string s:p.second){
            cout<<s<<",";
        }
        cout<<endl;
    }
}
