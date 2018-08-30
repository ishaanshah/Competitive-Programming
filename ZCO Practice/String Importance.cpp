/* Created by Ishaan Shah on 27-08-2018.
* Problem Name: String Importance
* Problem Link: https://www.iarcs.org.in/inoi/2018/zco2018/zco2018-question-paper.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
string arr[100005];
int px[3][100005], pz[3][100005];
int wnd = 0;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i += 1) cin >> arr[i];
		if (arr[0] == "X") {
			px[0][0] = 1;
			pz[0][0] = 0;
		} else if (arr[0] == "Z") {
			px[0][0] = 0;
			pz[0][0] = 1;
		}
		px[1][0] = 0, pz[1][0] = 0;
		px[2][0] = 0, pz[2][0] = 0;
		for (int i = 1; i < n; i += 1) {
			if (arr[i] == "Z") {
				pz[i%3][i] = pz[i%3][i-1]+1;
				px[i%3][i] = px[i%3][i-1];
			}
			else if (arr[i] == "X") {
				px[i%3][i] = px[i%3][i-1]+1;
				pz[i%3][i] = pz[i%3][i-1];
			}
			for (int j = 1; j <= 2; j++) {
				pz[(i+j)%3][i] = pz[(i+j)%3][i-1];
				px[(i+j)%3][i] = px[(i+j)%3][i-1];
			}
		}
		
		int ans, t;
		wnd = 0;
		for (int i = 0; i < k; i++) {
			t = (i+2)%3;
			if (arr[i] == "X") wnd += pz[t][n-1] - pz[t][i];
		} 
		ans = wnd;
		for (int i = 1; i < n-k; i++) {
			t = (i+1)%3;
			if (arr[i-1] == "X") wnd -= pz[t][n-1] - pz[t][i-1+k-1];
			else if (arr[i-1] == "Z")
				if (i > 1) wnd -= px[t][i-2];
			
			t = (i+k+1)%3;
			if (arr[i+k-1] == "X") wnd += pz[t][n-1] - pz[t][i+k-1];
			else if (arr[i+k-1] == "Z") wnd += px[t][i-1];
			
			ans = min(wnd, ans);
		}
		printf("%d\n", ans);
	}
}
