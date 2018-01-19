/* Created by Ishaan Shah on 28-11-2017.
 * Problem Name: CHEFGP
 * Problem Link: https://www.codechef.com/OCT17/problems/CHEFGP
*/


#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, x, y, len, i, count_a, count_b;
    cin >> t;
    string str;
    while (t--) {
        count_a = 0;
        count_b = 0;
        cin >> str;
        cin >> x >> y;
        len = int(str.length());
        for (i = 0; i < len; i++) {
            if (str[i] == 'a')
                count_a++;
            else if (str[i] == 'b')
                count_b++;
        }

        if (count_a > count_b) {
            while (count_a > count_b) {
                for (i = 0; i < x; i++) {
                    cout << "a";
                    count_a--;
                    if (count_a == count_b)
                        break;
                }
                if (count_a == count_b)
                    break;
                else if (count_b == 0 && count_a != 0)
                    cout << "*";
                else if (count_b != 0) {
                    cout << "b";
                    count_b--;
                }
            }
            while (count_a != 0) {
                cout << "ba";
                count_a--;
            }
        } else if (count_b > count_a) {

            while (count_b > count_a) {
                for (i = 0; i < y; i++) {
                    cout << "b";
                    count_b--;
                    if (count_a == count_b)
                        break;
                }
                if (count_a == count_b)
                    break;
                if (count_a == 0 && count_b != 0) {
                    cout << "*";
                } else if (count_a != 0) {
                    cout << "a";
                    count_a--;
                }
            }
            while (count_b != 0) {
                cout << "ab";
                count_b--;
            }
        } else if (count_b == count_a) {
            for (i = 0; i < count_a; i++)
                cout << "ab";
        }
        cout << "\n";
    }
}