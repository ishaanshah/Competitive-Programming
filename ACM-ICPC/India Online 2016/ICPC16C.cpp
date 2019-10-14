/* Created by Rutvij Menavlikar on 27-09-2019.
* Problem Name: Watson and Digit Sums
* Problem Link: https://www.codechef.com/ACMIND16/problems/ICPC16C
*/

#include <bits/stdc++.h>

using namespace std;

int t,d;

int main() {
	cin >> t;
	for(int z=0;z<t;++z) {
		cin >> d;
		cout << (d % 9) + 1 << endl;
	}
	return 0;
}