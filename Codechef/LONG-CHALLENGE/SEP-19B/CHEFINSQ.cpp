/* Created by Ishaan Shah on 07-09-2019.
* Problem Name: Chef and Interesting Subsequences
* Problem Link: https://www.codechef.com/SEPT19B/problems/CHEFINSQ
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll coeff(ll n, ll k) { 
    ll C[n + 1][k + 1]; 
    ll i, j; 
  
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) {  
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vi arr(n);
        map<ll, ll> freq;
        REP(i, 0, n) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        sort(arr.begin(), arr.end());
        set <ll> st;
        map <ll, ll> mp;
        REP(i, 0, k) { 
            st.insert(arr[i]);
            mp[arr[i]]++;
        }
        ll ans = 1;
        while (!st.empty()) {
            ll a = *st.begin();
            ans = ans*coeff(freq[a], mp[a]);
            st.erase(a);
        }
        cout << ans << endl;
    }
}
