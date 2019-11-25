/* Created by Ishaan Shah on 24-11-2019.
* Problem Name: Less or Equal
* Problem Link: https://codeforces.com/problemset/problem/977/C
*/

#include <stdio.h>
#include <string.h>

typedef long long ll;

int main() {
    char s[200005];
    scanf("%s", s);
    ll arr[200005];
    int len = strlen(s);    
    if (s[0] == s[1])
        arr[0] = 1;
    else
        arr[0] = 0;
    for (int i = 1; i < len-1; i++) {
        if (s[i] == s[i+1])
            arr[i] = arr[i-1]+1;
        else
            arr[i] = arr[i-1];
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        if (l == 0)
            printf("%lld\n", arr[r-1]);
        else
            printf("%lld\n", arr[r-1]-arr[l-1]);
    }
}