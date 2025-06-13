#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWeTake(vector<int> &nums, int &p, int maxDiff){
        int cnt = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] - nums[i-1] <= maxDiff){
                cnt++; i++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWeTake(nums, p, mid)){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){

}