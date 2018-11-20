/* Created by Ishaan Shah on 20-11-2018.
* Problem Name: 0/1 Tiles
* Problem Link: http://opc.iarcs.org.in/index.php/problems/01TILES
*/

#include <stdio.h>

#define mod 15746

using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	
	int dp[n+1];
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
	}
	
	printf("%d", dp[n]);
}
