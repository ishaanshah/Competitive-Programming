/* Created by Ishaan Shah on 17-12-2019.
* Problem Name: Competitive Programmer
* Problem Link: http://codeforces.com/contest/1266/problem/A
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
    while (n--) {
        string s;
        cin >> s;
        bool flag = true;
        int even = 0, zero = 0, sum = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if ((s[i]-'0') % 2 == 0)
                even++;
            if (s[i] == '0')
                zero++;
            sum += s[i]-'0';
        }
        if (zero == 0)
            flag = false;
        if (zero == 1 && even == 1)
            flag = false;
        if (sum % 3 != 0)
            flag = false;
        
        if (flag)
            cout << "red" << '\n';
        else
            cout << "cyan" << '\n';
    }
    return 0;
}