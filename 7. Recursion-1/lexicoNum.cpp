#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, int n, vector<int> &ans){
        if(i > n) return;
        if(i) ans.push_back(i);
        for(int j = (i == 0)? 1 : 0; j <= 9; j++){
            helper(10*i+j, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        helper(0, n, ans);
        return ans;
    }
};

int main(){

}