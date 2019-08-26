/* Created by Ishaan Shah on 26-08-2019.
* Problem Name: Uniqueness
* Problem Link: https://codeforces.com/contest/1208/problem/B
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
    vi arr(n);
    REP(i, 0, n) cin >> arr[i];

    int ans = n-1;
    map <int, int> freq;
    REP(i, 0, n) {
        bool flag =  true;
        REP(j, 0, i) {
            freq[arr[j]]++;
            if (freq[arr[j]] == 2) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            freq.clear();
            continue;
        }
        int idx = n;
        for (int j = n-1; j >= i; j--) {
            freq[arr[j]]++;
            if (freq[arr[j]] == 1) idx = j;
            else break;
        }
        ans = min(ans, idx-i);
        freq.clear();
    }
    cout << ans;
}