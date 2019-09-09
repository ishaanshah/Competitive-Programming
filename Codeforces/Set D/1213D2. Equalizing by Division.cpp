/* Created by Ishaan Shah on 09-09-2019.
* Problem Name: Equalizing by Division
* Problem Link: https://codeforces.com/contest/1213/problem/D2
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
    map<int, int> cnt, sum;
    REP(i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    REP(i, 0, n) {
        int tmp = arr[i];
        int j = 0;
        while (tmp) {
            if (cnt[tmp] < k) {
                cnt[tmp]++;
                sum[tmp] += j;
            }
            j++;
            tmp >>= 1;
        }
    }
    int ans = sum.begin()->second;
    for (auto it = sum.begin(); it != sum.end(); it++)
        if (cnt[it->first] == k)
            ans = min(ans, it->second);
    cout << ans;
}