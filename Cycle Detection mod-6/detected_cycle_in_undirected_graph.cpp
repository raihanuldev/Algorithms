#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool cycle;
int parent[105];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : adj_list[par])
        {
            if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, edge;
    cin >> n >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // multiple push for undirected ghrpah
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for (int i = 0; i < n; i++)
    {

        if (!adj_list[i].empty() && !vis[i])
            bfs(i);
    }
    if (cycle)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "NO CYCLE";
    }
    return 0;
}