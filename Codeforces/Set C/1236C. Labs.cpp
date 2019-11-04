/* Created by Ishaan Shah on 17-10-2019.
* Problem Name: Labs
* Problem Link: https://codeforces.com/contest/1236/problem/C 
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
    int arr[305][305];
    int cnt = 1, tmp = 0;
    REP(i, 0, n) {
        if (tmp%2) {
            REP(j ,0 , n) {
                arr[i][j] = cnt;
                cnt++;
            }
        } else {
            for (int j = n-1; j >= 0 ; j--) {
                arr[i][j] = cnt;
                cnt++;
            }
        }
        tmp++;
    }
    REP(i, 0, n) {
        REP(j, 0, n) {
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }
}