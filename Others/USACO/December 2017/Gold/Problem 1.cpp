/* Created by Ishaan Shah on 17-04-2018.
* Problem Name: A Pie for a Pie
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=765
*/

#include <bits/stdc++.h>

using namespace std;

int A[2*100005], B[2*100005];
int dist[2*100005];

struct cmpA {
    bool operator()(int a, int b) const {
        return B[a] < B[b];
    }
};

struct cmpB {
    bool operator()(int a, int b) const {
        return A[a] < A[b];
    }
};

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    int n, d;
    cin >> n >> d;

    queue<int> q;
    multiset<int, cmpA> sA;
    multiset<int, cmpB> sB;

    for(int i = 0; i < 2*n; i++) {
        cin >> A[i] >> B[i];
        A[i] = -A[i]; B[i] = -B[i];
        dist[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        if(B[i] == 0) {
            q.push(i);
            dist[i] = 1;
        } else {
            sA.insert(i);
        }

        if(A[n+i] == 0) {
            q.push(n+i);
            dist[n+i] = 1;
        } else {
            sB.insert(n+i);
        }
    }
    multiset<int, cmpA>::iterator itA;
    multiset<int, cmpB>::iterator itB;

    while(!q.empty()) {
        int i = q.front();
        if(i < n) {
            while(true) {
                itB = sB.lower_bound(i);
                if(itB == sB.end() || A[i] + d < A[*itB]) {
                    break;
                }
                q.push(*itB);
                dist[*itB] = dist[i] + 1;
                sB.erase(itB);
            }
        } else {
            while(true) {
                itA = sA.lower_bound(i);
                if(itA == sA.end() || B[i] + d < B[*itA]) {
                    break;
                }
                q.push(*itA);
                dist[*itA] = dist[i] + 1;
                sA.erase(itA);
            }
        }
        q.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }
}