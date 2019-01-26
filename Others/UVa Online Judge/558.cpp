/* Created by Ishaan Shah on 26-01-2019.
* Problem Name: Wormholes
* Problem Link: https://uva.onlinejudge.org/external/5/558.pdf
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int, int> pi;

int t, n, m;
vector <pi> adj[1005];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(pi(v, w));
		}
		
		vector<int> dist(n, (int)INF);
		dist[0] = 0;
		for (int i = 0; i < n-1; i++) {
			for (int u = 0; u < n; u++) {
				for (const pi &v: adj[u]) {
					dist[v.first] = min(dist[v.first], dist[u]+v.second);
				}
			}
		}
		
		bool ans = false;
		for (int u = 0; u < n; u++) {
			for (const pi &v: adj[u]) {
				if (dist[v.first] > dist[u]+v.second) ans = true;
			}
		}
		
		if (ans) printf("possible\n");
		else printf("not possible\n");
	} 
}

