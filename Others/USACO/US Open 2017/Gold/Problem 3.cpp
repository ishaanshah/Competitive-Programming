/* Created by Ishaan Shah on 26-08-2018.
* Problem Name: Modern Art 2
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=743
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
map<int, int> cnt;
map<int, queue<int> > aux;
int dep = 0;
int ans = 0;
bool b = true;

int main() {
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
		else cnt[a[i]]++;
	}
	for (auto c: cnt) {
		if (c.second == 1) {
			aux[c.first].push(4);
			continue;
		}
		for (int i = 0; i < c.second; i++) {
			if (i == 0) aux[c.first].push(1);
			else if (i == c.second-1) aux[c.first].push(2);
			else {
				aux[c.first].push(3);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if(a[i] == 0 && dep > 0) {
			printf("-1");
			b = false;
			break;
		}
		else if (a[i] == 0 && dep == 0) continue;
		
		if (aux[a[i]].front() == 1) {
			dep++;
			ans = max(ans, dep);
		}
		else if (aux[a[i]].front() == 2) dep--;
		else if (aux[a[i]].front() == 4) {
			dep++;
			ans = max(ans, dep);
			dep--;
		}
		aux[a[i]].pop();
	}
	if (b) printf("%d", ans);
}
