/* Created by Ishaan Shah on 21-05-2018.
* Problem Name: Secret Recipe
* Problem Link: https://www.codechef.com/COOK94B/problems/CHEFRUN
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;   
    while(t--) {
        float x1, x2, x3, v1, v2;
        cin >> x1 >> x2 >> x3 >> v1 >> v2;
        if(fabs((x2-x3)/v2) > fabs((x3-x1)/v1)) {
            cout << "Chef" << endl;
        } else if (fabs((x2-x3)/v2) < fabs((x3-x1)/v1)) {
            cout << "Kefa" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
}