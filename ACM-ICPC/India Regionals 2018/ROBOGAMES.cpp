/* Created by Ishaan Shah on 20-09-2019.
* Problem Name: A Game of Robots
* Problem Link: https://www.codechef.com/ACMIND18/problems/ROBOGAME
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
        string s;
        cin >> s;
        int freq[55], n = s.size();
        memset(freq, 0, sizeof(freq));
        REP(i, 0, n) {
            if (s[i] != '.') {
                int r = s[i]-'0';
                for (int j = i-1; j >= max(0, i-r); j--) 
                    freq[j]++;
                for (int j = i; j <= min(n-1, i+r); j++) 
                    freq[j]++;
            }
        }
        
        int flag = 1;

        for (int i = 0; i < 55; i++) {
            if (freq[i] > 1) {
                flag = 0;
                break;
            }
        }

        if (flag)
            cout << "safe" << '\n';
        else
            cout << "unsafe" << '\n';
    }
}