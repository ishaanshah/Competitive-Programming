/* Created by Ishaan Shah on 05-07-2018.
* Problem Name: https://uva.onlinejudge.org/external/106/10656.pdf
* Problem Link: Maximum Sum (II)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	while (true) {
		int n;
		scanf("%d", &n);
		if (!n) break;
		int temp;
		vector<int> arr;
		for (int i = 0; i < n; i += 1) {
			scanf("%d", &temp);
			if (temp) {
				arr.push_back(temp);
			}
		}
		if (arr.size() == 0) printf("0");
		else {
			for (int i = 0; i < arr.size()-1; i += 1) {
				printf("%d ", arr[i]);
			}
			printf("%d", arr[arr.size()-1]);
		}
		printf("\n");
	}
}
