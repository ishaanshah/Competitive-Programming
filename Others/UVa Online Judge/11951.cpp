/* Created by Ishaan Shah on 06-06-2018.
* Problem Name: Area
* Problem Link: https://uva.onlinejudge.org/external/119/11951.pdf
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    int cn = 1;
    while (t--) {
    	int n, m, p;
    	scanf("%d%d%d", &n, &m, &p);

    	int a[n][m];
		for (int i = 0; i < n; i += 1) for (int j = 0; j < m; j += 1) {
			scanf("%d", &a[i][j]);
			if (i > 0) a[i][j] += a[i-1][j];
			if (j > 0) a[i][j] += a[i][j-1];
			if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
		}
		
		ll price = p, area = 0;
		for (int i = 0; i < n; i += 1) for (int j = 0; j < m; j += 1) {
			for (int k = i; k < n; k += 1) for (int l = j; l < m; l += 1) {
				ll plot_c = a[k][l];
				if (i > 0) plot_c -= a[i-1][l];
				if (j > 0) plot_c -= a[k][j-1];
				if (i > 0 && j > 0) plot_c += a[i-1][j-1];
				if (plot_c <= p) {
					ll plot_a = (l-j+1)*(k-i+1);
					if (plot_a > area) {
						price = plot_c;
						area = plot_a;
					} else if (plot_a == area) {
						price = min(plot_c, price);
					}
				}
			}
		}
		if (area == 0) price = 0;
		printf("Case #%d: %lld %lld\n", cn, area, price);
		cn++;
    }
}
