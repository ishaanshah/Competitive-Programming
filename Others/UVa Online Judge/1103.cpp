/* Created by Ishaan Shah on 17-01-2019.
* Problem Name: Ancient Messages
* Problem Link: https://uva.onlinejudge.org/external/11/1103.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int h, w, cnt, A, J, D, S, W, K, cs = 0;
int grid[205][205], vis[205][205];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

string hb(char c) {
    switch(toupper(c)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

void flood1(int x, int y, int clr) {
	if (vis[x][y] > 0) return;
	vis[x][y] = clr;
	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (grid[nx][ny] == 0) flood1(nx, ny, clr);
	}
}

void flood2(int x, int y) {
	if (vis[x][y] > 0) return;
	vis[x][y] = 3;
	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (vis[nx][ny] == 0 && grid[nx][ny] == 0) {
			flood1(nx, ny, 2);
			cnt++;
		} else {
			flood2(nx, ny);
		}
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	while (true) {
		cs++;
		memset(vis, 0, sizeof vis);
		A = 0; J = 0; D = 0; W = 0; S = 0; K = 0; 
		scanf("%d %d", &h, &w);
		if (!h && !w) break;
		
		// Creating the grid
		for (int i = 0; i < h; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < w; j++) {
				string s = hb((char)temp[j]);
				for (int k = 0; k < 4; k++) {
					grid[i][4*j+k] = s[k]-'0';
				}
			}
		}
		
		// Color the background pixels
		w = 4*w;
		for (int i = 0; i < h; i++) {
			if (grid[i][0] == 0) flood1(i, 0, 1);
			if (grid[i][w-1] == 0) flood1(i, w-1, 1);
		}
		for (int i = 0; i < w; i++) {
			if (grid[0][i] == 0) flood1(0, i, 1);
			if (grid[h-1][i] == 0) flood1(h-1, i, 1);
		}
		
		// Find number of holes
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cnt = 0;
				if (grid[i][j] == 1 && vis[i][j] == 0) {
					flood2(i, j);
					switch(cnt) {
						case 0: W++; break;
						case 1: A++; break;
						case 2: K++; break;
						case 3: J++; break;
						case 4: S++; break;
						case 5: D++; break;
					}
				}
			}
		}
		
		// Output
		printf("Case %d: ", cs);
		for (int i = 0; i < A; i++) printf("A");
		for (int i = 0; i < D; i++) printf("D");
		for (int i = 0; i < J; i++) printf("J");
		for (int i = 0; i < K; i++) printf("K");
		for (int i = 0; i < S; i++) printf("S");
		for (int i = 0; i < W; i++) printf("W");
		printf("\n");
	}
}
