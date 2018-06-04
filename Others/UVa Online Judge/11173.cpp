/* Created by Ishaan Shah on 03-06-2018.
* Problem Name: Grey Codes
* Problem Link: https://uva.onlinejudge.org/external/111/11173.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    cin >> n;
    for (unsigned int i = 0; i < n; i += 1) {
    	int k, temp;
    	cin >> temp >> k;
    	cout << (k^(k>>1)) << endl;
    }
}
