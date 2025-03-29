#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long int ll;
    ll MOD = 1e9 + 7;
    void calculateScore(vector<int> &nums, vector<ll> &score){
        for(ll ele : nums){
            ll count = 0;
            for(ll i = 2; i * i < ele; ++i){
                if(ele % i == 0) count++;
                while(ele % i == 0) ele /= i;
            }
            if(ele > 1) count++;
            score.push_back(count);
        }
    }

    void calculateSubarrayCntPerScore(vector<ll> &score, vector<ll> &subarray_cnt){
        vector<ll> pge;
        stack<ll> st;
        ll n = score.size();
        for(ll i = 0; i < n; i++){  // prev greater
            while(!st.empty() and score[st.top()] < score[i]) st.pop();

            if(st.empty()) pge.push_back(-1);
            else pge.push_back(st.top());
            st.push(i);
        }

        st = stack<ll>();
        ll count;
        for(ll i = n-1; i >= 0; --i){
            count = 0;
            while(!st.empty() and score[st.top()] <= score[i]) st.pop();

            if(st.empty()) count = (n-i) * (i-pge[i]);
            else count = (st.top()-i) * (i-pge[i]);

            st.push(i);
            subarray_cnt[i] = count;
        }
    }

    ll binaryExponentiation(long long a, long long b){
        ll result = 1;
        while(b){
            if (b & 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return result % MOD;
    }

    int maximumScore(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll> score;
        calculateScore(nums, score);

        vector<ll> subarray_cnt(n);
        calculateSubarrayCntPerScore(score, subarray_cnt);

        priority_queue<pair<ll, ll>> maxHeap;
        for(ll i = 0; i < n; i++){
            maxHeap.push({nums[i], i});
        }

        long long result = 1;
        while(k > 0){
            auto curr = maxHeap.top(); maxHeap.pop();
            result = (result * binaryExponentiation(curr.first, min((ll)k, subarray_cnt[curr.second]))) % MOD;

            k -= subarray_cnt[curr.second];
        }

        return result;
    }
};

int main(){

}