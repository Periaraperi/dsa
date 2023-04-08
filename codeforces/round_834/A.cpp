#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = (int) s.size();
        string yes = "Yes";
        for (int i=0; i<n; ++i) {
            yes += "Yes";
        }
        if (yes.find(s)!=string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}