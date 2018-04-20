/* Created by Ishaan Shah on 11-04-2018.
 * Problem Name: WGHTNUM
 * Problem Link: https://www.codechef.com/APRIL18B/problems/WGHTNUM
*/


#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

long long m_pow(long long x, long long y);

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        long long n, w;
        cin >> n >> w;
        long long ways = 1;
        if(-9 <= w and w < 9) {
            ways = m_pow(10, n-2);
            if(w < 0) {
                ways = (ways % mod) * ((10 - abs(w)) % mod) % mod;
            } else {
                ways = (ways % mod) * ((9 - abs(w)) % mod) % mod;
            }
            cout << ways << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

long long m_pow(long long x, long long y) {
    long long res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
 
        y = y>>1;
        x = (x*x) % mod;  
    }
    return res;
}