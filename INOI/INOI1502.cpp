/* Created by Ishaan Shah on 16-12-2017.
 * Problem Name: INOI1502
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1502
*/

#include <bits/stdc++.h>

using namespace std;

int powers[150001];
set<int> divisor;

void power(int n, int m);
void divisors(int n);

int main() {
    int n, m;
    cin >> n >> m;
    power(n, m);
    divisors(n);
    int dp[n+1];
    dp[1] = 2;
    int count = 0;
    for(int i = 2; i <= n; i++) {
        divisors(i);
        dp[i] = powers[i];
        for(auto &elem: divisor) {
            dp[i] -= dp[elem];
            dp[i] = (dp[i] + m) % m;
        }
    }
    cout << dp[n];

}

void power(int n, int m) {
    powers[0] = 1;
    for(int i = 1; i <= n; i++){
        powers[i] = (powers[i - 1] * 2) % m;
    }
}

void divisors(int n) {
    divisor.clear();
    divisor.insert(1);
    for(int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            divisor.insert(i);
            divisor.insert(n / i);
        }
    }
}

