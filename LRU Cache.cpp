#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  int capacity;
  unordered_map<int, list<pair<int,int>>::iterator> cache;
  list<pair<int, int>> lrulist;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity=cap;
    }

    // Function to return value corresponding to the key.
    int get(int key ) {
        // your code here
        if(cache.find(key) != cache.end()){
            lrulist.splice(lrulist.begin() , lrulist, cache[key]);
            return cache[key]->second;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(cache.find(key) != cache.end()){
            cache[key]->second=value;
            lrulist.splice(lrulist.begin() , lrulist, cache[key]);
        }
        else{
            if(lrulist.size() == capacity){
                int lrukey=lrulist.back().first;
                cache.erase(lrukey);
                lrulist.pop_back();
            }
            lrulist.push_front({key,value});
            cache[key]=lrulist.begin();
        }
    }
};