/* Created by Ishaan Shah on 05-01-2018.
 * Problem Name: KCON
 * Problem Link: https://www.codechef.com/JAN18/problems/KCON
*/

#include <bits/stdc++.h>

using namespace std;

long long kadane(int start, int end, long long array[]) {
    long long curr_max = array[start];
    long long max_so_far = array[start];
    for(int i = start + 1; i < end; i++) {
        curr_max = max(array[i], curr_max + array[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main() {
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        long long array[2*n];
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> array[i];
            sum += array[i];
            array[n+i] = array[i];
        }
        long long min_prefix = array[0];
        long long min_suffix = array[n-1];
        long long prefix = array[0];
        long long suffix = array[n-1];
        for(int i = 1; i < n; i++) {
            prefix += array[i];
            suffix += array[(n-1) - i];
            min_prefix = min(min_prefix, prefix);
            min_suffix = min(min_suffix, suffix);
        }
        long long ans;
        if(k == 1) {
            ans = kadane(0, n, array);
        } else {
            ans = kadane(0, 2*n, array);
            if(sum > 0) {
                long long temp = k*sum;
                if(min_prefix < 0) {
                    temp -= min_prefix;
                }
                if(min_suffix < 0) {
                    temp -=  min_suffix;
                }
                ans = max(ans, temp);
            }
        }
        cout << ans << endl;
    }
}
