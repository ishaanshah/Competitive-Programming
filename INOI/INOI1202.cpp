/* Created by Ishaan Shah on 16-12-2017.
 * Problem Name: INOI1202
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1202
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n+2];
    array[0] = 0;
    array[n+1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    for(int i = 1; i <= n; i++) {
        array[i] += i;
        array[i] = max(array[i-1], array[i]);
    }
    int count = 0;
    cout << array[n] << " ";
    for(int i = n; i > 1; i--) {
        array[i] -= n;
        array[i] = max(array[i+1], array[i]) + 1;
        count++;
        array[i-1] += count;
        cout << max(array[i-1], array[i]) << " ";
    }
}