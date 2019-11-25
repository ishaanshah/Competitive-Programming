/* Created by Ishaan Shah on 24-11-2019.
* Problem Name: Ilya and Queries
* Problem Link: https://codeforces.com/problemset/problem/313/B
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp[200005], arr[200005], n, k;

void merge(int l, int r) {
    int ptr1 = l, ptr2 = (l+r)/2+1, idx = l;
    while (ptr1 <= (l+r)/2 && ptr2 <= r) {
        if (arr[ptr1] < arr[ptr2]) {
            temp[idx] = arr[ptr1];
            ptr1++;
        } else {
            temp[idx] = arr[ptr2];
            ptr2++;
        }
        idx++;
    }
    for (; ptr1 <= (l+r)/2; ptr1++) {
        temp[idx] = arr[ptr1];
        idx++;
    }
    for (; ptr2 <= r; ptr2++) {
        temp[idx] = arr[ptr2];
        idx++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void sort(int l, int r) {
    if (l == r)
        return;
    sort(l, (l+r)/2);
    sort((l+r)/2+1, r);
    merge(l, r);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(0, n-1);
    
    if (k == 0) {
        if (arr[0] == 1)
            printf("-1\n");
        else
            printf("1\n");
        return 0;
    }
    if (k == n)
        printf("%d", arr[n-1]);
    else if (arr[k-1] == arr[k])
        printf("-1");
    else
        printf("%d", arr[k-1]);

    return 0;
}