/* Created by Ishaan Shah on 22-09-2019.
* Problem Name: Two Groups
* Problem Link: https://www.codechef.com/problems/TWOGRS
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
        int a, b, c;
        cin >> a >> b >> c;
        int flag = 1;
        if ((a + 2*b + 3*c)%2)
            flag = 0;
        else {
            if (a == 0 && c == 0 && (b&1))
                flag = 0;
            if (a == 1 && b == 0 && (c&1))
                flag = 0;
            if (a == 0 && b == 1 && !(c&1))
                flag = 0;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}