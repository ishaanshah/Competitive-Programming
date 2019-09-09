/* Created by Ishaan Shah on 08-09-2019.
* Problem Name: Unique TT
* Problem Link: https://codeforces.com/group/yny9prUF8z/contest/252289/problem/A
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

    ll q1, q2, q3, k;
    cin >> k >> q1 >> q2 >> q3;
    if (((q1-1)/k)%2 == 0) cout << 'L';
    else cout << 'S';
    if (((q2-1)/k)%2 == 0) cout << 'L';
    else cout << 'S';
    if (((q3-1)/k)%2 == 0) cout << 'L';
    else cout << 'S';

}