/* Created by Ishaan Shah on 16-10-2019.
* Problem Name: Stones
* Problem Link: https://codeforces.com/contest/1236/problem/A 
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a%2) {
            if (cnt%2)
                a = floor((double)a/2);
            else
                a = ceil((double)a/2);
            cnt++;
            cout << a;
        } else {
            a >>= 1;
            cout << a;
        }
        cout << '\n';
    }
}