/* Created by Ishaan Shah on 22-09-2019.
* Problem Name: Playing with Matches
* Problem Link: https://www.codechef.com/COOK110B/problems/MATCHES
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
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll c = a+b;
        ll res = 0;
        while (c) {
            int num = c%10;
            switch (num) {
                case 0:
                    res += 6;
                    break;
                case 1:
                    res += 2;
                    break;
                case 2:
                    res += 5;
                    break;
                case 3:
                    res += 5;
                    break;
                case 4:
                    res += 4;
                    break;
                case 5:
                    res += 5;
                    break;
                case 6:
                    res += 6;
                    break;
                case 7:
                    res += 3;
                    break;
                case 8:
                    res += 7;
                    break;
                case 9:
                    res += 6;
                    break;    
            }
            c/=10;
        }
        cout << res << '\n';
    }
}