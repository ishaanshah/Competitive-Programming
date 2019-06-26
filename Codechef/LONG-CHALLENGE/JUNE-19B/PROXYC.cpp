/* Created by Ishaan Shah on 09-06-2019.
* Problem Name: Chef and Proxy
* Problem Link: https://www.codechef.com/JUNE19B/problems/PROXYC
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        string s;
        scanf("%d", &n);
        cin >> s;
        int req = ceil(0.75*n), cnt = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'P') cnt++;
        int prx = 0;
        for (int i = 2; i < n-2; i++) {
            if (cnt >= req) break;
            if (s[i] == 'A' && (s[i-1] == 'P' || s[i-2] == 'P') && (s[i+1] == 'P' || s[i+2] == 'P')) {
                prx++;
                cnt++;
            }
        }
        if (cnt < req) prx = -1;
        printf("%d\n", prx);
    }
}

