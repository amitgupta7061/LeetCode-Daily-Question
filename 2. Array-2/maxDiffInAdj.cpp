#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN, n = nums.size();
        for(int i = 1; i < n; i++){
            maxDiff = max(maxDiff, nums[i] - nums[i-1]);
            maxDiff = max(maxDiff, nums[i-1] - nums[i]);
        }
        return max(maxDiff, nums[0] > nums[n-1] ? nums[0]-nums[n-1] : nums[n-1]-nums[0]);
    }
};

int main(){

}