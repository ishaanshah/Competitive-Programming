/* Created by Ishaan Shah on 08-07-2018.
* Implementation of Fenwick Tree take from CP3 by Steven & Felix Halim
*/

#include <bits/stdc++.h>

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

int main () {
	int f[] = {2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9};
	Fenwick_Tree ft(10);
	for (int i = 0; i < 11; i++) ft.update(f[i], 1);
	printf("RSQ(5, 7): %d\n", ft.rsq(5, 7));
	ft.update(5, 2);
	printf("RSQ(5, 7): %d\n", ft.rsq(5, 7));
}
