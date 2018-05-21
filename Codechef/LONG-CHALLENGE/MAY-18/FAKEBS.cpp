/* Created by Ishaan Shah on 08-05-2018.
* Problem Name: Fake Binary Search
* Problem Link: https://www.codechef.com/MAY18B/problems/FAKEBS
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
        int n, q;
        cin >> n >> q;
        int arr[n+1];
        vector<int> sarr;
        map<int, int> mp; 
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            sarr.push_back(arr[i]);
            mp[arr[i]] = i;
        }
        sort(sarr.begin(), sarr.end());
        int x[q];
        for(int i = 0; i < q; i++) {
            cin >> x[i]; 
        }
        
        for(int i = 0; i < q; i++) {
            int low, high, mid, pos, ans;
            int idx = lower_bound(sarr.begin(), sarr.end(), x[i]) - sarr.begin();
            int avblh = n-1-idx;
            int avlbl = idx;
            low = 1;
            high = n;
            pos = mp[x[i]];
            ans = 0;
            int tsh = 0; int tsl = 0;
            while (low <= high) {
                mid = (low + high) / 2;
                if (mid == pos) {
                    break;
                } else if (mid < pos) {
                    low = mid+1;
                    if(arr[mid] > x[i]) {
                        tsh++;
                        avblh--;
                    } else {
                        avlbl--;
                    }
                } else {
                    high = mid-1;
                    if(arr[mid] < x[i]) {
                        tsl++;
                        avlbl--;
                    } else {
                        avblh--;
                    }
                }
            }

            if(tsh > tsl) {
                ans += tsl;
                int diff = tsh - tsl;
                if(diff <= avlbl) {
                    ans += diff;
                } else {
                    ans = -1;
                }
            } else if(tsl > tsh) {
                ans += tsh;
                int diff = tsl - tsh;
                if(diff <= avblh) {
                    ans += diff;
                } else {
                    ans = -1;
                }
            } else {
                ans += tsl;
            }
            cout << ans << endl;
        }
    }
}