/* Created by Ishaan Shah on 24-12-2017.
 * Problem Name: FTML
 * Problem Link: https://www.codechef.com/COOK89/problems/FTML
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int team_1 = 0;
        int team_2 = 0;
        if(n == 0) {
            cout << "Draw" << endl;
            continue;
        }
        string first;
        string sec;
        cin >> first;
        team_1++;
        for(int i = 1; i < n; i++) {
            string inp;
            cin >> inp;
            if(inp == first) {
                team_1++;
            }
            else {
                sec = inp;
                team_2++;
            }
        }
        if(team_1 == team_2) {
            cout << "Draw" << endl;
        }
        else if(team_1 > team_2) {
            cout << first << endl;
        }
        else {
            cout << sec << endl;
        }
    }
}
