/* Created by Ishaan Shah on 24-11-2019.
* Problem Name: BerSU Ball
* Problem Link: https://codeforces.com/problemset/problem/489/B
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int vis[105];
int b[105], g[105];
    
int comp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    memset(vis, 0, sizeof(vis));
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &g[i]);
    }
    qsort((void *)b, n, sizeof(int), comp);
    qsort((void *)g, m, sizeof(int), comp);

    int ans = 0;
    if (n < m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (abs(b[i]-g[j]) < 2 && !vis[j]) {
                    vis[j] = 1;
                    ans++;
                    break;
                }            
            }
        }
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(b[j]-g[i]) < 2 && !vis[j]) {
                    vis[j] = 1;
                    ans++;
                    break;
                }            
            }
        }
    }
    printf("%d", ans);
}