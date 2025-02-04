#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;cin>>n>>e;
    int adj_matrix[n][n];
    memset(adj_matrix,0,sizeof(adj_matrix));
    //corner er value logically 1 hoi
    for(int i =0; i<n;i++)
        for(int j =0; j<n;j++)
            if(i==j)
                adj_matrix[i][j] = 1;


    //take matrix input
    for(int i =0; i<e;i++){
        int a,b;
        cin>>a>>b;
        adj_matrix[a][b] = 1;
    }
    
    //print matrxi
    for(int i = 0; i<n; i++){
        for(int j =0; j<n;j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}