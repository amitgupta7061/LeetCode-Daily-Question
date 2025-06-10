#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freqMap(26, 0);
        for(auto &ch: s) freqMap[ch - 'a']++;
        int maxOdd = 0, minEven = INT_MAX;
        for(auto it : freqMap){
            if(it != 0 and it % 2){
                maxOdd = max(maxOdd, it);
            } else if(it != 0 and it % 2 == 0){
                minEven = min(minEven, it);
            }
        }
        return  maxOdd - minEven;
    }
};

int main(){

}