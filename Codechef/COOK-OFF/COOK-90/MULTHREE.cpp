/* Created by Ishaan Shah on 21/1/18
 * Problem Name: MULTHREE
 * Problem Link: https://www.codechef.com/COOK90/problems/MULTHREE
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t,k, d_1, d_0;
    cin >> t;
    while (t--) {
        cin >> k >> d_0 >> d_1;
        if(k==2) {
            if ((d_0 + d_1) % 3 == 0) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            int prefix[4];
            prefix[0] = d_0;
            prefix[1] = d_1;
            prefix[2] = (d_1 + d_0);
            prefix[2] %= 10;
            prefix[3] = d_0 + d_1 + prefix[2];
            prefix[3] %= 10;
            if(prefix[2] == 0 or prefix[3] == 0) {
                cout << "NO" << endl;
                continue;
            }
            long long blocks = (k-3)/4;
            long long sum = blocks*20;
            int remaining = (k-3) % 4;
            int array[4];
            switch(prefix[3]) {
                case 2:
                    array[0] = 2; array[1] = 4; array[2] = 8; array[3] = 6;
                    break;
                case 4:
                    array[0] = 4; array[1] = 8; array[2] = 6; array[3] = 2;
                    break;
                case 8:
                    array[0] = 8; array[1] = 6; array[2] = 2; array[3] = 4;
                    break;
                case 6:
                    array[0] = 6; array[1] = 2; array[2] = 4; array[3] = 8;
                    break;
            }
            for(int i = 0; i < remaining; i++) {
                sum += array[i];
            }
            if((sum+prefix[2]+d_0+d_1)%3 == 0) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
        cout << endl;
    }
}