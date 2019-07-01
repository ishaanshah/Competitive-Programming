/* Created by Ishaan Shah on 01-07-2019.
* Problem Name: Nick and Array
* Problem Link: https://codeforces.com/contest/1180/problem/B
*/

#include <bits/stdc++.h>

#define MAX_N (int)1e5+5

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[MAX_N];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= 0) arr[i] = -arr[i]-1;
    }
    if (n % 2 == 0) for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    else {
        int idx = -1, mx = -1;
        for (int i = 0; i < n; i++) {
            if (abs(arr[i]) > mx) {
                idx = i;
                mx = abs(arr[i]);
            }
        }
        arr[idx] = -arr[idx]-1;
        for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    }
}