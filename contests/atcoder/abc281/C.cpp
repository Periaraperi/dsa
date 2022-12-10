#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        long long m; cin >> m;
        vector<long long> v(n);
        long long sm = 0;
        for (auto& i:v) {
            cin >> i;
            sm += i;
        }
        if (m>sm) m %= sm;
        

        long long cnt = 0;
        for (int i=0; i<n; ++i) {
            if (cnt+v[i]>m) {
                cout << (i+1) << " " << v[i]-(cnt+v[i]-m) << '\n';
                break;
            }
            cnt += v[i];
        }
    }
    return 0;
}