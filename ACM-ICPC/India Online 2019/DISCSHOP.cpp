/* Created by Ishaan Shah on 18-10-2019.
* Problem Name: Discount in a Shop
* Problem Link: https://www.codechef.com/ICPCIN19/problems/DISCSHOP
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int rem_dig(int pos, int n) {
    int res = 0, tmp = 1;
    for (int i = 0; i < pos; i++) {
        res += (n%10)*tmp;
        n /= 10;
        tmp *= 10;
    }
    n /= 10;
    while (n) {
        res += (n%10)*tmp;
        tmp *= 10;
        n /= 10;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1e9+5;
        for (int i = 0; i < 10; i++) {
            ans = min(ans, rem_dig(i, n));
        }
        cout << ans << '\n';
    }
}