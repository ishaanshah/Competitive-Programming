/* Created by Ishaan Shah on 05-11-2018.
* Problem Name: Save Spaceman Spiff
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO13004
*/

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int n, m, k;
pair<int, int> blast[2505];
int start[2505], freq[2505];
bool safe[2505][2505];
int grid[2505][2505];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i += 1) {
		scanf("%d %d %d %d", &blast[i].x, &blast[i].y, &start[i], &freq[i]);
	}
	memset(safe, true, sizeof safe);
	for (int i = 0; i < k; i++) {
		blast[i].x -= 1; blast[i].y -= 1;
		safe[blast[i].x][blast[i].y] = false;
		int a = blast[i].x, b = blast[i].y; 
		while (a > 0) {
			a--;
			int time = a+b;
			int dist = abs(a-blast[i].x);
			if (time >= start[i] && (time-start[i]-dist)%freq[i] == 0) 
				safe[a][b] = false;
		}
		a = blast[i].x, b = blast[i].y; 
		while (a < n-1) {
			a++;
			int time = a+b;
			int dist = abs(a-blast[i].x);
			if (time >= start[i] && (time-start[i]-dist)%freq[i] == 0) 
				safe[a][b] = false;
		}
		a = blast[i].x, b = blast[i].y; 
		while (b > 0) {
			b--;
			int time = a+b;
			int dist = abs(b-blast[i].y);
			if (time >= start[i] && (time-start[i]-dist)%freq[i] == 0) 
				safe[a][b] = false;
		}
		a = blast[i].x, b = blast[i].y; 
		while (b < m-1) {
			b++;
			int time = a+b;
			int dist = abs(b-blast[i].y);
			if (time >= start[i] && (time-start[i]-dist)%freq[i] == 0) 
				safe[a][b] = false;
		}
	}
	
   	for(int i = n-1; i >= 0; i--) {
       	for(int j = m-1; j >= 0; j--) {	
            grid[i][j] = -1;
            if (safe[i][j] and i == n-1 and j == m-1) grid[i][j] = 1; 
            else if (i == n-1 and safe[i][j] and grid[i][j+1] == 1) 
            	grid[i][j] = 1;
            else if(j == m-1 and safe[i][j] and grid[i+1][j] == 1) 
            	grid[i][j] = 1;
            else if(safe[i][j] and (grid[i+1][j] == 1 or grid[i][j+1] == 1))
            	grid[i][j] = 1;                    
        }
    }
    
	if(grid[0][0] > 0) {
		printf("YES\n%d", n+m-2);
	} else {
		printf("NO");
	}
}
