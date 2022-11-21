#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 101;
char grid[N][N];

int getRowIdx(int j,int n)
{
    for(int i=0; i<n; ++i)
        if(grid[i][j]=='o')
            return i;
}

int getColIdx(int i,int n)
{
    for(int j=0; j<n; ++j)
        if(grid[i][j]=='o')
            return j;
}

void removeRow(int i,int n)
{
    for(int j=0; j<n; ++j)
        grid[i][j] = '.';
}

void removeCol(int j,int n)
{
    for(int i=0; i<n; ++i)
        grid[i][j] = '.';
}

int main()
{
    int n; cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];

    vector<pair<int,int>> ans;
    int cntRows = 0;
    int cntCols = 0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(grid[i][j]=='o')
                ++cntRows;
        }
        if(cntRows==1)
        {
            int col = getColIdx(i,n);
            removeCol(col,n);
            ans.push_back({2,col+1});
        }
        cntRows = 0;
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(grid[j][i]=='o')
                ++cntCols;
        }
        if(cntCols==1)
        {
            int row = getRowIdx(i,n);
            removeRow(row,n);
            ans.push_back({1,row+1});
        }
        cntCols = 0;
    }

    cntRows = cntCols = 0;
    vector<int> row;
    vector<int> col;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(grid[i][j]=='o') ++cntRows;
            if(grid[j][i]=='o') ++cntCols;
        }
        if(cntRows!=0) row.push_back(i);
        if(cntCols!=0) col.push_back(i);
        cntRows = cntCols = 0;
    }
    if(row.size()<col.size())
        for(auto r:row)
            ans.push_back({1,r+1});
    else
        for(auto c:col)
            ans.push_back({2,c+1});
    cout << ans.size() << '\n';
    for(auto a:ans)
        cout << a.first << " " << a.second << '\n';
}
