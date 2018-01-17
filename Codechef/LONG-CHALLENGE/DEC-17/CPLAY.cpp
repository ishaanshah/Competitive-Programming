/* Created by Ishaan Shah on 02-12-2017.
 * Problem Name: CPLAY
 * Problem Link: https://www.codechef.com/DEC17/problems/CPLAY
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;

    while (cin >> input) {
        bool result = false;
        int a = 0;
        int b = 0;
        int a_shots = 5;
        int b_shots = 5;
        for (int i = 0; i < 10; i++) {
            if (input[i] == '1') {
                if (i % 2 == 0) {
                    a++;
                } else {
                    b++;
                }
            }

            if (i % 2 == 0) {
                a_shots--;
            } else {
                b_shots--;
            }

            if (b + b_shots < a) {
                cout << "TEAM-A " << i + 1 << endl;
                result = true;
                break;
            } else if (a + a_shots < b) {
                cout << "TEAM-B " << i + 1 << endl;
                result = true;
                break;
            }
        }

        if (a == b && !result) {
            int i = 10;
            while (i < 20 && !result) {
                if (input[i] == '1' && input[i + 1] == '0') {
                    cout << "TEAM-A " << i + 2 << endl;
                    result = true;
                } else if (input[i] == '0' && input[i + 1] == '1') {
                    cout << "TEAM-B " << i + 2 << endl;
                    result = true;
                }

                i += 2;
            }
        }


        if (!result) {
            cout << "TIE" << endl;
        }

    }
}