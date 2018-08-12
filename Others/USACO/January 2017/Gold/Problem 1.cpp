/* Created by Ishaan Shah on 11-08-2018.
* Problem Name: Balanced Photo
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=693
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef vector<int> vi;

class Fenwick_Tree {
	private: vi ft;
	public: 
		Fenwick_Tree(int n) { 
			ft.assign(n+1, 0); 
		}

		int rsq(int b) {
			int sum = 0;
			for (; b; b -= (b & (-b))) {
				sum += ft[b];
			}
			return sum;
		}
		
		int rsq(int a, int b) {
			return rsq(b) - (a == 1 ? 0 : rsq(a-1)); 
		}
		
		void update(int k, int v) {
			for (; k < (int)ft.size(); k += (k & (-k))) {
				ft[k] += v;
			}
		}
};

pair<int, int> arr[100005];
int n;

int main() {
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	
	scanf("%d", &n);
	Fenwick_Tree idt(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i+1;
	}
	sort(arr, arr+n, greater<pair<int, int> >());
	int	ans = 0;
	for (int i = 0; i < n; i++) {
		int l = idt.rsq(1, arr[i].second);
		int r = idt.rsq(arr[i].second, n);
		if (l > 2*r || r > l*2) ans++;
		idt.update(arr[i].second, 1);
	}
	printf("%d", ans);
}
