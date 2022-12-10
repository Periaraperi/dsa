#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = (int)s.size();
        if (n!=8) {
            cout << "No\n";
        } else {
            auto beg = s[0];
            auto en = s[n-1];
            if (!(beg>='A' && beg<='Z' && en>='A' && en<='Z')) {
                cout << "No\n";
            } else {
                string num = "";
                for (int i=1; i<n-1; ++i) {
                    if (s[i]>='0' && s[i]<='9')
                        num += s[i];
                }
                if (num.size()!=6 || num[0]=='0') {
                    cout << "No\n";
                } else {
                    cout << "Yes\n";
                }
            }
        }
    }
    return 0;
}