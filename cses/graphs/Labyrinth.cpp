#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1001;
char grid[N][N];
pair<int,int> parent[N][N];
int n,m;
int r,rr,c,cc;

bool check(int row,int col)
{
    return (row<n && row>=0 && col<m && col>=0 && grid[row][col]!='#');
}

int BFS()
{
    queue<pair<pair<int,int>,int>> q;

    q.push({{r,c},0});
    grid[r][c] = '#';
    while(!q.empty())
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int lvl = q.front().second;
        q.pop();
        if(i==rr && j==cc) return lvl;
        if(check(i+1,j))
        {
            q.push({{i+1,j},lvl+1});
            parent[i+1][j] = {i,j};
            grid[i+1][j] = '#';
        }
        if(check(i-1,j))
        {
            q.push({{i-1,j},lvl+1});
            parent[i-1][j] = {i,j};
            grid[i-1][j] = '#';
        }
        if(check(i,j+1))
        {
            q.push({{i,j+1},lvl+1});
            parent[i][j+1] = {i,j};
            grid[i][j+1] = '#';
        }
        if(check(i,j-1))
        {
            q.push({{i,j-1},lvl+1});
            parent[i][j-1] = {i,j};
            grid[i][j-1] = '#';
        }
    }
    return -1;
}


void reconstructPath()
{

    pair<int,int> p = {rr,cc};
    vector<pair<int,int>> path;
    path.push_back({rr,cc});
    while(p!=parent[r][c])
    {
        path.push_back(parent[p.first][p.second]);
        p = parent[p.first][p.second];
    }
    reverse(path.begin(),path.end());

    for(int i=1; i<path.size(); ++i)
    {
        if(path[i].first==path[i-1].first)
        {
            if(path[i].second>path[i-1].second)
                cout << 'R';
            else
                cout << 'L';
        }
        else
        {
            if(path[i].first>path[i-1].first)
                cout << 'D';
            else
                cout << 'U';
        }
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> grid[i][j];
            if(grid[i][j]=='A') r = i,c = j;
            if(grid[i][j]=='B') rr = i,cc = j;
        }
    }
    parent[r][c] = {r,c};
    int k = BFS();
    if(k==-1) cout << "NO";
    else
    {
        cout << "YES\n" << k << '\n';
        reconstructPath();
    }
}
