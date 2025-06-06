#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        string result = "";
        int n = word.length(), longestPossible = n - numFriends - 1;
        for(int i = 0; i < n; ++i){
            int canTake = min(longestPossible, n-i);
            result = max(result, word.substr(i, canTake));
        }
        return result;
    }
};

int main(){

}