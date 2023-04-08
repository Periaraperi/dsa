#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = (int)s.size();
        cout << (n-1)*9 + s[0]-'0' << '\n';
    }

    return 0;
}