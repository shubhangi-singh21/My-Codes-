//To find strongly connected components (there is a path between all pairs of vertices) in a graph

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,stack<int>&st,vector<int>&vis,vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,st,vis,adj);
        }
    }
    st.push(node);
}

void revDFS(int node,vector<int>&vis,vector<int>transpose[])
{
    cout<<node<<"  ";
    vis[node]=1;
    for(auto it: transpose[node])
    {
        if(!vis[it])
        revDFS(it,vis,transpose);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int>st;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,st,vis,adj);
    }
    vector<int>transpose[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node] == 0)
        {
          revDFS( node, vis, transpose);
          cout << endl;
        }
      return 0;
    }
