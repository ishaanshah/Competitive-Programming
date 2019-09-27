/* Created by Ishaan Shah on 26-09-2019.
* Problem Name: Obtain Desired Standard Deviation
* Problem Link: https://www.codechef.com/ACMIND17/problems/STDDEV
*/

#include <bits/stdc++.h>

using namespace std;

int t,n;
double s,x;

int main() {
	cin >> t;
	for(int z=0;z<t;++z) {
		cin >> n >> s;
		if(n == 1) {
			if(s == 0)
				cout << "0\n";
			else
				cout << "-1\n";
		}
		else {
			x = (s * n) / sqrt(n-1);
			for(int i=0;i<(n-1);++i)
				cout << "0 ";
			printf("%0.4lf\n",x);
		}
	}
	return 0;
}
