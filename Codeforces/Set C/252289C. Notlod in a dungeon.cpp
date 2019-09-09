/* Created by Ishaan Shah on 08-09-2019.
* Problem Name: Notlod in a dungeon
* Problem Link: https://codeforces.com/group/yny9prUF8z/contest/252289/problem/C
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

    ll a, b, k;
    cin >> a >> b >> k;
    if (k < a) cout << k+1 << ' ' << '1';
    else {
        k = k-a;
        b--;
        ll row = a-(k/b);
        ll col;
        col = k%b;
        if (a%2 == 1) {
            col++;
            if (row%2 == 0) {
                col = b+2-col;
            } else col++;
            cout << row << ' ' << col;
        } else {
            col++;
            if (row%2 == 1) {
                col = b+2-col;
            } else col++;
            cout << row << ' ' << col;
        }
    }
}