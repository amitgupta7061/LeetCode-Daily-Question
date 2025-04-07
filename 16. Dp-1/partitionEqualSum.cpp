#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> &arr, int index, int sum, int target, vector<vector<int>> &dp){
        if(sum == target) return true;
        if(index >= arr.size() or sum > target) return false;
        if(dp[index][sum] != -1) return dp[index][sum];
        return dp[index][sum] = f(arr, index+1, sum+arr[index], target, dp) or f(arr, index+1, sum, target, dp);
    }
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % 2) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(target/2+1, -1));
        return f(nums, 0, 0, target/2, dp);
    }
};

int main(){

}