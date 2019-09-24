/* Created by Ishaan Shah on 03-12-2017.
 * Problem Name: INOI1501
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1501
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> a, b;

int main() {
    cin >> n;
    a.resize(n), b.resize(n);
    long long maximum = numeric_limits<long long>::min();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        maximum = max(maximum, a[i]);
    }
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        b[i] = y;
    }

    long long prefix_sum[n];
    long long diff[n];
    long long sum[n];
    prefix_sum[0] = b[0];
    diff[0] = a[0] - prefix_sum[0];
    sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefix_sum[i] = b[i] + prefix_sum[i-1];
    }

    // Forward Case
    for(int i = 1; i < n; i++) {
        diff[i] = max(diff[i-1], a[i] - prefix_sum[i]);
    }
    for(int i = 1; i < n; i++) {
        maximum = max(maximum, a[i] + diff[i-1] + prefix_sum[i-1]);
    }

    // Backward Case
    for(int i = 1; i < n; i++) {
        sum[i] = max(sum[i-1], prefix_sum[i-1] + a[i]);
    }
    for(int i = 1; i < n; i++) {
        maximum = max(maximum,a[i] + prefix_sum[n-1] + sum[i-1] - prefix_sum[i]);
    }
    cout << maximum << endl;
}
