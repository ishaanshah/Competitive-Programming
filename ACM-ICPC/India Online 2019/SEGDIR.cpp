/* Created by Rutvij Menavlikar on 18-10-2019.
* Problem Name: Moving Segments
* Problem Link: https://www.codechef.com/ICPCIN19/problems/SEGDIR
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = (1e3) + 5;

int t,n;
pair< pair<int,int>, int> p[max_n];
pair<int,int> pr;
vector<pair<int,int> > v;
bool flag = true;
int cntr = 0,k;

int main()
{
	cin >> t;
	for(int z=0;z<t;++z)
	{
		flag = true;
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> p[i].first.first >> p[i].first.second >> p[i].second;
		sort(p,p+n);
		for(int i=0;i<(n-1);++i)
		{
			cntr = 0;
			v.clear();
			for(int j=i+1;j<n;++j)
			{
				if(p[j].first.first <= p[i].first.second and p[i].second == p[j].second)
				{
					pr.first = p[j].first.first;
					pr.second = p[j].first.second;
					v.push_back(pr);
					++cntr;
				}
			}
			sort(v.begin(),v.end());
			for(int j=0;j<(cntr-1);++j)
			{
				if(v[j+1].first <= v[j].second)
					flag = false;
			}
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}