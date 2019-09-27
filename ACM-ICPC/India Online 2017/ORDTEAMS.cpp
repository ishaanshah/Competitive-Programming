/* Created by Ishaan Shah on 26-09-2019.
* Problem Name: Ordering teams
* Problem Link: https://www.codechef.com/ACMIND17/problems/ORDTEAMS
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
        pair <int, ii> ppl[3];
        REP(i, 0, 3) {
            cin >> ppl[i].first >> ppl[i].second.first >> ppl[i].second.second;
        }
        sort (ppl, ppl+3);
        if ((ppl[0].first <= ppl[1].first) && (ppl[0].second.first <= ppl[1].second.first) && (ppl[0].second.second <= ppl[1].second.second) && ((ppl[1].first <= ppl[2].first) && (ppl[1].second.first <= ppl[2].second.first) && (ppl[1].second.second <= ppl[2].second.second))) {
            if (((ppl[0].first < ppl[1].first) || (ppl[0].second.first < ppl[1].second.first) || (ppl[0].second.second < ppl[1].second.second)) && ((ppl[1].first < ppl[2].first) || (ppl[1].second.first < ppl[2].second.first) || (ppl[1].second.second < ppl[2].second.second)))
                cout << "yes" << '\n';
            else 
                cout << "no" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}