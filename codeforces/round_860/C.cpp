#include <bits/stdc++.h>
 
using namespace std;

long long gcd(long long a, long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

long long lcm(long long a, long long b)
{
    return a*b/gcd(a,b);
}

struct candy {
    long long a,b;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<candy> v(n);
        for (auto& [a,b]:v) {
            cin >> a >> b;
        }
        long long running_lcm = v[0].b;
        long long running_gcd_tot = v[0].a*v[0].b;
        int cnt = 1;
        for (int i=1; i<n; ++i) {
            running_lcm = lcm(running_lcm,v[i].b);
            running_gcd_tot = gcd(running_gcd_tot,v[i].a*v[i].b);
            if (running_gcd_tot%running_lcm!=0) {
                running_lcm = v[i].b;
                running_gcd_tot = v[i].a*v[i].b;
                ++cnt;
            } 
        }
        cout << cnt << '\n';
    }
    return 0;
}

