/* Created by Ishaan Shah on 08-06-2018.
* Problem Name: Rest Stops
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=810
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define ll long long

int pos[MAXN], taste[MAXN];
int l, n, fs, bs;
bool is_max[MAXN];

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    
    scanf("%d%d%d%d", &l, &n, &fs, &bs);
    for (int i = 0; i < n; i += 1) {
    	scanf("%d%d", &pos[i], &taste[i]);
    }
    int mx = -1;
    for (int i = n-1; i >= 0; i += -1) {
    	if (taste[i] > mx) {
    		is_max[i] = true;
    		mx = taste[i];
    	}
    }
    ll tf = 0;
    ll tb = 0;
    ll ans = 0;
    ll last = 0;
    for (int i = 0; i < n; i += 1) {
    	if(is_max[i]) {
			tf += (pos[i] - last)*((ll)fs);
			tb += (pos[i] - last)*((ll)bs);
			ans += (tf - tb)*((ll)taste[i]);
			tb = tf;
			last = pos[i];	
    	}
    }
    printf("%lld", ans);
}
