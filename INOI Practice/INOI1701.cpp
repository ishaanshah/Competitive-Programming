/* Created by Ishaan Shah on 26-12-2017.
 * Problem Name: INOI1701
 * Problem Link: https://www.iarcs.org.in/inoi/2017/inoi2017/inoi2017-qpaper.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int r, c, n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
bool *is_visited;
map<pair<int, int>, bool> is_cultivated;
map<pair<int, int>, int> cell_id;
list<int> *adj;

inline bool within_grid(int x, int y) {
    return (1 <= x && x <= r and 1 <= y && y <= c);
}

int dfs(int start) {
    is_visited[start] = true;
    int result = 4 - ((int)adj[start].size());
    for(auto vertex: adj[start]) {
        if(!is_visited[vertex]) {
            result += dfs(vertex);
        }
    }
    return result;
}

int main() {
    cin >> r >> c >> n;
    is_visited = new bool[r*c];
    adj = new list<int>[r*c];
    int k = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            is_cultivated[{i,j}] = false;
            is_visited[k] = false;
            cell_id[{i,j}] = k;
            k++;
        }
    }

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        is_cultivated[{a, b}] = true;
    }

    for(auto elem: is_cultivated) {
        int x = elem.first.first;
        int y = elem.first.second;
        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = x + dy[i];
            if(within_grid(new_x, new_y) and is_cultivated.count({new_x, new_y})) {
                adj[cell_id[{x, y}]].push_back(cell_id[{new_x, new_y}]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < r*c; i++) {
        if (!is_visited[i]) {
            ans = max(ans, dfs(i));
        }
    }
    cout << ans << endl;
}