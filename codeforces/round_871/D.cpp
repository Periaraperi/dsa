#include <bits/stdc++.h>
 
using namespace std;
 
bool f(int a, int b, int m)
{
    if (a==m || b==m) return true;
    bool b1 = false;
    if (m<a) {
        if (a%3==0) {
            b1 = f(a/3,a-(a/3),m);
            if (b1) return true;
        }
    }
    bool b2 = false;
    if (m<b) {
        if (b%3==0) {
            b2 = f(b/3,b-(b/3),m);
            if (b2) return true;
        }
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        if (m>n) {
           cout << "NO\n";
           continue;
        }
        if (m==n) {
           cout << "YES\n";
           continue;
        }
        
        if (n%3!=0) {
            cout << "NO\n";
        } else {
            auto x = n/3;
            bool can = f(x,n-x,m);
            if (can) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

