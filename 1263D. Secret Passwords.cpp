/* Created by Ishaan Shah on 30-11-2019.
* Problem Name: Secret Passwords
* Problem Link: https://codeforces.com/contest/1263/problem/D
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector <set <int> > graph(26);
vector <bool> vis(26, false);
int cnt = 0;

void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = true;
    for (auto it = graph[u].begin(); it != graph[u].end(); it = next(it))
        dfs(*it);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    string s;
    set <char> st;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length();
        for (int j = 0; j < len-1; j++) {
            if (s[j] != s[j+1]) {
                graph[s[j]-'a'].insert(s[j+1]-'a');
                graph[s[j+1]-'a'].insert(s[j]-'a');
                st.insert(s[j]);
            }
        }
        st.insert(s[len-1]);
    }
    for (auto it = st.begin(); it != st.end(); it = next(it)) {
        int u = *it-'a';
        if (!vis[u]) {
            cnt++;
            dfs(u);
        }
    }
    cout << cnt << '\n';
}