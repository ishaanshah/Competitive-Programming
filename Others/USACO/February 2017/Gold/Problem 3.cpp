/* Created by Ishaan Shah on 25-08-2018.
* Problem Name: Why Did the Cow Cross the Road III(Gold)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=719
*/

#include <bits/stdc++.h>

#define MAX_N (1 << 17)

using namespace std;

typedef pair<int, int> pi;

int n;

class Fenwick_Tree {
	private: vector<int> ft;
	public: 
		Fenwick_Tree(int n) { 
			ft.assign(n+1, 0); 
		}

		int rsq(int b) {
			int sum = 0;
			for (; b; b -= (b & (-b))) sum += ft[b];
			return sum;
		}
		
		int rsq(int a, int b) {
			return rsq(b) - (a == 1 ? 0 : rsq(a-1)); 
		}
		
		void update(int k, int v) {
			for (; k < (int)ft.size(); k += (k & (-k))) ft[k] += v;	
		}
};

int main () {
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	
	scanf("%d", &n); n *= 2;
	vector<pi> arr(n/2, {-1, -1});
	int x;
	for (int i = 1; i < n+1; i++) {
		scanf("%d", &x); x--;
		if (arr[x].first == -1) arr[x].first = i;
		else arr[x].second = i;
	}
	sort(arr.begin(), arr.end());
	
	Fenwick_Tree ft(MAX_N);
	int ans = 0;
	for (pi elem: arr) {
		ans += ft.rsq(elem.first, elem.second);
		ft.update(elem.second, 1);
	}
	printf("%d", ans);
}
