/* Created by Ishaan Shah on 22-08-2018.
* Problem Name: Why Did the Cow Cross the Road(Gold)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=717
*/

#include <bits/stdc++.h>

#define INF 1e12

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;

ll n, t;
ll grid[105][105];
ll dx1[] = {1, 0, -1, 0}, dy1[] = {0, -1, 0, 1};
ll dx2[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2};
ll dy2[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1};

ll ssp(pi start) {
	priority_queue<pii, vector<pii>, greater<pii> > pq; pq.push({start, 0});
	ll dist[n][n];
	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) dist[i][j] = INF;
	dist[0][0] = 0;
	while (!pq.empty()) {
		pii u = pq.top(); pq.pop();
		ll ux = u.first.first, uy = u.first.second;
		for (ll i = 0; i < 4; i++) {
			ll vx = ux + dx1[i], vy = uy + dy1[i];
			if ((vx < n && vx >= 0) && (vy < n && vy >= 0)) {
				if (u.second + 3*t + grid[vx][vy] <= dist[vx][vy]) {
					dist[vx][vy] = u.second + 3*t + grid[vx][vy];
					pq.push({{vx, vy}, dist[vx][vy]});
				}
			}
		}
		for (ll i = 0; i < 12; i++) {
			ll vx = ux + dx2[i], vy = uy + dy2[i];
			if ((vx < n && vx >= 0) && (vy < n && vy >= 0)) {
				if (u.second + 3*t + grid[vx][vy] <= dist[vx][vy]) {
					dist[vx][vy] = u.second + 3*t + grid[vx][vy];
					pq.push({{vx, vy}, dist[vx][vy]});
				}
			}
		}
	}
	ll psbl[] = {dist[n-1][n-1], dist[n-2][n-1]+t, dist[n-1][n-2]+t, dist[n-3][n-1]+2*t, dist[n-2][n-2]+2*t, dist[n-1][n-3]+2*t};
	return *min_element(psbl, psbl+6);
}

int main() {
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	
	scanf("%lld %lld", &n, &t);
	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) {
		scanf("%lld", &grid[i][j]);
	}
	ll ans = ssp({0, 0});
	printf("%lld", ans);
}
