/* Created by Ishaan Shah on 10-09-2019.
* Problem Name: Chef and Good Subsequences
* Problem Link: https://www.codechef.com/SEPT19B/problems/GDSUB
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool vis[100005];
ll memo[100005];

int n, k;
vi freq;

ll dp (ll i) {
    ll &ans = memo[i];
    if (vis[i]) return ans;
    vis[i] = true;
    if (i == min(k, n)) {
        return 1;
    } else {
        REP(j, i, n)
            ans = (ans+(freq[j]*(dp(j+1)%MOD))%MOD)%MOD;
    }
    ans = (ans+1)%MOD;
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n >> k;
    map<int, int> f;
    memset(vis, false, sizeof(vis));
    memset(memo, 0, sizeof(memo));
    REP(i, 0, n) {
        int tmp;
        cin >> tmp;
        f[tmp]++;
    }
    for (auto it = f.begin(); it != f.end(); it++)
        freq.push_back(it->second);

    n = freq.size();
    if (k == 0) cout << 1;
    else cout << dp(0);
}