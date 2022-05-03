#include<bits/stdc++.h> 

using namespace std; 

//DFS Implementation
void dfs(int node, vector<bool>& visited, map<int,vector<int>>& adj, int end)
{
    cout<<node<<" ";
    visited[node]=true;
    if(node==end)
    {
        return;
    }

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it, visited, adj, end);
        }
        if(visited[end]==true)
        {
            break;
        }
    }
} 

//BFS Implementation
void bfs(int node, vector<bool>& visited, map<int,vector<int>>& adj, int end)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        if(temp==end)
        {
            break;
        }

        for(auto it:adj[temp])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=true;
            }
        }
    }
}
 
int main()
{
    int n;
    cin>>n;

    map<int, vector<int>> adj;

    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int source_node, goal_node;
    cin>>source_node>>goal_node;

    vector<bool> visited1(n+1, false);
    vector<bool> visited2(n+1, false);

    cout<<"DFS: ";
    dfs(source_node, visited1, adj, goal_node);
    cout<<endl;
    cout<<"BFS: ";
    bfs(source_node, visited2, adj, goal_node); 
}