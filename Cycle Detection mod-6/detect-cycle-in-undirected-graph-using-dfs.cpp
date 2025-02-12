#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool cycle;
int parent[105];

void dfs(int src)
{
    vis[src] = true;
    for(auto child:adj_list[src]){
        if(!vis[child]){
            dfs(child);
            parent[child] = src; // we keep track parent this is main logic
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
            dfs(i);
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