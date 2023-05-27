#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;// cin >> t;
    while(t--) {
        int n,m,h,k; cin >> n >> m >> h >> k;
        string s; cin >> s;
        vector<pair<int,int>> v(m);
        map<pair<int,int>,bool> mp;
        for (auto& p:v) {
            cin >> p.first >> p.second;
            mp[p] = true;
        }
        int x = 0, y = 0;
        int cnt = 0;

        auto move = [](const string& s,int i, int& x, int& y) -> void {
            if (s[i]=='R') ++x;
            if (s[i]=='L') --x;
            if (s[i]=='U') ++y;
            if (s[i]=='D') --y;
        };

        for (int i=0; i<(int)s.size(); ++i) {
            move(s,i,x,y);
            --h;
            if (h<0) break;
            if (mp[make_pair(x,y)] && h<k) {
                h = k;
                mp[make_pair(x,y)] = false;
            }
            ++cnt;
        }
        if (cnt==n) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

