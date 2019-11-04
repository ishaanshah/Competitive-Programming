/* Created by Ishaan Shah on 16-10-2019.
* Problem Name: Alice and the List of Presents
* Problem Link: https://codeforces.com/contest/1236/problem/B
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

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    int ans = 0;
    set <int> st;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    while (i < n) {
        if (q.front() != arr[i] && st.find(q.front()) == st.end()) {
            ans++;
            st.insert(arr[i]);
            i++;
        } else if (q.front() != arr[i] && st.find(q.front()) != st.end()) {
            q.pop();
        }
        else {
            q.pop();
            i++;
        }
    }
    cout << ans;
}