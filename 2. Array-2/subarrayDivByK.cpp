#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int , int> map;
        map[0] = 1;
        for(auto num : nums){
            sum += num;
            int rem = sum % k;
            result += map[rem];
            map[rem]++;
        }
        return result;
    }
};

int main(){

}