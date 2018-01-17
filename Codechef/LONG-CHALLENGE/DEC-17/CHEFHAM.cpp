/* Created by Ishaan Shah on 04-12-2017.
 * Problem Name: CHEFHAM
 * Problem Link: https://www.codechef.com/DEC17/problems/CHEFHAM
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        vector<int> input;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            input.push_back(a);
        }
        if(n==2)
        {
            if(input[0] == input[1])
            {
                cout << 0 << endl;
                cout << input[1] << " " << input[0] << endl;
            } else
            {
                cout << 2 << endl;
                cout << input[1] << " " << input[0] << endl;
            }
        }
        else
        {
            vector<int> copy(input);
            sort(input.begin(), input.end());
            map<int, vector<int> > output;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                int temp = input[(i + 2) % n];
                if (temp == input[i]) {
                    count++;
                }
                output[input[i]].push_back(input[(i + 2) % n]);
            }
            cout << n - count << endl;
            for (int i = 0; i < n; i++) {
                cout << output[copy[i]].back() << " ";
                output[copy[i]].pop_back();
            }
            cout << endl;
        }
    }
}