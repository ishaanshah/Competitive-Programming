/* Created by Ishaan Shah on 05-06-2018.
* Problem Name: Maximum Sum
* Problem Link: https://uva.onlinejudge.org/external/1/108.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i += 1) for (int j = 0; j < n; j += 1) {
		scanf("%d", &a[i][j]);
		if (i > 0) a[i][j] += a[i-1][j];
		if (j > 0) a[i][j] += a[i][j-1];
		if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
    }
    
    int ans = -127*100*100;
    for (int i = 0; i < n; i += 1) for (int j = 0; j < n; j += 1) {
    	for (int k = i; k < n; k += 1) for (int l = j; l < n; l += 1) {
    		int temp = a[k][l];
    		if (i > 0) temp -= a[i-1][l];
    		if (j > 0) temp -= a[k][j-1];
    		if (i > 0 && j > 0) temp += a[i-1][j-1];
    		ans = max(temp, ans);
    	}
    }
    
    printf("%d", ans);
}
