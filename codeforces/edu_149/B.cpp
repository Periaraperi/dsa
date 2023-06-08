#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int cc = 0;
        for (int i=0; i<n; ++i) {
            int cnt = 1;
            while (i+1<n && s[i]==s[i+1]) {
                ++cnt;
                ++i;
            }
            cc = max(cc,cnt);
        }
        cout << cc+1 << '\n';
    }
    return 0;
}

