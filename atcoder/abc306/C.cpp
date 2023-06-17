#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> fr(n+1,0);
        vector<pair<int,int>> v;
        for (int i=0; i<3*n; ++i) {
            int x; cin >> x;
            ++fr[x];
            if (fr[x]==2) {
                v.push_back({i+1,x});
            }
        }
        sort(v.begin(),v.end());
        for (auto& [x,y]:v) {
            cout << y << " ";
        } 
        cout << '\n';
    }
    return 0;
}

