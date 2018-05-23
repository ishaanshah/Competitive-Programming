/* Created by Ishaan Shah on 23-05-2018.
* Problem Name: Lifeguards
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=786
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    
    int n;
    cin >> n;
    pair<int, int> l[2*n];
    int aln[n];
    for(int i = 0; i < n; i++) {
        cin >> l[2*i].first >> l[2*i+1].first;
        l[2*i].second = i;
        l[2*i+1].second = i; 
        aln[i] = 0;
    }

    set<int> tracker;
    sort(l, l+2*n);
    int last = 0;
    int total = 0;
    for(pair<int, int>& s: l) {
        if(tracker.size() == 1) {
            aln[(*tracker.begin())] += s.first - last;
        }
        if(!tracker.empty()) {
            total += s.first - last;
        }
        if(tracker.find(s.second) != tracker.end()) {
            tracker.erase(s.second);
        } else {
            tracker.insert(s.second);
        }
        last = s.first;
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret = max(ret, total - aln[i]);
    }
    cout << ret;
}