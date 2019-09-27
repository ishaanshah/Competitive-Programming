/* Created by Ishaan Shah on 27-09-2019.
* Problem Name: Compression Algorithm
* Problem Link: https://www.codechef.com/ACMIND17/problems/COMPEXP
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long double n, k, N, D, diff, bar;
		cin>>n>>k;
		if (fabs(k-1.0) < 0.0000001) {
			cout << "2.0000000\n";
			continue;
		}
		bar=(2.0 + (k-1)*4.0)/k;
		diff = (2.0-2.0/k);
		printf("%.7Lf\n", diff*(n-2)+bar);
	}
}
