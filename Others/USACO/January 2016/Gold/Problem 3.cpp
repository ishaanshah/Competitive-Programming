/* Created by Ishaan Shah on 23-09-2018.
* Problem Name: Light Out
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=599
*/

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int n, t_len = 0;
int dist[205];
pair<int, int> vert[205];
map<int, int> sgn[2];

int length(pair<int, int> a, pair<int, int> b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}

int cross_p(pair<int, int> a, pair<int, int> b) {
	return ((a.first*b.second - a.second*b.first) > 0) ? 1 : 0;
}

int angle(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	pair<int, int> vec_1, vec_2;
	vec_1.first = b.x-a.x; vec_1.second = b.y-a.y;
	vec_2.first = c.x-b.x; vec_2.second = c.y-b.y;
	return cross_p(vec_1, vec_2);
}

int main() {
	freopen("lightsout.in", "r", stdin);
	freopen("lightsout.out", "w", stdout);
	
	scanf("%d", &n);
	scanf("%d %d", &vert[0].x, &vert[0].y);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &vert[i].x, &vert[i].y);
		t_len += length(vert[i], vert[i-1]);
	}
	t_len += length(vert[n-1], vert[0]);
	
	int len, cloc = 0;
	for (int i = 0; i < n; i++) {
		len = length(vert[i], vert[(i+1)%n]);
		cloc += len;
		dist[(i+1)%n] = min(cloc, t_len-cloc);
		int ang = angle(vert[i], vert[(i+1)%n], vert[(i+2)%n]);
		if (sgn[ang].find(len) != sgn[ang].end()) sgn[ang][len]++;
		else sgn[ang][len] = 1;
	}
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		cloc = 0;
		int k = (i+1)%n, j = i; 
		while (j != 0) {
			int len = length(vert[k], vert[j]);
			cloc += len;
			int ang = angle(vert[j], vert[k], vert[(k+1)%n]);
			if (sgn[ang][len] > 1) {
				j = k;
				k = (k+1)%n;
			} else break;
		}
		ans = max(abs(dist[i] - (cloc+dist[j])), ans);
	}
	printf("%d", ans);
}
