#include<bits/stdc++.h>
using namespace std;


class BinaryIndexedTree {
public:
    vector<int> tree;
    int size;
    explicit BinaryIndexedTree(int n) : size(n), tree(n + 1, 0) {}
    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += lowbit(index);
        }
    }

    int query(int index) const {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowbit(index);
        }
        return sum;
    }

private:
    static int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    long long goodTriplets(const vector<int>& nums1, const vector<int>& nums2) {
        int n = nums1.size();

        vector<int> position(n);
        for (int i = 0; i < n; ++i) position[nums2[i]] = i + 1;

        BinaryIndexedTree bit(n);
        long long count = 0;

        for (int num : nums1) {
            int currentPos = position[num];
            int leftCount = bit.query(currentPos);
            int rightCount = n - currentPos - (bit.query(n) - bit.query(currentPos));
            
            count += static_cast<long long>(leftCount) * rightCount;
        
            bit.update(currentPos, 1);
        }
        return count;
    }
};

int main(){

}