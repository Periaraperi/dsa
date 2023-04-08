#include <bits/stdc++.h>
 
using namespace std;
 
// nice bin search
// careful with long longs

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        long long n,k; cin >> n >> k;
        vector<long long> a(n),b(n);
        for (auto&& i:a) cin >> i;
        for (auto&& i:b) cin >> i;

        auto check = [&a = a, &b = b, n = n](long long cookies, long long k) -> bool {
            for (int i=0; i<n; ++i) {
                long long need = cookies*a[i];
                if (b[i]>=need) continue;
                if (need-b[i]<=k) k -= (need-b[i]);
                else return false;
            } 
            return true;
        };

        long long lo = 0;
        long long hi = (accumulate(b.begin(),b.end(),0LL)+k)/accumulate(a.begin(),a.end(),0LL);
        while (lo<=hi) {
            auto m = (lo+hi)/2;
            if (check(m,k)) {
                lo = m+1;
            } else {
                hi = m-1;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}

