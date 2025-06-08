#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> haveSmall(n);
        char minChar = s[n-1];
        haveSmall[n-1] = minChar;
        for(int i = n-2; i >= 0; --i){
            if(s[i] > minChar) haveSmall[i] = minChar;
            else{
                haveSmall[i] = s[i];
                minChar = s[i];
            }
        }
        for(auto it : haveSmall) cout<<it<<" ";
        string t = "", p = "";
        for(int i = 0; i < n; i++){
            t.push_back(s[i]);
            while(t.size() and i < n-1 and haveSmall[i+1] > t.back()){
                p.push_back(t.back()); t.pop_back();
            }
        }
        while(t.size()){
            p.push_back(t.back()); t.pop_back();
        }
        return p;
    }
};

int main(){

}