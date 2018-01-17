/* Created by Ishaan Shah on 24-12-2017.
 * Problem Name: BTAR
 * Problem Link: https://www.codechef.com/COOK89/problems/BTAR
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int class_1 = 0;
        int class_2 = 0;
        int class_3 = 0;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if(a%4 == 2) {
                class_1++;
            } else if(a%4 == 1) {
                class_2++;
            } else if(a%4 == 3) {
                class_3++;
            }
        }
        int temp;
        if(class_2 == class_3) {
            if(class_1%2 == 0) {
                cout << class_1/2 + class_2;
            } else {
                cout << -1;
            }
        } else if(class_2 > class_3) {
            temp = class_2 - class_3;
            if(temp%2 == 0 and (class_1-temp/2)%2 == 0) {
                cout << class_3 + (class_1-temp/2)/2 + temp;
            }
            else {
                cout << -1;
            }
        } else if(class_3 > class_2) {
            temp = class_3 - class_2;
            if (temp % 2 == 0 and (class_1 - temp/2) % 2 == 0) {
                cout << class_2 + (class_1 - temp/2)/2 + temp;
            } else {
                cout << -1;
            }
        }
        cout << endl;
    }
}