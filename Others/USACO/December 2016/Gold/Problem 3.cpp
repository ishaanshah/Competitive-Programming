/* Created by Ishaan Shah on 09-08-2018.
* Problem Name: Lasers and Mirrors
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=671
*/

#include <bits/stdc++.h>

#define INF 1e8

using namespace std;

struct point {
	int x, y, idx;
};

int n;
point s, e, p[100005];
vector<pair<int, int> > adj[200010];

bool cmpx(point a, point b) {
	return tie(a.x, a.y) < tie(b.x, b.y);
}

bool cmpy(point a, point b) {
	return tie(a.y, a.x) < tie(b.y, b.x);
}

int bfs() {
	int dist[2*(n+2)];
	for (int i = 0; i < 2*(n+2); i++) {
		dist[i] = INF;
	}
	deque<int> q;
	dist[n] = 0, dist[2*n+2] = 0;
	q.push_back(n); q.push_back(2*n+2);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (int i = 0; i < adj[v].size(); i++) {
            // checking for the optimal distance
            if (dist[adj[v][i].first] > dist[v] + adj[v][i].second) {
                dist[adj[v][i].first] = dist[v] + adj[v][i].second;
                if (adj[v][i].second == 0)
                    q.push_front(adj[v][i].first);
                else
                    q.push_back(adj[v][i].first);
            }
        }
    }
    return min(dist[n+1], dist[2*n+3]);
}

int main() {
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	
	// Take input
	scanf("%d %d %d %d %d", &n, &s.x, &s.y, &e.x, &e.y);
	s.idx = n;
	e.idx = n+1;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].idx = i;
	}
	p[n] = s; p[n+1] = e;
	
	// Connect vertical with horizontal.
	for (int i = 0; i < n+2; i++) {
		adj[i].push_back({i+n+2, 1});
	}
	for (int i = n+2; i < 2*(n+2); i++) {
		adj[i].push_back({i-n-2, 1});
	}
	
	// Scan right to left
	sort(p, p+n+2, cmpx);
	map<int, int> lseen;
	for (int i = 0; i < n+2; i++) {
		if (lseen.count(p[i].y)) {
			adj[p[i].idx].push_back({lseen[p[i].y], 0});
			adj[lseen[p[i].y]].push_back({p[i].idx, 0});
			lseen[p[i].y] = p[i].idx;
		} else {
			lseen[p[i].y] = p[i].idx;
		}
	}
	
	// Scan top to down
	sort(p, p+n+2, cmpy);
	lseen.clear();
	for (int i = 0; i < n+2; i++) {
		if (lseen.count(p[i].x)) {
			adj[p[i].idx+n+2].push_back({lseen[p[i].x], 0});
			adj[lseen[p[i].x]].push_back({p[i].idx+n+2, 0});
			lseen[p[i].x] = p[i].idx+n+2;
		} else {
			lseen[p[i].x] = p[i].idx+n+2;
		}
	}
	
	int ans = bfs();
	if (ans == INF) printf("-1");
	else printf("%d", ans);
}
