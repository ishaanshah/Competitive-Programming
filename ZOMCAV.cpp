/* Created by Ishaan Shah on 06-08-2019.
* Problem Name: Zombie and the Caves
* Problem Link: https://www.codechef.com/AUG19B/problems/ZOMCAV
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
		
		void update(int k, int v) {
			for (; k < (int)ft.size(); k += (k & (-k))) {
				ft[k] += v;
			}	
		}
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans = "YES";
        Fenwick_Tree ft(n+1);
        vi c(n+1), h(n+1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int i = 1; i <= n; i++) {
            int l = i-c[i];
            int r = i+c[i];
            if (l < 1) l = 1;
            if (r > n) r = n;
            ft.update(l, 1);
            ft.update(r+1, -1);
        }
        map<int, int> cvmap;
        for (int i = 1; i <= n; i++) cvmap[ft.rsq(i)]++;
        for (int i = 1; i <= n; i++) {
            cvmap[h[i]]--;
            if (cvmap[h[i]] < 0) {
                ans = "NO";
                break;
            }
        }
        cout << ans << "\n";
    }
}