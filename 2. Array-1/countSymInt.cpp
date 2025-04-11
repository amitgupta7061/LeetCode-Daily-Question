#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canTake(int num){
        int n = floor(log10(num)) + 1;
        if(n % 2) return false;
        int temp = 1, fSum = 0, sSum = 0;
        for(int i = 0; i < n; i++){
            int dig = (num / temp ) % 10;
            temp *= 10;
            if(i < n/2) fSum += dig;
            else sSum += dig;
        }
        return fSum == sSum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if(canTake(i)) cnt++;
        }
        return cnt;
    }
};

int main(){

}