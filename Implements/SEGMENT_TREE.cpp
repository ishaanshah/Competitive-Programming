/* Created by Ishaan Shah on 21-09-2019.
** Implenetation of Segment Tree and it's variations.
** Inspired from https://codeforces.com/blog/entry/18051 
*/

// Note that the range is given by [l, r)

#include <bits/stdc++.h>

using namespace std;

// Implemention of standard segment tree without Lazy-Propagation

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
            // Your operation here;
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
            int res = dummy;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) res = op(tree[l++], res);
                if (r&1) res = op(tree[--r], res); 
            }
            return res;
        }
};

/* Implementation of Invert segment tree
** The operations are inverted, i.e update is done on a range
** and query is done on a single element.
*/

class Invert_Segment_Trees {
    private:
        int n, dummy;
        vector<int> tree;

    public:
        Invert_Segment_Trees(const vector<int> &arr, int m, int d) {
            n = m;
            dummy = d;
            tree.resize(2*n, dummy);
            for (int i = 0; i < n; i++)
                tree[i+n] = arr[i];
        }

        void build() {
            for (int i = n-1; i > 0; i--)
                tree[i] = tree[i*2] + tree[i*2+1];
        }

        int query(int pos) {
            pos += n;
            int res = dummy;
            while (pos > 1) {
                res = res + tree[pos];
                pos >>= 1;
            }
            return res;
        }

        void update(int l, int r, int k) {
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) tree[l++] += k;
                if (r&1) tree[r--] += k;
            }
        }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
}