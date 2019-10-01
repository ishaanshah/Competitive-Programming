/* Created by Ishaan Shah on 01-10-2019.
* Problem Name: Distinct Characters Queries
* Problem Link: https://codeforces.com/contest/1234/problem/D
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class Fenwick_Tree {
	private: vi ft;
	public:
		void resize(int n) { 
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


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.length(), q;
    cin >> q;
    Fenwick_Tree ft[26];
    for (int i = 0; i < 26; i++)
        ft[i].resize(n);
    
    for (int i = 0; i < n; i++)
        ft[s[i]-'a'].update(i+1, 1);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            ft[s[pos-1]-'a'].update(pos, -1);
            s[pos-1] = c;
            ft[s[pos-1]-'a'].update(pos, 1);
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                int freq = ft[i].rsq(l, r);
                if (freq) ans++;
            }
            cout << ans << '\n';
        }
    }
}