#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ok = false;
        for (int i=0; i<n-1; ++i) {
            string tmp = ""; tmp += s[i]; tmp += s[i+1];
            if (i+2<n && s.find(tmp,i+2)!=string::npos) {
                ok = true;
                break;
            }
        }
        cout << (ok?"YES\n":"NO\n");
    }

    return 0;
}