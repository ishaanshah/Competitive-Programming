/* Created by Ishaan Shah on 04-05-2018.
* Problem Name: Stamp Painting
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=791
*/

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
 
int dp[10000005];
 
int main()
{
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

	int N, M, K;
	cin >> N >> M >> K;
	
	dp[0] = 0;
	for(int i = 1; i < K; i++) {
		dp[i] = (M*((long long)dp[i-1]) + M)%mod;
    }

	for(int i = K; i <= N; i++) {
		dp[i] = (M*((long long)dp[i-1]) + mod - ((M-1)*((long long)dp[i-K]))%mod)%mod;
    }

	int andp = 1;
	for(int i = 1; i <= N; i++) {
		andp = (M*((long long)andp))%mod;
    }

	cout << (((long long)andp) + mod - ((long long)dp[N]) + dp[N-1])%mod << endl;
}