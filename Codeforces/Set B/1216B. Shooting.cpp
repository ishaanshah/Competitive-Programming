/* Created by Ishaan Shah on 21-09-2019.
* Problem Name: Shooting
* Problem Link: https://codeforces.com/contest/1216/problem/B
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
    vii arr(n);
    REP(i, 0, n) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end(), greater<ii>());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += arr[i].first*i+1;

    cout << ans << '\n';
    for (int i = 0; i < n; i++)
        cout << arr[i].second << ' ';

    return 0;
}