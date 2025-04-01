#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long f(vector<vector<int>> &questions, int ind, vector<int> &dp){
        if(ind >= questions.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        return max(questions[ind][0] + f(questions, ind+questions[ind][1]+1, dp), f(questions, ind+1, dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<int> dp(questions.size()+1, -1);
        return f(questions, 0, dp);
    }
};

int main(){

}