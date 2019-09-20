/* Created by Ishaan Shah on 19-09-2019.
* Problem Name: 
* Problem Link: 
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int freq[30];

int ans(int n) {
    if (n == 0) {
        freq[0]--;
        return (freq[0] >= 0);
    }
    if (freq[n] > 0) {
        freq[n]--;
        return 1;
    }
    return (ans(n-1) & ans(n-1));
}

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
        memset(freq, 0, sizeof(freq));
        int tmp;
        REP(i, 0, n) {
            cin >> tmp;
            freq[(int)log2(tmp)]++;
        }
        if (ans(11))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}