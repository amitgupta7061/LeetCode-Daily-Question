#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), lstRepeatInd = -1;
        unordered_set<int> visited;
        for(int i = n-1; i >= 0; --i){
            if(visited.count(nums[i])){
                lstRepeatInd = i; break;
            }
            visited.insert(nums[i]);
        }
        cout<<lstRepeatInd<<" ";
        return lstRepeatInd == -1 ? 0 : (lstRepeatInd + 3) / 3; 
    }
};

int main(){

}