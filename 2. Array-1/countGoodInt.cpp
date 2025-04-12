#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    int cntAllGoodInt(string nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());  // Start with lexicographically smallest permutation
        set<string> seen; // To avoid duplicates

        do {
            if (seen.count(nums)) continue;  // skip duplicate permutations
            seen.insert(nums);
            
            if (isPalindrome(nums)) {
                int number = stoi(nums);
                if (number % k == 0) {
                    cnt++;
                }
            }
        } while (next_permutation(nums.begin(), nums.end()));

        return cnt;
    }

    long long countGoodIntegers(int n, int k) {
        long long result = 0;
        for(int i = pow(10, n-1); i < pow(10, n); ++i){
            result += cntAllGoodInt(to_string(i), k);
        }
        return result;
    }
};

int main(){

}