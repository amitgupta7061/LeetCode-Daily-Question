#include<iostream>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;
    int countGoodNumbers(long long n) {
        long long evn = (power(5, (n+1) / 2) % mod) % mod;
        long long odd = (power(4, n / 2) % mod) % mod;
        return (int)((evn * odd) % mod);
    }
    long long power(long long x, long long n) {
        long long result = 1;
        while (n > 0) {
            if (n % 2 == 1)  result = (result * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        return result;  
    }
};

int main(){

}