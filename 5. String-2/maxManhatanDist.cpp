#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        return max({flip(s, k, "NE"), flip(s, k, "NW"),flip(s, k, "SE"), flip(s, k, "SW")});
    }
private:
    int flip(const string& s, int k, const string& direction) {
        int res = 0, pos = 0, opposite = 0;
        for (char c : s) {
            if (direction.find(c) != string::npos) {
                ++pos;
            } else {
                --pos;
                ++opposite;
            }
            res = max(res, pos + 2 * min(k, opposite));
        }
        return res;
    }
};

int main(){

}