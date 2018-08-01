/* Created by Ishaan Shah on 29-07-2018.
* Problem Name: Quality Of Living
* Problem Link: https://wcipeg.com/problem/ioi1013
*/

#include <bits/stdc++.h>

using namespace std;

int r, c, h, w;
int grid[3005][3005], cnvrt[3005][3005];

void convert(int med) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] > med) cnvrt[i][j] = 1;
			else if (grid[i][j] == med) cnvrt[i][j] = 0;
			else cnvrt[i][j] = -1; 
		}
	}
}

int check() {
	int wsum[r];
	bool zer = false;
	for (int i = 0; i <= c-w; i++) {
		wsum[0] = 0;
		for (int j = 0; j < w; j++) {
			wsum[0] += cnvrt[0][i+j];
		}
		for (int j = 1; j < r; j++) {
			wsum[j] = wsum[j-1];
			for (int k = 0; k < w; k++) {
				wsum[j] += cnvrt[j][i+k];
			}
		}
		int block = wsum[h-1];
		for (int j = h; j < r; j++) {
			if (block == 0) zer = true;
			else if (block < 0) return -1;
			block = wsum[j]-wsum[j-h];
		}
	}
	if (zer) return 0;
	return 1;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	scanf("%d %d %d %d", &r, &c, &h, &w);
	for (int i = 0; i < r; i += 1) {
		for (int j = 0; j < c; j += 1) {
			scanf("%d", &grid[i][j]);
		}
	}
	
	int lo = 1, hi = r*c, ans;
	while (lo <= hi) {
		int mid = (lo+hi)/2;
		convert(mid);
		int temp = check();
		if (temp == 0) {
			ans = mid;
			break;
		}
		else if (temp == -1) hi = mid-1;
		else lo = mid+1;
	}
	printf("%d", ans);
}
