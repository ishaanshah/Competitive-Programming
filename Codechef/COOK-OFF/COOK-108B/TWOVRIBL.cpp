/* Created by Ishaan Shah on 21-07-2019.
* Problem Name: Two Variables
* Problem Link: https://www.codechef.com/COOK108B/problems/TWOVRIBL
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(long long i = a; i < b; i++)

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
    vector<ll> data;
    data.push_back(1);
    ll sum = 1;
    REP(i, 2, 1e9+1) {
        if (i*i > sum) {
            sum += i*i;
            data.push_back(sum);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        n = n*n;
        auto it = lower_bound(data.begin(), data.end(), n);
        cout << (int)(it-data.begin())+1 << endl;
    }
}