/* Created by Ishaan Shah on 14-12-2017.
 * Problem Name: INOI1302
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1302
*/

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v;
    list<int> *adj;

public:
    explicit Graph(int v);
    void add_edge(int u, int v);
    int DFS(int start);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Graph::DFS(int start) {
    bool visited[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    int ans = 0;
    stack<int> stk;
    stk.push(start);
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();

        if(!visited[u]) {
            ans++;
            visited[u] = true;
        }

        for(auto &elem: adj[u]) {
            if(!visited[elem]) {
                stk.push(elem);
            }
        }
    }
    return ans;
}

int intersection(set<int> &id_1, set<int> &id_2);

int main() {
    int n, k;
    vector<set<int> > people;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        set<int> id;
        for(int j = 0; j < a; j++) {
            int b;
            cin >> b;
            id.insert(b);
        }
        people.push_back(id);
    }
    Graph relations(n);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int temp = intersection(people[i], people[j]);
            if(temp >= k) {
                relations.add_edge(i, j);
            }
        }
    }
    cout << relations.DFS(0);
}

int intersection(set<int> &id_1, set<int> &id_2) {
    int i = 0;
    int j = 0;
    int count = 0;
    vector<int> arr_1(id_1.begin(), id_1.end());
    vector<int> arr_2(id_2.begin(), id_2.end());
    while(i < arr_1.size() && j < arr_2.size()) {
        if(arr_1[i] < arr_2[j]) {
            i++;
        } else if(arr_1[i] > arr_2[j]) {
            j++;
        } else {
            count++;
            i++;
            j++;
        }
    }
    return count;
}