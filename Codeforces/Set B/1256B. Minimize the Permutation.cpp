/* Created by Ishaan Shah on 04-11-2019.
* Problem Name: Minimize the Permutation
* Problem Link: https://codeforces.com/contest/1256/problem/B
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
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int moves = n-1;
        int pos = 0;
        while (moves && pos < n) {
            int mn_idx = min_element(arr.begin()+pos, arr.end())-arr.begin();
            if (mn_idx == pos) {
                pos++;
                continue;
            }
            for (int i = mn_idx-1; i >= pos; i--) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                moves--;
                if (moves == 0)
                    break;
            }
            pos = mn_idx;
        }
        
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
}