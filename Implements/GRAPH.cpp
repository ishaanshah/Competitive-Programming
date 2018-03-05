/* Created by Ishaan Shah on 09-12-2017.
 * Representation of a graph and implementation of DFS & BFS
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    //Number of vertices
    int v;

    //pointer to adjacency list
    list <int> *adj;
    public:
    // Constructor
    Graph(int v);

    // Functions on graphs
    void add_edge(int v, int w);
    vector<int> BFS(int start);
    vector<int> DFS(int start);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

vector<int> Graph::BFS(int start)
{
    bool visited[v];
    vector<int> result;
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(!visited[u])
        {
            result.push_back(u);
            visited[u] = true;
        }

        for(auto &elem: adj[u])
        {
            if(!visited[elem])
            {
                q.push(elem);
            }
        }
    }
    return result;
}

vector<int> Graph::DFS(int start)
{
    bool visited[v];
    vector<int> result;
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    stack<int> stack;
    stack.push(start);
    while(!stack.empty())
    {
        int u = stack.top();
        stack.pop();

        if(!visited[u])
        {
            result.push_back(u);
            visited[u] = true;
        }

        for(auto &elem: adj[u])
        {
            if(!visited[elem])
            {
                stack.push(elem);
            }
        }
    }
    return result;
}