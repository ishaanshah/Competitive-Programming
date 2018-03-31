/* Created by Ishaan Shah on 31/03/18.
 * Problem Name: Haybale Feast
 * Problem Link:http://www.usaco.org/index.php?page=viewproblem2&cpid=767
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long s[n], f[n];
    for(int i = 0; i < n; i++) {
        cin >> f[i] >> s[i];
    }

    int left = 0;
    int right = 0;
    long long sum = 0;
    int mn = numeric_limits<int>::max();
    multiset<int> mx;

    for(int i = 0; i < n; i++) {
        sum += f[i];
        mx.insert(s[i]);
        
        while(sum - f[left] >= m) {
            multiset<int>::iterator it = mx.find(s[left]);
            if(it != mx.end()) {
                mx.erase(it);
            }
            sum -= f[left++];
        }

        if(sum >= m) {
            mn = min(mn, *mx.rbegin());
        }
    }

    cout << mn;
}