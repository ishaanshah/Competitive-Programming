/* Created by Ishaan Shah on 24-11-2019.
* Problem Name: Triangles
* Problem Link: https://atcoder.jp/contests/abc143/tasks/abc143_d
*/

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int len[2005], n;

int compare(const void * a, const void * b) { 
    return ( *(int*)a - *(int*)b ); 
}

int upper_bound(int x) {
	int lo = 0, hi = n-1, mid, ans = 0;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (len[mid] >= x)
			hi = mid-1;
		else {
			ans = mid;
			lo = mid+1;
		}
	}
	return ans;
}

int lower_bound(int x) {
	int lo = 0, hi = n-1, mid, ans = n-1;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (len[mid] <= x)
			lo = mid+1;
		else {
			ans = mid;
			hi = mid-1;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &len[i]);
	qsort(len, n, sizeof(int), compare);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int tmp = len[i]+len[j];
			int ub = upper_bound(tmp);
			tmp = len[j]-len[i];
			int lb = lower_bound(tmp);
			ans += ub-lb+1;
			if (lb <= j)
				ans--;
			if (lb <= i)
				ans--;
		}
	}
	printf("%lld\n", ans/3);
	return 0;
}