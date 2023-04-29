#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> sieve()
{
    const int MAX = 1e7 + 3;
    vector<int> p(MAX,1);
    p[0] = p[1] = 0;
    for (int i=2; i<=MAX; ++i) {
        if (p[i]!=1) continue;
        p[i] = i;
        for (int j=i; j<=MAX; j+=i) {
            if (p[j]==1)
                p[j] = i;
        }
    }
    return p;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto p = sieve();
    map<int,int> f;
    int t = 1; cin >> t;
    for (int tt=0; tt<t; ++tt) {
        f.clear();
        int n; cin >> n;
        for (int i=0; i<n; ++i) {
            int x; cin >> x;
            while (x>1) {
                ++f[p[x]];
                x /= p[x];
            }
        }
        
        int ans = 0;
        int k = 0;
        for (auto it:f) {
            ans += (it.second/2);
            k += (it.second%2);
        }
        cout << ans + k/3 << '\n';
    }
    return 0;
}

