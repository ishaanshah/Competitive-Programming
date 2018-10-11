/* Created by Ishaan Shah on 08-10-2018.
* Problem Name: Build Gates
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=596
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> vert;
typedef pair<vert ,vert> edg;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n;
set<edg> edges; set<vert> vertices;
string ins;

int main() {
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);
	
	scanf("%d", &n);
	cin >> ins;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		int nx, ny;
		if (ins[i] == 'N') {
			nx = x+dx[1]; ny = y+dy[1];
			vertices.insert({x, y}); vertices.insert({nx, ny});
			edges.insert({{x, y}, {nx, ny}});
		}
		else if (ins[i] == 'E') {
			nx = x+dx[0]; ny = y+dy[0];
			vertices.insert({x, y}); vertices.insert({nx, ny});
			edges.insert({{x, y}, {nx, ny}});
		}
		else if (ins[i] == 'S') {
			nx = x+dx[3]; ny = y+dy[3];
			vertices.insert({x, y}); vertices.insert({nx, ny});
			edges.insert({{nx, ny}, {x, y}});
		}
		else if (ins[i] == 'W') {
			nx = x+dx[2]; ny = y+dy[2];
			vertices.insert({x, y}); vertices.insert({nx, ny});
			edges.insert({{nx, ny}, {x, y}});
		}
		x = nx; y = ny;
	}
	printf("%d", (int)(edges.size()-vertices.size()+1));
}
