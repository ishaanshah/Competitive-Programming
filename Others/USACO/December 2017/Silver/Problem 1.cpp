/* Created by Ishaan Shah on 18/2/18.
 * Problem Name: My Cow Ate My Homework
 * Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=762
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min_arr[n];
    min_arr[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        min_arr[i] = min(min_arr[i+1], arr[i]);
    }

    int sum[n];
    sum[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        sum[i] = sum[i+1] + arr[i];
    }

    float mx = 0;
    for(int i = n-2; i >= 0; i--) {
        mx = max(float(sum[i] - min_arr[i])/(n-i-1), mx);
    }

    stack<int> ans;
    for(int i = n-2; i >= 0; i--) {
        if(mx == float(sum[i] - min_arr[i])/(n-i-1)) {
            ans.push(i);
        }
    }

    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
}