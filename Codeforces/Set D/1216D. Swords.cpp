/* Created by Ishaan Shah on 21-09-2019.
* Problem Name: Swords
* Problem Link: https://codeforces.com/contest/1216/problem/D
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

ll printEqualModNumbers (vi arr, ll n) { 
    sort(arr.begin(), arr.end());  
    ll d = arr[n-1] - arr[0]; 
    vi v; 
    for (int i=1; i*i<=d; i++) { 
        if (d%i == 0) { 
            v.push_back(i); 
            if (i != d/i) 
                v.push_back(d/i); 
        } 
    } 
  
    sort(v.begin(), v.end(), greater<ll>());
    for (int i=0; i<v.size(); i++) { 
        int temp = arr[0]%v[i]; 
        int j; 
        for (j=1; j<n; j++) 
            if ((arr[j] % v[i] != temp) && (arr[j])) 
                break; 
  
        if (j == n)
            return v[i]; 
    } 
} 

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n;
    cin >> n;
    ll sum = 0;
    vi arr(n);
    REP(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (n == 2) {
        cout << 1 << ' ' << abs(arr[0]-arr[1]);
        return 0;
    }
    ll z, x, st;
    z = printEqualModNumbers(arr, n);
    x = *max_element(arr.begin(), arr.end());
    ll y = (n*x-sum)/z;
    cout << y << ' ' << z;
}