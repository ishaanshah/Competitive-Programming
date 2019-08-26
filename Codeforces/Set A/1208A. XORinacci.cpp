/* Created by Ishaan Shah on 25-08-2019.
* Problem Name: XORinacci
* Problem Link: https://codeforces.com/contest/1208/problem/A
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
        ll a, b, n;
        cin >> a >> b >> n;
        ll c = a^b;
        if (n%3 == 0) cout << a;
        else if (n%3 == 1) cout << b;
        else cout << c;
        cout << '\n';
    }
}