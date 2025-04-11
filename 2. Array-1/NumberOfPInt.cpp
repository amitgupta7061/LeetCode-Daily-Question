#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        int m = floor(log10(start))+1, n = floor(log10(finish))+1, p = s.length();
        int result = 1, diff = n - p;
        for(int i = 1; i < diff; i++) result *= 9;
        if(stoi(s) >= start) result++;
        
    }
};

int main(){
    int start = 1, finish = 6000, limit = 4; string s = "124";
    Solution sol;
    sol.numberOfPowerfulInt(start, finish, limit, s);
}