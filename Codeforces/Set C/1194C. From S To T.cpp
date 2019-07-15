/* Created by Ishaan Shah on 15-07-2019.
* Problem Name: From S To T
* Problem Link: https://codeforces.com/contest/1194/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll q;
    cin >> q;
    while (q--) {
        string s, t, p, ans = "YES";
        cin >> s >> t >> p;
        map <char, int> mp;
        for (char c = 'a'; c <= 'z'; c++) mp[c] = 0;
        for (int i = 0; i < p.size(); i++) mp[p[i]]++;
        
        if (s.size() > t.size()) {
            cout <<  "NO" << endl;
            continue;
        }
        int sptr = 0, tptr = 0;
        while (true) {
            if (sptr >= s.size() && tptr < t.size()) {
                if (mp[t[tptr]] > 0) {
                    mp[t[tptr]]--;
                    tptr++;
                } else {
                    ans = "NO";
                    break;
                }
            } else if (tptr >= t.size() && sptr < s.size()) {
                ans = "NO";
                break;
            } else {
                if (sptr == s.size() && tptr == t.size()) break;
                if (s[sptr] == t[tptr]) {
                    sptr++;
                    tptr++;
                } else {
                    if (mp[t[tptr]] > 0) {
                        mp[t[tptr]]--;
                        tptr++;
                    } else {
                        ans = "NO";
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}