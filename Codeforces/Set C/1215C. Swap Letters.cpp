/* Created by Ishaan Shah on 19-09-2019.
* Problem Name: Swap Letters
* Problem Link: https://codeforces.com/contest/1215/problem/C
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
    string s, t;
    cin >> s >> t;
    vi pos1, pos2;
    int cnt1 = 0, cnt2 = 0;
    REP(i, 0, n) {
        if (s[i] == 'a' && t[i] == 'b') 
            pos1.push_back(i+1);
        else if (s[i] == 'b' && t[i] == 'a')
            pos2.push_back(i+1);
        if (s[i] == 'a')
            cnt1++;
        if (t[i] == 'a')
            cnt2++;
    }
    if ((pos1.size()&1)^(pos2.size()&1)) {
        cout << -1;
        return 0;
    } 
    if (pos1.size()&1) {
        cout << (pos1.size()-1)/2 + (pos2.size()-1)/2 + 2 << '\n';
        cout << *(pos1.end()-1) << ' ' << *(pos1.end()-1) << '\n';
        cout << *(pos1.end()-1) << ' ' << *(pos2.end()-1) << '\n';
        pos1.pop_back(); pos2.pop_back();
    } else {
        cout << pos1.size()/2 + pos2.size()/2 << '\n';
    }
    for (int i = 0; i < pos1.size(); i+=2)
        cout << pos1[i] << ' ' << pos1[i+1] << '\n';
    for (int i = 0; i < pos2.size(); i+=2)
        cout << pos2[i] << ' ' << pos2[i+1] << '\n';

    return 0;
}