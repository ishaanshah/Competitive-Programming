/* Created by Ishaan Shah on 30-05-2018.
* Problem Name: Rental Service
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=787
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    int n, m, r;
    cin >> n >> m >> r;
    
    int cow[n];
    for(int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    sort(cow, cow+n, greater<int>());
    
    pair<int, int> shop[m];
    for(int i = 0; i < m; i++) {
        cin >> shop[i].first >> shop[i].second;
    }
    sort(shop, shop+m, comp);

    int rent[r];
    for(int i = 0; i < r; i++) {
        cin >> rent[i];
    }
    sort(rent, rent+r, greater<int>());

    long long g[n];
    g[0] = rent[0];
    for(int i = 1; i < n; i++) {
        if(i < r) {
            g[i] = g[i-1] + rent[i];
        } else {
            g[i] = g[i-1];
        }
    }
    reverse(g, g+n);

    long long f[n];
    f[0] = 0;
    int ci = 0;
    int si = 0;
    int rem = cow[0];
    int need = shop[0].first;
    while(ci < n) {
        if(si >= m) {
            f[ci] = f[ci-1];
            ci++;
            continue;
        }
        int temp = min(rem, need);
        f[ci] += shop[si].second*temp;
        rem -= temp;
        need -= temp;
        if(!need) {
            si++;
            if(si < m) {
                need = shop[si].first;
            }
        }
        if(!rem) {
            ci++;
            if(ci < n) {
                f[ci] = f[ci-1];
                rem = cow[ci];
            }
        }
    }
    long long res = max(f[n-1], g[0]);
    for(int i = 0; i < n-1; i++) {
        res = max(res, f[i]+g[i+1]);
    }
    cout << res;
}