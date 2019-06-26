/* Created by Ishaan Shah on 26-06-2019.
* Problem Name: Candy Box (easy version)
* Problem Link: https://codeforces.com/contest/1183/problem/D
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
        int inp;
        for (int i = 0; i < n; i++) {
            cin >> inp;
            arr[inp-1]++;
        }
        sort(arr, arr+n);
        reverse(arr, arr+n);
        int tmp = arr[0];
        int sum = tmp;
        tmp--;
        for (int i = 1; i < n; i++) {
            if (tmp > arr[i]) {
                tmp = arr[i];
            } 
            if (tmp <= 0) break;
            sum += tmp;
            tmp--;
        }
        cout << sum << endl;
    }
}