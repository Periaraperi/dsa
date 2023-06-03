#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while (t--) {
        int w,h; cin >> w >> h;
        int n; cin >> n;
        vector<pair<int,int>> v(n);    
        for (int i=0; i<n; ++i) {
            cin >> v[i].first >> v[i].second;
        }
        int a; cin >> a;
        vector<int> v1(a);
        v1.push_back(w);
        for (int i=0; i<a; ++i) cin >> v1[i];
        int b; cin >> b;
        vector<int> v2(b);
        for (int i=0; i<b; ++i) cin >> v2[i];
        v2.push_back(h);

        constexpr int INF = 1e9;
        map<pair<int,int>,int> freq;
        for (int i=0; i<n; ++i) {
            pair<int,int> p = {0,0};
            p.first = *upper_bound(v1.begin(),v1.end(),v[i].first);
            p.second = *upper_bound(v2.begin(),v2.end(),v[i].second);
            ++freq[p];
        }
        
        int mx = -INF;
        int mn = INF;
        int64_t tot = (int64_t)v1.size()*(int64_t)v2.size();
        for (const auto& [k,v]:freq) {
            mx = max(mx,v);
            mn = min(mn,v);
        }
        if (tot>(int64_t)freq.size()) mn = 0;

        cout << mn << " " << mx << '\n';

    }
    return 0;
}

