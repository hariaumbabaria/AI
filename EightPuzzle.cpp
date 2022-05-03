#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>a;
vector<vector<int>>b;
vector<vector<vector<int>>> ans;
map<vector<vector<int>>, int> visi;
vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool isvalid(int x, int y, int n, int m) {
    if(x >= 0 && y >= 0 && x < n && y < m) return true;
    return false;
}

int heuristic(vector<vector<int>> cur) {
    int val = 0;
    for(int i=0; i<cur.size(); i++) {
        for(int j=0; j<cur[0].size(); j++) {
            if(cur[i][j] != b[i][j]) val++;
        }
    }
    return val;
}

void sol() {
    priority_queue<pair<pair<int, int>, vector<vector<int>>>, vector<pair<pair<int, int>, vector<vector<int>>>>, greater<pair<pair<int, int>, vector<vector<int>>>>> q;
    q.push({{heuristic(a), 0}, a});
    map<vector<vector<int>>, vector<vector<int>>> m;
    visi[a] = heuristic(a);
    while(!q.empty()) {
        auto x = q.top();
        if(x.second == b) {
            break;
        }
        q.pop();
        auto cur = x.second;
        for(int i=0; i<cur.size(); i++) {
            for(int j=0; j<cur[0].size(); j++) {
                if(cur[i][j] == 0) {
                        for(int k=0; k<4; k++) 
                        {
                            int ii = i + dir[k][0];
                            int jj = j + dir[k][1];
                            int thival = x.first.second + 1;
                            if(isvalid(ii, jj, cur.size(), cur[0].size())) {
                                swap(cur[i][j], cur[ii][jj]);
                                int heu = heuristic(cur);
                                if(visi[cur] > (heu + thival) || visi[cur] == 0) {
                                    q.push({{heu + x.first.second + 1, x.first.second + 1}, cur});
                                    m[cur] = x.second;
                                    visi[cur] = heu + thival + 1;
                                }
                                swap(cur[i][j], cur[ii][jj]);
                            }
                        }
                }
            }
        }
    }
    while(b != a) {
        ans.push_back(b);
        b = m[b];
    }
    ans.push_back(a);
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

    sol();
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