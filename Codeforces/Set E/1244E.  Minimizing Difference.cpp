/* Created by Ishaan Shah on 14-10-2019.
* Problem Name: Minimizing Difference
* Problem Link: https://codeforces.com/contest/1244/problem/E
*/

#include <iostream>      

using namespace std;

typedef long long ll;

ll n, k;
ll arr[100005];

ll calc(ll mn, ll d) {
    ll mx = mn+d, res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mx) res += (arr[i]-mx);
        if (arr[i] < mn) res += (mn-arr[i]);
    }
    return res;
}

bool check(ll d) {
    ll lo = 0, hi = 1e9, mid1, mid2, tmp = 1e15;
    while (abs(hi-lo) > 3) {
        mid1 = lo + (hi-lo)/3;
        mid2 = hi - (hi-lo)/3;
        ll tmp1 = calc(mid1, d);
        ll tmp2 = calc(mid2, d);
        tmp = min(tmp1, tmp);
        tmp = min(tmp2, tmp);
        if (tmp1 > tmp2)
            lo = mid1;
        else 
            hi = mid2;
    }
    ll ans = min(calc(lo, d), calc(hi, d));
    ans = min(tmp, ans);
    return (k >= ans);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    ll lo = 0, hi = 1e9, mid, ans;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if (check(mid)) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    printf("%lld", ans);
}