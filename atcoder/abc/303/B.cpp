#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<vector<int>> v(m,vector<int>(n));
        for (auto& i:v) for(auto& j:i) cin >> j;
        set<pair<int,int>> st;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (i==j) continue;
                st.insert({i,j});
                st.insert({j,i});
            }
        }

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n-1; ++j) {
                if (st.find({v[i][j],v[i][j+1]})!=st.end()) {
                    st.erase({v[i][j],v[i][j+1]});
                    st.erase({v[i][j+1],v[i][j]});
                }
            }
        }
        cout << st.size()/2 << '\n';

    }
    return 0;
}

