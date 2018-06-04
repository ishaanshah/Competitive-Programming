/* Created by Ishaan Shah on 03-06-2018.
* Problem Name: The jackpot
* Problem Link: https://uva.onlinejudge.org/external/106/10684.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int n;
    while(scanf("%d", &n) && n != 0) {
    	vector<int> a;
    	while(n--) {
    		int temp;
    		scanf("%d", &temp);
    		a.push_back(temp);
    	}
 		
 		int ans = 0, cur = 0;
 		for (int i = 0; i < a.size(); i += 1) {
 			cur += a[i];
 			ans = max(cur, ans);
 			if(cur < 0) cur = 0;
 		}
 		if (ans > 0) {
 			printf("The maximum winning streak is %d.\n", ans);
 		} else {
 			printf("Losing streak.\n");
 		}
    }
}
