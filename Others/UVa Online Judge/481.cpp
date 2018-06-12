/* Created by Ishaan Shah on 12-06-2018.
* Problem Name: What Goes Up
* Problem Link: https://uva.onlinejudge.org/external/4/481.pdf
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

void reconstruct_print(int end, int a[], int p[]) {
  	int x = end;
  	stack<int> s;
  	for (; p[x] >= 0; x = p[x]) s.push(a[x]);
 	printf("%d\n", a[x]);
  	for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

  	int n = 0;
  	int A[MAX_N];
  	while (scanf("%d", &A[n]) != EOF) n++;
  	
	int L[MAX_N], L_id[MAX_N], P[MAX_N];
	int lis = 0, lis_end = 0;
  	for (int i = 0; i < n; ++i) {
		int pos = lower_bound(L, L + lis, A[i]) - L;
    	L[pos] = A[i];
    	L_id[pos] = i;
    	P[i] = pos ? L_id[pos - 1] : -1;
    	if (pos + 1 >= lis) {
    	  lis = pos + 1;
    	  lis_end = i;
    	}
	}
  	printf("%d\n-\n", lis);
	reconstruct_print(lis_end, A, P);
}

