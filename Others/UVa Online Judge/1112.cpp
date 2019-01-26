/* Created by Ishaan Shah on 26-01-2019.
* Problem Name: Mice and Maze
* Problem Link: https://uva.onlinejudge.org/external/11/1112.pdf
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int T, n, e, m, t;
int adjMat[105][105];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d", &T);
	while(T--) {
        for (int i = 0; i < 105; i++) for (int j = 0; j < 105; j++)
            adjMat[i][j] = (int)INF;

	    scanf ("%d %d %d %d", &n, &e, &t, &m);
        e--;
	    for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            a--; b--;
            adjMat[a][b] = w;
	    }
	    
	    for (int i = 0; i < n; i++) adjMat[i][i] = 0;

	    for (int k = 0; k < n; k++) {
	        for (int i = 0; i < n; i++) {
	            for (int j = 0; j < n; j++) {
	                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
	            }
	        }
	    }

	    int ans = 0;
	    for (int i = 0; i < n; i++) {
	        if(adjMat[i][e] <= t) ans++;
	    }

	    printf("%d\n", ans);
	    if (T) printf("\n");
	}
}
