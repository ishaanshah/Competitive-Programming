/* Created by Ishaan Shah on 05-06-2018.
* Problem Name: Maximum sum on a torus
* Problem Link: https://uva.onlinejudge.org/external/108/10827.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    while (t--) {
    	int n;
    	scanf("%d", &n);

    	int a[n][n];
		for (int i = 0; i < n; i += 1) for (int j = 0; j < n; j += 1) {
			scanf("%d", &a[i][jcp ]);
			if (i > 0) a[i][j] += a[i-1][j];
			if (j > 0) a[i][j] += a[i][j-1];
			if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
		}
		
		int ans = -100*75*75;
		for (int i = 0; i < n; i += 1) for (int j = 0; j < n; j += 1) {
			for (int k = i; k < n; k += 1) for (int l = j; l < n; l += 1) {
				int rect1 = a[k][l];
				if (i > 0) rect1 -= a[i-1][l];
				if (j > 0) rect1 -= a[k][j-1];
				if (i > 0 && j > 0) rect1 += a[i-1][j-1];
				ans = max(ans, rect1);
				
				int rect2 = 0;
				if (j > 0 && l <= n-1) {
					rect2 = a[k][n-1];
					if (i > 0) rect2 -= a[i-1][n-1];
					rect2 -= rect1;
					ans = max(ans, rect2);
				}
				int rect3 = 0;
				if (i > 0 && k < n-1) {
					rect3 = a[n-1][l];
					if (j > 0) rect3 -= a[n-1][j-1];
					rect3 -= rect1;
					ans = max(ans, rect3);
				}
				
				if(j > 0 && l <= n-1 && i > 0 && k < n-1) {
					ans = max(a[n-1][n-1] - rect1 - rect2 - rect3, ans);
				}
			}
		}
		printf("%d\n", ans);
    }
}
