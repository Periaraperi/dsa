#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int i = 0;
        while (i<n) {
            if (s[i]=='"') {
                ++i;
                while (i<n) {
                    if (s[i]=='"') break;
                    ++i;
                }
                ++i;
                continue;
            } else if (s[i]==',') {
                s[i] = '.';
            }
            ++i;
        }
        cout << s << '\n';
    }
    return 0;
}