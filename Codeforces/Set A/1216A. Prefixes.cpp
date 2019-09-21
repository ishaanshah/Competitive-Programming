/* Created by Ishaan Shah on 21-09-2019.
* Problem Name: 
* Problem Link: https://codeforces.com/contest/1216/problem/A
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
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == 'a' && s[i+1] == 'a') {
            cnt++;
            s[i] = 'b';
        } else if (s[i] == 'b' && s[i+1] == 'b') {
            cnt++;
            s[i] = 'a';
        }
    }


    cout << cnt << '\n' << s;
}