/* Created by Ishaan Shah on 27-09-2019.
* Problem Name: Help Lost Robot!
* Problem Link: https://www.codechef.com/ACMIND16/problems/ICPC16A/
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

    int t;
    cin >> t;
    while (t--) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 < y2) {
                cout << "up\n";
            } else {
                cout << "down\n";
            }
        } else if (y1 == y2) {
            if (x1 < x2) {
                cout << "right\n";
            } else {
                cout << "left\n";
            }
        } else {
            cout << "sad\n";
        }
    }
}