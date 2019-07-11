/* Created by Ishaan Shah on 08-07-2019.
* Problem Name: Parity Again
* Problem Link: https://www.codechef.com/JULY19B/problems/PRTAGN
*/

#include <bits/stdc++.h>

using namespace std;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int q, x, evn = 0, odd = 0;
        set <int> st;
        cin >> q;
        while (q--) {
            cin >> x;
            if (st.find(x) == st.end()) {
                if (__builtin_popcount(x)%2 == 1) odd++;
                else evn++;
            }
            int res;
            vector <int> tmp;
            for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
                res = *it^x;
                if (st.find(res) == st.end() && res != 0) {
                    if (__builtin_popcount(res)%2 == 1) odd++;
                    else evn++;
                    tmp.push_back(res);
                }
            }
            for (int i = 0; i < (int)tmp.size(); i++) st.insert(tmp[i]);
            st.insert(x);
            cout << evn << ' ' << odd << endl;
        }
    }
}