#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int groupsCount = 1, currentGroupStart = nums[0];
        for (int& currentNum : nums) {
            if (currentNum - currentGroupStart > k) {
                currentGroupStart = currentNum;
                groupsCount++;
            }
        }
        return groupsCount;
    }
};

int main(){

}