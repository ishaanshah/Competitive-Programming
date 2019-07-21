/* Created by Ishaan Shah on 21-07-2019.
* Problem Name: Prime Graph
* Problem Link: https://codeforces.com/contest/1178/problem/D
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii out;

bool is_prime(int n) {
    if (n < 2) return false;
    REP(i, 2, sqrt(n)+1) if (n%i == 0) return false;
    return true;
}

void print() {
    cout << out.size() << endl;
    REP(i, 0, out.size()) cout << out[i].first << ' ' << out[i].second << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    REP(i, 1, n) out.push_back(mp(i, i+1));
    out.push_back(mp(n, 1));
    if (is_prime(out.size())) {
        print();
        return 0;
    }
    REP(i, 1, n/2+1) {
        out.push_back(mp(i, i+n/2));
        if (is_prime(out.size())) {
            print();
            return 0;
        }
    }
}