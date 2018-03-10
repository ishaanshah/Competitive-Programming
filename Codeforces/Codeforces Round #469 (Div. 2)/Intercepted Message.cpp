/* Created by Ishaan Shah on 24-12-2017.
 * Problem Name: Intercepted Message
 * Problem Link: http://codeforces.com/contest/950/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int m1[n], m2[m];
    for(int i = 0; i < n; i++) {
        cin >> m1[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> m2[i];
    }

    int ps1[n], ps2[m];
    ps1[0] = m1[0];
    ps2[0] = m2[0];
    for(int i = 1; i < n; i++) {
        ps1[i] = ps1[i-1] + m1[i];
    }
    for(int i = 1; i < m; i++) {
        ps2[i] = ps2[i-1] + m2[i];
    }

    int i = 0;
    int j = 0;
    int count = 0;
    while(i < n and j < m) {
        if(ps1[i] == ps2[j]) {
            count++;
            i++;
            j++;
        }
        else if(ps1[i] < ps2[j]) {
            i++;
        } 
        else {
            j++;
        } 
    }

    cout << count;
}