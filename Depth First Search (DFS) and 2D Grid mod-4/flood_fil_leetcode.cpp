#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
bool vis[105][105];
vector<pair<int,int>>d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool isVaild(int i,int j)
{
    if(i<0 || i>=n || j<0|| j>=m)
        return false;
    return true;
}
void dfs(int si,int sj)
{
    // cout<<si<<" "<<sj<<endl;
    // cout<<grid[si][sj]<<endl;
    grid[si][sj] = 2;
    vis[si][sj] = true;
    for(int i =0; i<4; i++)
    {
        int ci =si+ d[i].first;
        int cj = sj+ d[i].second;
        if(isVaild(ci,cj) && !vis[ci][cj] && grid[ci][cj]==1)
            dfs(ci,cj);
    }
}

int main()
{
    cin>>n>>m;
    
    for(int i = 0; i<n;i++)
        for(int j =0; j<m; j++)
            cin>>grid[i][j];
    
    int si,sj;
    cin>>si>>sj;
    dfs(si,sj);
    cout<<"Result must be Come ="<<grid[1][1]<<endl;
    cout<<"Result must be Come =  "<<grid[0][0]<<endl;
    cout<<"Result must be Come =  "<<grid[0][1]<<endl;
    return 0;
}