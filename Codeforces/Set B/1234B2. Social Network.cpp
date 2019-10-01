/* Created by Ishaan Shah on 01-10-2019.
* Problem Name: Social Network (hard version)
* Problem Link: https://codeforces.com/contest/1234/problem/B2
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vi arr(n);
    REP(i, 0, n) cin >> arr[i];
    set<int> st;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (st.find(arr[i]) == st.end()) {
            if (dq.size() == k) {
                int bck = *(dq.end()-1);
                dq.pop_back();
                st.erase(bck);
                st.insert(arr[i]);
                dq.push_front(arr[i]);
            } else {
                st.insert(arr[i]);
                dq.push_front(arr[i]);
            }
        }
    }
    int len = dq.size();
    cout << dq.size() << '\n';
    for (int i = 0; i < len; i++) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }

    return 0;
}