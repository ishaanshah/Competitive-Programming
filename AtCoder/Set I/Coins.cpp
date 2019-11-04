/* Created by Ishaan Shah on 04-11-2019.
* Problem Name: Coins
* Problem Link: https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, vis[3005][3005];
double p[3005], memo[3005][3005];

double dp(int i, int h) {
    if (i == 1) {
        if (h == 1)
            return p[1];
        else if (h == 0)
            return 1-p[1];
        else
            return 0;
    }
    double &ans = memo[i][h];
    if (vis[i][h])
        return ans;
    vis[i][h] = 1;
    ans = dp(i-1, h-1)*p[i] + dp(i-1, h)*(1-p[i]);
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i+1];
    double ans = 0;
    for (int i = 0; i <= n/2; i++) 
        ans += dp(n, n-i);
    printf("%.10lf", ans);
}