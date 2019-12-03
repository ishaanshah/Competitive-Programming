/* Created by Ishaan Shah on 30-11-2019.
* Problem Name: PIN Codes
* Problem Link: https://codeforces.com/contest/1263/problem/B
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool sort_by_sec(const pair<string, int> a, const pair<string, int> b) {
    return (a.second < b.second);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        set <string> st, ast;
        vector <pair<string, int> > arr, farr; 
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            arr.push_back(make_pair(tmp, i));
            st.insert(tmp);
            ast.insert(tmp);
        }
        sort(arr.begin(), arr.end());

        int idx = 0, ans = 0;
        for (auto it = st.begin(); it != st.end(); it = next(it)) {
            int cnt = 0;
            string str = *it;
            while (idx < n) {
                if (str == arr[idx].first)
                    cnt++;
                else
                    break;
                idx++;
            }
            cnt--;
            ans += cnt;
            farr.push_back(arr[idx-cnt-1]);
            for (int i = 0; i < cnt; i++) {
                string tmp = arr[idx-i-1].first;
                for (int j = 0; j < 10; j++) {
                    tmp[0] = j+'0';
                    if (ast.find(tmp) == ast.end()) {
                        ast.insert(tmp);
                        farr.push_back(make_pair(tmp, arr[idx-i-1].second));
                        break;
                    }
                }
            }
        }

        sort(farr.begin(), farr.end(), sort_by_sec);
        cout << ans << '\n';
        for (int i = 0; i < n; i++)
            cout << farr[i].first << '\n';
    }

    return 0;
}