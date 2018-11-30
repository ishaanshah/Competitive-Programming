/* Created by Ishaan Shah on 28-11-2018.
* Problem Name: Substring Importance
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/STRIMPOR
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

	int t;
	cin >> t;
	while (t--) {
		// Take input
		int n, k;
		cin >> n >> k;
		string str[n];
		for (int i = 0; i < n; i++) cin >> str[i];
		
		// Create prefix sum
		int x[n][3], z[n][3];
		for (int i = 0; i < 3; i++) {
		    x[0][i] = 0;
		    z[0][i] = 0;
		}
		if (str[0] == "X") x[0][0] = 1;
        if (str[0] == "Z") z[0][0] = 1;
		for (int i = 1; i < n; i++) {
		    if (str[i] == "X") {
		        x[i][i%3] = x[i-1][i%3]+1;
                z[i][i%3] = z[i-1][i%3];
		    } else if (str[i] == "Z") {
		        z[i][i%3] = z[i-1][i%3]+1;
                x[i][i%3] = x[i-1][i%3];
		    } else {
                x[i][i%3] = x[i-1][i%3];
                z[i][i%3] = z[i-1][i%3];
		    }
            x[i][(i+1)%3] = x[i-1][(i+1)%3];
            x[i][(i+2)%3] = x[i-1][(i+2)%3];
            z[i][(i+1)%3] = z[i-1][(i+1)%3];
            z[i][(i+2)%3] = z[i-1][(i+2)%3];
		}
		
		// Initialize window
		int wnd = 0;
		for (int i = 0; i < k; i++) {
			int j = (i+2)%3;
			if (str[i] == "X") wnd += z[n-1][j]-z[i][j];
		}
		
		// Slide the window
		int ans = wnd;
		for (int i = 1; i <= n-k-1; i++) {
			// Remove element
			int j = (i-1+1)%3;			
			if (str[i-1] == "Z") {
				wnd -= x[(i-1)][j];
			}
			
			// Add element
			j = (i+k-1+2)%3;
			if (str[i+k-1] == "X") {
				wnd += (z[n-1][j] - z[i+k-1][j]);
			}
			ans = min(ans, wnd);
		}
		
		// Last window
		wnd = 0;
		for (int i = n-k; i < n; i++) {
			if (str[i] == "Z") {
				wnd += x[i][(i+1)%3];
			}
		}
		ans = min(ans, wnd);
		printf("%d\n", ans);
	}
}
