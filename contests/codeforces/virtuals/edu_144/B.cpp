#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        string a,b; cin >> a >> b;
        if (a.size()>b.size()) swap(a,b);
        int n = (int)a.size();
        if (a.back()==b.back()) {
            cout << "YES\n*" << a.back() << '\n';
        } else if (a.front()==b.front()) {
            cout << "YES\n" << a.front() << "*\n";
        } else {
            bool ok = false;
            string ans;
            for (int len=2; len<=n; ++len) {
                for (int i=0; i<=n-len; ++i) {
                    string sub = a.substr(i,len);
                    if (b.find(sub)!=string::npos) {
                        ok = true;
                        ans.push_back('*');
                        ans += sub;
                        ans.push_back('*');
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
            if (ok) cout << "YES\n" << ans << '\n';
            else cout << "NO\n";
        }
    }
    return 0;
}

