/* Created by Ishaan Shah on 15-12-2017.
 * Problem Name: INOI1301
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1301
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    int array[n];
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        array[i] = a;
    }
    int sum_1[n];
    int sum_2[n];
    sum_1[0] = array[0];
    sum_1[1] = array[1] + array[0];
    sum_2[s-1] = 0;
    sum_2[s] = array[s];
    for(int i = 2; i < n; i++) {
        sum_1[i] = max(sum_1[i-1],sum_1[i-2]) + array[i];
    }
    for(int i = s + 1; i < n; i++) {
        sum_2[i] = max(sum_2[i-1],sum_2[i-2]) + array[i];
    }
    int ans = numeric_limits<int>::min();
    for(int i = s-1; i < n; i++) {
        ans =  max(ans, sum_1[i] + sum_2[i] - array[i]);
    }
    cout << ans;
}

