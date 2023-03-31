#include <bits/stdc++.h>
 
using namespace std;

// 1200 rated problem, could not solve.
// very interesting solution
//
// notice that every player will play with every other
// so order of pairings does not matter
//
// also, since we are adding all pairwise distances to answer,
// the order of those pairwise distance additions does not matter
// meaning we can go column by column and sort the column
//
// 1 8 1  -->  1 2 1
// 7 3 4  -->  2 3 1
// 2 2 1  -->  7 8 4

// since elems are sorted, bigger pairwise distances can be
// seen, as sum of smaller pairwise distances, that are inside bigger par
// e.g.
// consider number elems on line: 1 2 7: (1,7) distance can be expressed
// as sum of distances of (1,2) and (2,7)
// generally: every (l,r) pairs distance, can contribute to every other larger pair (a,b)'s distance
// i.e (l,r) is inside (a,b)
// so answer for each column will be sum of each neighbouring elements distance * k
// where k is to how many other pairs does (l,r) contribute
//
// (l,r) is inside i*j intervals, where i is number of elements/points to the left of l, including l
// and j is number of elements/points to the right of r, including r
// basically we just fix left and right endpoints
//
// so for each column C, ans += (C[i+1]-C[i])*i*(n-i)

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> v(n,vector<int>(m));
        long long ans = 0;
        for (int i=0; i<n; ++i) 
            for (int j=0; j<m; ++j)
                cin >> v[i][j];
        for (int col=0; col<m; ++col) {
            vector<int> column;
            for (int i=0; i<n; ++i) 
                column.push_back(v[i][col]);
            sort(column.begin(),column.end());
            for (int i=0; i<n-1; ++i)
                ans += (long long)(column[i+1]-column[i])*(i+1)*(n-(i+1)); // i+1 because of 0 indexing
        }
        cout << ans << '\n';
    }
    return 0;
}

