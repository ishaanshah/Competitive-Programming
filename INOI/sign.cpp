#include <bits/stdc++.h>
using namespace std;



int main()
{
	std::vector<pair<int, int>> v;
	std::vector<int> v1;
	int n, m=0, minq, k, count = 0;
	cin>>n;


	for (int i=0; i<n; i++)
	{
		int a,b;
		
		cin>>a>>b;

		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());
	int p = 0, q = 0;
	int j = 0;
	int l = 0;
	int ans = 0;
	while(count!=n)
	{	
		for(p; p<n; p++)
		{
			if(v[p].first<=v[q].second)
			{
				m++;
			}
			
		}
		minq= v[q].second;
		k = q;
		for(j; j<m; j++)
		{
			
			if(minq>v[j].second)
			{
				minq = v[j].second;
				k= j;
				
			}
			
		}
		
		v1.push_back(v[k].second);
		
		for(l; l<m; l++)
		{
			if(v[l].first<=v[k].second)
			{
				count++;
				

			}
				
		}
		p =count;
		j = count;
		l = count;
		q = count;
		m = count;
		ans++;

	}
	cout<<ans<<endl;
	for(int z =0 ; z<ans; z++)
	{
		cout << v1[z] << " ";
	}
	

	

	return 0;
}
