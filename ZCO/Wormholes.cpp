#include <bits/stdc++.h>

using namespace std;

int time_taken(vector<pair<int, int> >& contests, vector<int>& start, vector<int>& end);

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int> > contests;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        contests.emplace_back(make_pair(a, b));
    }

    vector<int> start, end;
    while(x--)
    {
        int input;
        cin >> input;
        start.push_back(input);
    }

    while(y--)
    {
        int input;
        cin >> input;
        end.push_back(input);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    cout << time_taken(contests, start, end);
}


int time_taken(vector<pair<int, int> >& contests, vector<int>& start, vector<int>& end)
{
    int time = numeric_limits<int>:: max();
    for(auto contest: contests)
    {
        long lower = upper_bound(start.begin(), start.end(), contest.first) - start.begin() - 1;
        long higher = lower_bound(end.begin(), end.end(), contest.second) - end.begin();

        if(lower >= 0 && higher < end.size())
        {
            time = min(time, end[higher] - start[lower] + 1);
        }
    }
    return time;
}
