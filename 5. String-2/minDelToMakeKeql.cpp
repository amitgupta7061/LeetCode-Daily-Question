#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int frequency[26] = {};
        for (char& c : word) ++frequency[c - 'a'];

        vector<int> characterFrequencies;
        for (int freq : frequency) {
            if (freq > 0) {
                characterFrequencies.push_back(freq);
            }
        }

        int wordSize = word.size(), minimumDeletionsResult = wordSize;

        auto calculateDeletions = [&](int targetFrequency) {
            int deletions = 0;
            for (int freq : characterFrequencies) {
                if (freq < targetFrequency) { 
                    deletions += freq;
                } else if (freq > targetFrequency + k) {
                    deletions += (freq - targetFrequency - k);
                }
            }
            return deletions;
        };

        for (int target = 0; target <= wordSize; ++target) {
            minimumDeletionsResult = min(minimumDeletionsResult, calculateDeletions(target));
        }

        return minimumDeletionsResult;
    }
};

int main(){

}