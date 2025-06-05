#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n){
        int sum = 0;
        while(n){
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> map; 
        int maxLen = 0, answer = 0;
        for(int i = 1; i<= n; i++){
            int sumOfDigit = f(i);
            map[sumOfDigit]++;
            maxLen = max(maxLen, map[sumOfDigit]);
        }
        for(auto it : map){
            if(it.second == maxLen) answer++;
        }
        return answer;
    }
};

int main(){

}