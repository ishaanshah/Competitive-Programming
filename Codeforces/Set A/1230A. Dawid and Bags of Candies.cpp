/* Created by Ishaan Shah on 23-09-2019.
* Problem Name: Dawid and Bags of Candies
* Problem Link: https://codeforces.com/contest/1230/problem/A
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
 
    int a[4], flag = 0;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a+4);
    int sum = 0;
    REP(i, 0, 4) 
        sum += a[i];
    
    if (sum-a[3] == a[3])
        flag = 1;
    
    REP(i, 0, 4) {
        REP(j, i+1, 4) {
            int tmp = a[i]+a[j];
            if (sum-tmp == tmp)
                flag = 1;
        }
    }
 
    if (flag) cout << "YES";
    else cout << "NO";
 
    return 0;
}