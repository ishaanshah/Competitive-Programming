#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> height;
    int n;

    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        height.push_back(a);
    }

    sort(height.begin(), height.end());
    int ans = 2;
    for(int i = 0; i < height.size(); i++)
    {
        for(int j = i + 1; j < height.size(); j++) {
            int count = 2;
            int diff = height[j] - height[i];
            int temp = height[j] + diff;
            while (binary_search(height.begin(), height.end(), temp))
            {
                temp += diff;
                count += 1;
            }
            ans = max(ans, count);
        }
    }
    cout << ans;
}
