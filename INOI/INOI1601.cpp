/* Created by Ishaan Shah on 23-12-2017.
 * Problem Name: INOI1601
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1601
*/

#include<bits/stdc++.h>

using namespace std;

int *value;
int *dp;
list<int> *adj;

void dfs(int p) {
    int mx = numeric_limits<int>::min();
    for(auto elem: adj[p]) {
        dfs(elem);
        mx = max(mx, max(value[p]-value[elem], dp[elem]+value[p]-value[elem]));
    }
    if(!adj[p].empty()) {
        dp[p] = mx;
    }
}

int main() {
    int root;
    int n;
    cin >> n;
    dp = new int[n];
    for(int i = 0; i < n; i++) {
        dp[i] = 0;
    }
    value = new int[n];
    adj = new list<int>[n];
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == -1) {
            root = i;
            continue;
        }
        adj[a-1].push_back(i);
    }
    dfs(root);
    int mx = numeric_limits<int>::min();
    for(int i = 0; i < n; i++) {
        mx = max(mx, dp[i]);
    }
    cout << endl  << mx;
}
