#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num), maxStr = numStr;
        char firstDigit = numStr[0];

        for (char& c : numStr) {
            if (c == firstDigit)  c = '0';
        }
        int minNum = stoi(numStr);

        for (int i = 0; i < maxStr.size(); ++i) {
            if (maxStr[i] != '9') {
                char currentDigit = maxStr[i];
                for (int j = i; j < maxStr.size(); ++j) {
                    if (maxStr[j] == currentDigit) {
                        maxStr[j] = '9';
                    }
                }
                return stoi(maxStr) - minNum;
            }
        }
        return num - minNum;
    }
};

int main(){

}