/* Created by Ishaan Shah on 14-10-2019.
* Problem Name: Race Time!
* Problem Link: https://www.codechef.com/problems/AMCS03
*/

#include <bits/stdc++.h>

#define eps 1e-9

using namespace std;

int n; 
double k;

double f(double t, vector<double> &d, vector<double> &s) {
    double mx = -1, mn = 1e15, tmp;
    for (int i = 0; i < n; i++) {
        tmp = d[i]+t*s[i];
        mx = max(mx, tmp);
        mn = min(mn, tmp);
    }
    return mx-mn;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    cin >> n;
    vector <double> d(n), s(n);
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> d[i];
    }
    double lo = 0.0, hi = k, mid1, mid2; 
    while (hi-lo > eps) {
        mid1 = lo + (hi-lo)/3.0;
        mid2 = hi - (hi-lo)/3.0;
        if (f(mid1, d, s) > f(mid2, d, s))
            lo = mid1;
        else
            hi = mid2;
    }
    printf("%.6lf\n", f(lo, d, s));
}