#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int h,w; cin >> h >> w;
        vector<string> v(h);
        for (auto&& str:v) cin >> str;
        for (int i=0; i<h; ++i) {
            auto& s = v[i];
            for (int j=0; j<(int)s.size()-1; ++j) {
                if (s[j]=='T' && s[j]==s[j+1]) {
                    s[j] = 'P';
                    s[j+1] = 'C';
                }
            }
        }
        for (const auto& str:v) cout << str << '\n';
    }
    return 0;
}

