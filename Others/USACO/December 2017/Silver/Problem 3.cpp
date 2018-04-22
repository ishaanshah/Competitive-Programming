/* Created by Ishaan Shah on 21-04-2018.
* Problem Name: The Bovine Shuffle
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=764
*/

#include <bits/stdc++.h>

using namespace std;

int out[100005];
set<int> white, grey, black;
int strt = -1;
int ans = 0;

int dfs(int start) {
    if(grey.find(start) != grey.end()) {
        strt = start;
        ans++;
        grey.erase(start);
        black.insert(start);
        return 1;
    } else if(black.find(start) != black.end()) {
        return 0;
    } else {
        grey.insert(start);
        white.erase(start);
        int r = dfs(out[start]);
        if(strt == start) {
            strt = -1;
        }
        if(r and strt != -1) {
            ans++;
        }
        black.insert(start);
        grey.erase(start);
        return r;
    }
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        out[i] = arr[i]-1;
        white.insert(i);
    }
    int res = 0;
    while(!white.empty()) {
        int i = *white.begin();
        dfs(i);
        res += ans;
        ans = 0;
    }
    cout << res;
}