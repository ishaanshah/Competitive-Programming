/* Created by Ishaan Shah on 14-01-2019.
* Problem Name: Covention II
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=859 
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<int, int>, int> pii;
typedef pair<int, pair<int, int> > iip;

int n;
pii cow[100005];
priority_queue <iip> pq;

int main() {
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &cow[i].first.first, &cow[i].first.second);
		cow[i].second = n-i;
	}
	
	sort(cow, cow+n);
	int i = 0, time = 0, ans = 0;
	while (true) {
		while (i < n and time >= cow[i].first.first) {
			pq.push(make_pair(cow[i].second, make_pair(cow[i].first.first, cow[i].first.second)));
			i++;
		}
		
		if (pq.empty() and i < n) {
			time = cow[i].first.first;
			pq.push(make_pair(cow[i].second, make_pair(cow[i].first.first, cow[i].first.second)));
			i++;
		}
		
		ans = max(time-pq.top().second.first, ans);
		time += pq.top().second.second;
		pq.pop();
		
		if (pq.empty() and i >=n) break;
	}
	
	printf("%d", ans);
}
