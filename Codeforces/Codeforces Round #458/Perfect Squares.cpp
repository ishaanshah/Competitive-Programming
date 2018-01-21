/* Created by Ishaan Shah on 20/1/18
 * Problem Name: Perfect
 * Problem Link: http://codeforces.com/contest/914/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

bool sqrc(int n) {
    if(n < 0) {
        return false;
    }
    int x = round(sqrt(n));
    return n == x*x;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int mx = numeric_limits<int>::min();
    for(int i = 0; i < n; i++) {
        if(!sqrc(arr[i])) {
            mx = max(mx, arr[i]);
        }
    }
    cout << mx;
}