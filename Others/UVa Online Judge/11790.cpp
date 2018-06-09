/* Created by Ishaan Shah on 09-06-2018.
* Problem Name: Murcia's Skyline
* Problem Link: http://uva.onlinejudge.org/external/117/11790.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    int cn = 1;
    while (t--) {
    	int n;
    	scanf("%d", &n);
    	int h[n], w[n];
    	for (int i = 0; i < n; i += 1) {
 			scanf("%d", &h[i]);   		
    	}
    	for (int i = 0; i < n; i += 1) {
    		scanf("%d", &w[i]);
    	}
    	
		int len1[n], len2[n];
		int mxi = 0;
		int mxd = 0;
		int tmp_i, tmp_d;
    	for (int i = 0; i < n; i += 1) {
    		len1[i] = len2[i] = tmp_i = tmp_d = w[i];
    		for (int j = 0; j < i; j += 1) {
    			if (h[j] <  h[i]) {
					len1[i] = max(tmp_i+len1[j], len1[i]);
				}
    			
    			if (h[j] >  h[i]) {
					len2[i] = max(tmp_d+len2[j], len2[i]);
				}
    		}
			mxi = max(len1[i], mxi);
			mxd = max(len2[i], mxd);
    	}  	
     	
    	if (mxi >= mxd) { 
    		printf("Case %d. Increasing (%d). Decreasing (%d).\n", cn, mxi, mxd);
    	}
    	else {
    		printf("Case %d. Decreasing (%d). Increasing (%d).\n", cn, mxd, mxi);
    	}
		cn++;
    }
}
