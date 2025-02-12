#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool vis[105];
bool cycle;
bool pathvis[105];

void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for(auto child:adj_list[src]){
        if(vis[child] && pathvis[child]){
            cycle = true;
        }
        if(!vis[child]){
            dfs(child);
        }
    }
    pathvis[src] = false;
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
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));
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