#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        string x = std::to_string(n);
        if (n<=1e3-1) {
            // nt
        } else if (n>=1e3 && n<=1e4-1) {
            x[x.size()-1] = '0';
        } else if (n>=1e4 && n<=1e5-1) {
            x[x.size()-1] = '0';
            x[x.size()-2] = '0';
        } else if (n>=1e5 && n<=1e6-1) {
            x[x.size()-1] = '0';
            x[x.size()-2] = '0';
            x[x.size()-3] = '0';
        } else if (n>=1e6 && n<=1e7-1) {
            x[x.size()-1] = '0';
            x[x.size()-2] = '0';
            x[x.size()-3] = '0';
            x[x.size()-4] = '0';
        } else if (n>=1e7 && n<=1e8-1) {
            x[x.size()-1] = '0';
            x[x.size()-2] = '0';
            x[x.size()-3] = '0';
            x[x.size()-4] = '0';
            x[x.size()-5] = '0';
        } else if (n>=1e8 && n<=1e9-1) {
            x[x.size()-1] = '0';
            x[x.size()-2] = '0';
            x[x.size()-3] = '0';
            x[x.size()-4] = '0';
            x[x.size()-5] = '0';
            x[x.size()-6] = '0';
        }
        cout << x << '\n';
    }
    return 0;
}

