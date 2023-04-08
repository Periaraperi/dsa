#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        string a,b;
        for (int i=0; i<2*n-2; ++i) {
            string s; cin >> s;
            if (s.size()==n-1) {
                if (a.empty()) a = s;
                else b = s;
            }
        }    
        int m = n-1;
        string x;
        bool ok = true;
        for (int i=1,j=0; i<m && j<m-1; ++i,++j) {
            if (a[i]!=b[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            x = a;
            x.push_back(b.back());
        } else {
            x = b;
            x.push_back(a.back());
        }


        bool pal = true;
        for (int i=0; i<n/2; ++i) {
            if (x[i]!=x[n-i-1]) {
                pal = false;
                break;
            }
        }
        if (pal) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

