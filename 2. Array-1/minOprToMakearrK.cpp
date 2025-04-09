#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSame(vector<int> &nums, int k){
        int maxVal = *max_element(nums.begin(), nums.end());
        return maxVal == k;
    }
    int minOperations(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        int operation = 0;
        if(minVal < k) return -1;
        while(true){
            if(isSame(nums, k)) return operation;
            int fMax = -1, sMax = -1;
            for(auto it : nums){
                if (it > fMax) {
                    sMax = fMax; fMax = it;
                } else if (it > sMax && it != fMax) {
                    sMax = it;
                }
            }
            if(sMax == -1) sMax = k;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == fMax) nums[i] = sMax;
            }
            operation++;
        }
        return 0;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        if(minVal < k) return -1;
        unordered_set<int> cnt(nums.begin(), nums.end());
        return minVal == k? cnt.size() - 1 : cnt.size(); 
    }
};
int main(){

}