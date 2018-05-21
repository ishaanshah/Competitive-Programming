/* Created by Ishaan Shah on 10-04-2018.
* Problem Name: HIGHWAYC
* Problem Link: https://www.codechef.com/APRIL18B/problems/HIGHWAYC
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
        int n;
        double s, y;
        cin >> n >> s >> y;
        double v[n], d[n], c[n], p[n], x[n];
        for(int  i = 0; i < n; i++) {
            cin >> v[i];
        }
        for(int  i = 0; i < n; i++) {
            cin >> d[i];
            if(!d[i]) {
                v[i] = -v[i];
            }
        } 
        for(int  i = 0; i < n; i++) {
            cin >> p[i];
        }
        for(int  i = 0; i < n; i++) {
            cin >> c[i];
            if(d[i]) {
                c[i] = -c[i];
            }
            x[i] = p[i] + c[i];
        }

        double time = 0.0;
        double ch_t = y/s;
        for(int i = 0; i < n; i++) {
            p[i] = p[i] + v[i]*time;
            x[i] = p[i] + c[i];
            double ca_t = -(p[i]/v[i]);
            if(ca_t < 0) {
                if((x[i] < 0 and p[i] > 0) || (x[i] > 0 and p[i] < 0)) {
                    time += fabs(x[i]/v[i]) + ch_t;
                } else {
                    time += ch_t;
                }         
            } else if (ch_t < ca_t) {
                time += ch_t; 
            } else {
                time += fabs(x[i]/v[i]) + ch_t; 
            }
        }
        cout << time << endl;
    }
}