/* Created by Ishaan Shah on 21-09-2019.
* Implenetation of Segment Tree and it's variations.
* Inspired from https://codeforces.com/blog/entry/18051 
*/

#include <bits/stdc++.h>

using namespace std;

class Segment_Tree {
    private:
        int dummy, n;
        vector <int> tree;

    public:
        Segment_Tree(vector<int> &arr, int m, int d) {
            n = m;
            dummy = d;
            tree.resize(2*m, d);
            for (int i = 0; i < n; i++)
                tree[i+n] = arr[i];
        }

        int op(int a, int b) {
            return min(a, b);
        }

        void build() {
            for (int i = n-1; i > 0; i--)
                tree[i] = op(tree[i*2], tree[i*2+1]);
        }

        void update(int pos, int val) {
            pos += n;
            tree[pos] = val;
            while (pos > 1) {
                pos >>= 1;
                tree[pos] = op(tree[pos*2], tree[pos*2+1]);
            }
        }

        int query(int l, int r) {
            int res = 1e9;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) res = op(tree[l++], res);
                if (r&1) res = op(tree[--r], res); 
            }
            return res;
        }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    Segment_Tree st(arr, n, 1e9);
    st.build();

    while (m--) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r+1) << '\n';
        } else {
            int pos, val;
            cin >> pos >> val;
            st.update(pos, val);
        }
    }
}