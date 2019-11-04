/* Created by Ishaan Shah on 18-10-2019.
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
        map<pair<string, int> , int> mp;
        set <string> st;
        string w;
        int s;
        REP(i, 0, n) {
            cin >> w >> s;
            mp[make_pair(w, s)]++;
            st.insert(w);
        }
        int ans = 0;
        for (auto it = st.begin(); it != st.end(); it = next(it)) {
            ans += max(mp[make_pair(*it, 0)], mp[(make_pair(*it, 1))]);
        }
        cout << ans << '\n';
    }
}