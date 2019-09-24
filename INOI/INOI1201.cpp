/* Created by Ishaan Shah on 30-11-2017.
 * Problem Name: INOI1201
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1201
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<pair<int, int> > contestants;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        contestants.emplace_back(make_pair(a, b + c));
    }

    sort(contestants.begin(), contestants.end(), [](pair<int, int> &x, pair<int, int> &y){return x.second > y.second;});

    int sum = 0;
    int ans = 0;
    for(const auto &contestant: contestants)
    {
        int time_taken = contestant.second + contestant.first;
        time_taken += sum;
        sum += contestant.first;
        ans = max(ans, time_taken);
    }
    cout << ans;
}