#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>a;
vector<vector<int>>b;
vector<vector<vector<int>>> ans;
map<vector<vector<int>>, int> visi;
map<vector<vector<int>>, vector<vector<int>>> c;
vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool isvalid(int x, int y, int n, int m) 
{
    if(x >= 0 && y >= 0 && x < n && y < m) 
    {
        return true;
    }
    return false;
}

void bfs() 
{
    queue<vector<vector<int>>>q;
    q.push(a);
    while(!q.empty()) 
    {
        vector<vector<int>> cur = q.front();
        q.pop();
        visi[cur] = 1;
        if(cur == b) break;
        for(int i=0; i<cur.size(); i++) 
        {
            for(int j=0; j<cur[0].size(); j++) 
            {
                if(cur[i][j] == 0) 
                {
                    for(int k=0; k<4; k++) 
                    {
                        int idx1 = i + dir[k][0];
                        int idx2 = j + dir[k][1];
                        if(isvalid(idx1, idx2, cur.size(), cur[0].size())) 
                        {
                            vector<vector<int>> parent = cur;
                            swap(cur[idx1][idx2], cur[i][j]);
                            if(visi[cur] == 0) 
                            {
                                q.push(cur);
                                c[cur] = parent;
                            }
                            swap(cur[idx1][idx2], cur[i][j]);
                        }
                    }
                }
            }
        }
    }

    while(b!=a) 
    {
        ans.push_back(b);
        b = c[b];
    }
    ans.push_back(a);
    reverse(ans.begin(), ans.end());
    
    for(auto it: ans) 
    {
        for(int i=0; i<it.size(); i++) 
        {
            for(int j=0; j<it[0].size(); j++) 
            {
                cout<<it[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

}

bool dfs(vector<vector<int>> cur) 
{
    if(cur == b) 
    {
        if(ans.size() != 0) 
        {
            return false;
        }
        ans.push_back(cur);
        return true;
    }
    if(ans.size() > 0) return false;
    if(visi[cur]) return false;
    visi[cur] = 1;
    bool res = false;
    for(int i=0; i<cur.size(); i++) 
    {
        for(int j=0; j<cur[0].size(); j++) 
        {
            if(cur[i][j] == 0) 
            {
                for(int k=0; k<4; k++) 
                {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if(isvalid(x, y, cur.size(), cur[0].size())) 
                        {
                            swap(cur[x][y], cur[i][j]);
                            if(visi[cur] == 0) 
                            {
                                res |= dfs(cur);
                            }
                            swap(cur[x][y], cur[i][j]);
                        }
                }
            }
        }
    }
    if(res) 
    {
        ans.push_back(cur);
    }
    return res;
}

int main()
{
    int n,m;
    cout<<"Enter size of state:"<<endl;
    cin>>n>>m;
    a.resize(n, vector<int>(m));
    b.resize(n, vector<int>(m));
    cout<<"Enter initial state:"<<endl;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter goal state:"<<endl;
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            cin>>b[i][j];
        }
    }
    string s;
    cout<<"Enter DFS or BFS"<<endl;
    cin>>s;
    
    if(s=="DFS")
    {
        dfs(a);
        reverse(ans.begin(), ans.end());
        
        for(auto it: ans) 
        {
            for(int i=0; i<it.size(); i++) 
            {
                for(int j=0; j<it[0].size(); j++) 
                {
                    cout<<it[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    else
    {
        bfs();
    }
    
    return 0;
}