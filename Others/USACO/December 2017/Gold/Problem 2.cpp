/* Created by Ishaan Shah on 16-04-2018.
* Problem Name: Barn Painting
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=766
*/

#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

list<int> adj[100005];
int clr[100005];
vector<vector<long long int> > dp(100005, vector<long long> (3, -1));

int DFS(int root, int rclr, int parent, int pclr) {
    if(rclr == pclr || (clr[root] >= 0 && rclr != clr[root])) return 0;
    if(dp[root][rclr] >= 0) {
        return dp[root][rclr];
    }
    dp[root][rclr] = 1;
    for(int out: adj[root]) {
        if(out == parent) continue;
        long long canclr = 0;
        for(int c = 0; c < 3; c++) {
            canclr += DFS(out, c, root, rclr);
            canclr %= mod;
        }
        dp[root][rclr] *= canclr;
        dp[root][rclr] %= mod;
    }
    return dp[root][rclr];
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        clr[i] = -1;
    }
    
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        clr[a] = b;
    }

    cout << (DFS(0, 0, -1, -1) + DFS(0, 1, -1, -1) + DFS(0, 2, -1, -1)) % mod;
}