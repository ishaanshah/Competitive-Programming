/* Created by Ishaan Shah on 16-07-2019.
* Problem Name: Guess the Prime!
* Problem Link: https://www.codechef.com/problems/GUESSPRM
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> pfactor;
ll x = 1e5;

bool isprime (ll n) {
    for(ll i = 2; i <= (ll)sqrt(n); i++) if(n%i == 0) return false;
    return true;
}

void factorize(ll n) {
    if (isprime(n)) pfactor.insert(n);
    for (ll i = 2; i <= (ll)sqrt(n); i++) {
        if (n%i == 0) {
            if (isprime(i)) pfactor.insert(i);
            if (isprime(n/i)) pfactor.insert(n/i);
        }
    }
}

int main () {
    ll t;
    cin >> t;
    while (t--) {
        ll inp;
        cout << "1 " << x << endl;
        cin >> inp;
        if (inp == -1) return 0;
        factorize(x*x-inp);
        set<ll> modst; map<ll, ll> modmp; ll q;
        for (ll i = 2; i <= 10000; i++) {
            modst.clear(); modmp.clear();
            ll tmp;
            for (auto it = pfactor.begin(); it != pfactor.end(); it++) {
                tmp = ((i%*it)*(i%*it))%*it;
                if (modst.find(tmp) != modst.end()) continue;
                modst.insert(tmp);
                modmp[tmp] = *it;
            }
            if (modst.size() == pfactor.size()) {
                q = i;
                break;
            }
        }
        cout << "1 " << q << endl;
        cin >> inp;
        if (inp == -1) return 0;
        cout << "2 " << modmp[inp] << endl;
        string sinp;
        cin >> sinp;
        if (sinp == "No") return 0;
        fflush(stdout);
        fflush(stdin);
        pfactor.clear();
    }
    return 0;
}
