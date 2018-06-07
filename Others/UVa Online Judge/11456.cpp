/* Created by Ishaan Shah on 07-06-2018.
* Problem Name: Trainsorting
* Problem Link: https://uva.onlinejudge.org/external/114/11456.pdf
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

    	int a[n];
		for (int i = 0; i < n; i += 1) {
			scanf("%d", &a[i]);
		}
		
		int dp1[n];
		dp1[n-1] = 1;
		int dp2[n];
		dp2[n-1] = 1;
		for (int i = n-2; i >= 0; i -= 1) {
			dp1[i] = 1;
			dp2[i] = 1;
			for (int j = n-1; j > i; j -= 1) {
				if (a[j] > a[i]) dp2[i] = max(dp2[i], dp2[j]+1);
				if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j]+1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i += 1) {
			ans = max(ans, dp1[i]+dp2[i]-1);
		}
		printf("%d\n", ans);
    }
}
