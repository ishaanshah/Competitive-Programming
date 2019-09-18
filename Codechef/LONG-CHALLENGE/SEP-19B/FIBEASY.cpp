/* Created by Ishaan Shah on 06-09-2019.
* Problem Name: Easy Fibonacci
* Problem Link: https://www.codechef.com/SEPT19B/problems/FIBEASY
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

    int t;
    cin >> t;
    int fib[60];
    fib[0] = 0; fib[1] = 1;
    REP(i, 2, 60) fib[i] = (fib[i-1]+fib[i-2])%10;
    while (t--) {
        ll n;
        cin >> n;
        n--;
        ll bar = 0;
        while (2*bar+1 <= n) bar = 2*bar+1;
        cout << fib[bar%60] << endl;
    }
}