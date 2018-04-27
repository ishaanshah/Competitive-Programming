/* Created by Ishaan Shah on 08-04-2018.
* Problem Name: GOODPREF
* Problem Link: https://www.codechef.com/APRIL18B/problems/GOODPREF/
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    string s;
    long long n;
    while(t--) {
        cin >> s >> n;
        long long a = 0; long long b = 0;
        long long pref_diff[s.length()];
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') {
                a++;
            } else {
                b++;
            }
            pref_diff[i] = a - b;
        }

        long long diff = a-b;
        long long ans = 0;
        if(diff == 0) {
            for(int i = 0; i < s.length(); i++) {
                if(pref_diff[i] > 0) {
                    ans += n;
                }
            }
        } else if(diff > 0) {
            for(int i = 0; i < s.length(); i++) {
                if(pref_diff[i] <= 0) {
                    ans += max(n-(int)ceil((float)(-pref_diff[i]+1)/diff), 0ll);
                }  else {
                    ans += n;
                }
            }
        } else {
            for(int i = 0; i < s.length(); i++) {
                if(pref_diff[i] > 0) {
                    ans += min((long long)ceil(-(float)pref_diff[i]/(float)diff), (long long)n);
                }
            }
        }
        cout << ans << endl;
    }
}