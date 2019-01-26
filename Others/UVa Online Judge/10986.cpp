/* Created by Ishaan Shah on 26-01-2019.
* Problem Name: Sending email
* Problem Link: https://uva.onlinejudge.org/external/109/10986.pdf
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int, int> pi;

int T, n, m, t, s;
vector<pi> adj[20005];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	scanf("%d", &T);
	int tc = 0;
	while (T--) {
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(pi(v, w)); adj[v].push_back(pi(u, w));
		}
		
		vector <int> dist(n, INF);
		dist[s] = 0;
		priority_queue<pi, vector<pi>, greater<pi> > pq;
		pq.push(pi(0, s));
		while (!pq.empty()) {
			pi u = pq.top(); pq.pop();
			if (u.first > dist[u.second]) continue;
			for (pi v: adj[u.second]) {
				if (dist[v.first] > dist[u.second]+v.second) {
					dist[v.first] = dist[u.second]+v.second;
					pq.push(pi(dist[v.first], v.first));
				}
			}
		}
		tc++;
		if (dist[t] == (int)INF) printf("Case #%d: unreachable\n", tc);
		else printf("Case #%d: %d\n", tc, dist[t]);
	}
}
