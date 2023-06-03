#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<string,int>> v(n);
        int id=-1;
        int mn=1e9+7;
        for (int i=0; i<n; ++i) {
            cin >> v[i].first >> v[i].second;
            if (v[i].second<mn) {
                id = i;
                mn = v[i].second;
            }
        }
        for (int i=id; i<n; ++i) {
            cout << v[i].first << '\n';
        }
        for (int i=0; i<id; ++i) {
            cout << v[i].first << '\n';
        }
        cout << '\n';
    }
    return 0;
}

