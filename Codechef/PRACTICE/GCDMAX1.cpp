/* Created by Ishaan Shah on 03-01-2018.
 * Problem Name: GCDMAX1
 * Problem Link: https://www.codechef.com/problems/GCDMAX1
*/

#include<bits/stdc++.h>

using namespace std;

int n, k;
int *arr;

int midpoint_cross(int mid, int hi, int lo) {
    int suffix_gcd;
    int prefix_gcd;
    int left = 0;
    int right = 0;
    suffix_gcd = arr[mid];
    prefix_gcd = arr[mid+1];
    if(arr[mid] >= k) {
        left = 1;
    }
    if(arr[mid+1] >= k) {
        right = 1;
    }
    for(int i = mid-1; i >= lo; i--) {
        suffix_gcd = __gcd(suffix_gcd, arr[i]);
        if(suffix_gcd < k) {
            break;
        }
        left++;
    }
    for(int i = mid+2; i <= hi; i++) {
        prefix_gcd = __gcd(prefix_gcd, arr[i]);
        if(prefix_gcd < k) {
            break;
        }
        right++;
    }
    return left + right;
}

int dnc(int lo, int hi) {
    if(hi == lo) {
        if(arr[hi] >= k) {
            return 1;
        } else {
            return 0;
        }
    }

    int mid = (lo + hi)/2;
    int left = dnc(lo, mid);
    int right = dnc(mid+1, hi);
    int middle = midpoint_cross(mid, hi, lo);
    return max(middle, max(left, right));
}

int main() {
    cin >> n >> k;
    arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << dnc(0, n-1);
}
