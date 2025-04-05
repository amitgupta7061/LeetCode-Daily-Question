#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(vector<int> &arr,int index, int xr, int &sum){
        sum += xr;
        for(int i = index; i < arr.size(); i++){
            xr ^= arr[i];
            f(arr, i+1, xr, sum);
            xr ^= arr[i];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        f(nums, 0, 0, sum);
        return sum;
    }
};

int main(){

}