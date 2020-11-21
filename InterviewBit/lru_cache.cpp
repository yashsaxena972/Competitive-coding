// LRU Cache
/*

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

 NOTE: If you are using any global variables, make sure to clear them in the constructor. 
Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 


*/

#include <bits/stdc++.h>
using namespace std;

size_t sz;
list< pair<int, int> > keys;
unordered_map< int , list< pair<int, int> >::iterator> info;

LRUCache::LRUCache(int capacity) {
    sz = capacity;
    keys.clear();
    info.clear();
}

int LRUCache::get(int key) {
    int value = -1;
    if(info.find(key) != info.end()) {
        auto itr = info[key];
        value = itr->second;
        keys.erase(itr);
        keys.push_front( make_pair(key, value) );
        info[key] = keys.begin();
    }
    return value;
}

void LRUCache::set(int key, int value) {
    if(info.find(key) == info.end()) {
        if(sz == keys.size()){
            auto last = keys.back();
            info.erase(last.first);
            keys.pop_back();
        }
    }
    else {
        keys.erase( info[key] );
    }
    keys.push_front( make_pair(key, value) );
    info[key] = keys.begin(); 
}
