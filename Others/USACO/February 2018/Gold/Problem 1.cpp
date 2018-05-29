/* Created by Ishaan Shah on 24-05-2018.
* Problem Name: Snow Boots
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=813
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    
    int n, b;
    cin >> n >> b;
    pair<int, int> arr[n-2];
    int temp;
    cin >> temp;
    for(int i = 1; i < n-1; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    cin >> temp;
    pair<pair<int, int>, int> boots[b];
    for(int i = 0; i < b; i++) {
        cin >> boots[i].first.first >> boots[i].first.second;
        boots[i].second = i;
    }
    sort(arr, arr+n-2, greater<pair<int, int> >());
    sort(boots, boots+b, greater<pair<pair<int, int>, int> >());
    set<int> indices;
    for(int i = 1; i < n-1; i++) {
        indices.insert(i);
    }
    int mx_dist = 1;
    int i = 0;
    int ans[b];
    for(pair<pair<int, int>, int> &boot: boots) {
        while(i < n-1 and indices.size() > 0) {
            if(arr[i].first <= boot.first.first) {
                break;
            }
            if(indices.size() > 1) {
                set<int>::iterator it = indices.find(arr[i].second);
                if(it == indices.begin()) {
                    mx_dist = max(mx_dist, *next(it));
                } else if (it == prev(indices.end())) {
                    mx_dist = max(mx_dist, n - *prev(it));
                } else {
                    mx_dist = max(mx_dist, *next(it) - *prev(it));
                }
                indices.erase(it);
                i++;
            } else {
                mx_dist = numeric_limits<int>::max();
                indices.empty();
            }
        }
        int res = 1;
        if(mx_dist > boot.first.second) {
            res = 0;
        }
        ans[boot.second] = res;
    }
    for(int i = 0; i < b; i++) {
        cout << ans[i] << endl;
    }
}