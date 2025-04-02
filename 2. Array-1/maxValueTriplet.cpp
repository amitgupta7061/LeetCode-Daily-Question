#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxProduct = 0;
        int maxElement = 0, maxDifference = 0; 
        for (int num : nums) { 
            maxProduct = max(maxProduct, (long long)(maxDifference) * num);
            maxElement = max(maxElement, num);
            maxDifference = max(maxDifference, maxElement - num);
        }
        return maxProduct;
    }
};

int main(){

}