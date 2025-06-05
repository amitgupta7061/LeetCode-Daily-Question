#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    queue<int> queue;
    int cnt = 0;
    unordered_map<int, int> map;
    LRUCache(int capacity) {
        
    }
    
    int get(int key) {
        map.count(key) ? map[key] : -1;
    }
    
    void put(int key, int value) {
        
    }
};

int main(){

}