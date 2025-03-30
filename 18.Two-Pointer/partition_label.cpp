#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> map(26, -1), result;
        for(int i = 0; i < s.size(); ++i){
            map[s[i] - 'a'] = i;
        }
        int i = 0;
        while(i < s.size()){
            int end = map[s[i] - 'a'], j = i;
            while(j < end){
                end = max(end, map[s[j] - 'a']);
            }
            result.push_back(j - i);
        }
        return result;
    }
};

int main(){

}