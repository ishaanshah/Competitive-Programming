/* Created by Ishaan Shah on 26-06-2019.
* Problem Name: Nearest Interesting Number
* Problem Link: https://codeforces.com/contest/1183/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

int dsum(int n) {
    int ret = 0;
    while (n) {
        ret += n%10;
        n /= 10;
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int a;
    cin >> a;
    int sum = 0;
    while (true) {
        sum = dsum(a);
        if (sum%4 == 0) break;
        a++;
    }
    cout << a;
}