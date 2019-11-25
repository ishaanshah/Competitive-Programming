/* Created by Ishaan Shah on 04-11-2019.
* Problem Name: Payment Without Change
* Problem Link: https://codeforces.com/contest/1256/problem/A
*/

#include <stdio.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

typedef long long ll;

ll min(ll a, ll b) {
    return (a < b) ? a : b; 
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b, n, S;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &S);
        ll tmp = S/n;
        S -= min(tmp, a)*n;
        if (S > b)
            printf("NO\n");
        else
            printf("YES\n");
    }
}