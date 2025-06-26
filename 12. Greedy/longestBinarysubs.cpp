#include<iostream>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int answer = 0, value = 0; 
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++answer;
            } else if (answer < 30 && (value | (1 << answer)) <= k) {
                value |= 1 << answer;
                ++answer;
            }
        }
        return answer;
    }
};

int main(){

}