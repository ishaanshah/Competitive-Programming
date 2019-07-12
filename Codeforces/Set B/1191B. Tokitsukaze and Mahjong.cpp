/* Created by Ishaan Shah on 12-07-2019.
* Problem Name: Tokitsukaze and Mahjong
* Problem Link: https://codeforces.com/contest/1191/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    vector <int> num; vector<char> str;
    string tmp;
    for (int i = 0; i < 3; i++)  {
        cin >> tmp;
        num.push_back((int)(tmp[0]-'0'));
        str.push_back(tmp[1]);
    }
    for (int i = 0; i < 3; i++) {
        int a = num[i], b = num[i]; char x = str[i];
        if ((num[(i+1)%3] == a && num[(i+2)%3] == b) && (str[(i+1)%3] == x && str[(i+2)%3] == x)) {
            cout << 0;
            return 0;
        }
        a = num[i]+1; b = num[i]+2;
        if (((num[(i+1)%3] == a && num[(i+2)%3] == b) || (num[(i+1)%3] == b && num[(i+2)%3] == a)) && (str[(i+1)%3] == x && str[(i+2)%3] == x)) {
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        int a = num[i]; char x = str[i];
        if ((num[(i+1)%3] == a && str[(i+1)%3] == x) || (num[(i+2)%3] == a && str[(i+2)%3] == x)) {
            cout << 1;
            return 0;
        }
        a = num[i]+1;
        if ((num[(i+1)%3] == a && str[(i+1)%3] == x) || (num[(i+2)%3] == a && str[(i+2)%3] == x)) {
            cout << 1;
            return 0;
        }
        a = num[i]+2;
        if ((num[(i+1)%3] == a && str[(i+1)%3] == x) || (num[(i+2)%3] == a && str[(i+2)%3] == x)) {
            cout << 1;
            return 0;
        }
    }
    cout << 2;
    return 0;    
}
