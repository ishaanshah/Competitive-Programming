/* Created by Ishaan Shah on 04-06-2018.
* Problem Name: Garbage Heap
* Problem Link: https://uva.onlinejudge.org/external/107/10755.pdf
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    long long q[21][21][21];
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        if (tc != 1) printf("\n");
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i <= a; i++) {
        	for (int j = 0; j <= b; j++) {
        		for (int k = 0; k <= c; k++) {
            		if (i * j * k == 0) {
                		q[i][j][k] = 0;
                		continue;
            		}
            		int v;
            		cin >> q[i][j][k];
            		q[i][j][k] += q[i-1][j][k] + q[i][j-1][k] - q[i-1][j-1][k];
        		}
        	}
        }
        long long m = q[1][1][1];
        for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) {
	        for (int x = i + 1; x <= a; x++) for (int y = j + 1; y <= b; y++) {
		        long long s = 0;
		        for (int k = 1; k <= c; k++) {
		            long long t = q[x][y][k] - q[i][y][k] - q[x][j][k] + q[i][j][k];
		            s += t;
		            m = max(m, s);
		            if (s < 0) s = 0;
		        }
		    }
        }
        printf("%lld\n", m);
    }
}
