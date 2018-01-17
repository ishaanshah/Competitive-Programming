/*
 * Created by Ishaan Shah on 26-11-2017.
 * Problem Name: CLRL
 * Problem Link: https://www.codechef.com/problems/CLRL
 */


#include <iostream>
#include <vector>
#include <limits>


using namespace std;


int main()
{

    int t, n, rating;
    cin >> t;
    while(t--)
    {
        cin >> n >> rating;
        vector<int> seq;

        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            seq.push_back(a);
        }

        pair<int, int> range;

        range.first = -numeric_limits<int>::max();
        range.second = numeric_limits<int>::max();

        bool broken = false;

        for(int i = 0; i < n; i++)
        {
            if(seq[i] < range.first || seq[i] > range.second)
            {
                cout << "NO" << endl;
                broken = true;
                break;
            }

            if(seq[i] > rating)
            {
                range.second = seq[i];
            }
            else if(seq[i] < rating)
            {
                range.first = seq[i];
            }
        }

        if(!broken)
        {
            cout << "YES" << endl;
        }
    }
}