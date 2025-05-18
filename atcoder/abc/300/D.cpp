#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> sieve(int n)
{
    vector<int> p(n+1,1);
    p[0] = p[1] = 0;
    for (int i=2; i<=n; ++i) {
        if (p[i]==0) continue;
        for (int j=2*i; j<=n; j += i) {
            p[j] = 0;
        } 
    }
    return p;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int64_t n; cin >> n;
        int x = ceil(sqrt((long double)n));
        auto primes = sieve(x);

        vector<int64_t> p;
        for (int64_t i=2; i*i<=n; ++i) {
            if (primes[i])
                p.push_back(i);
        }
        int m = (int)p.size();

        int64_t cnt = 0;
        for (int i=0; i<m-2; ++i) {
            auto a = p[i]*p[i];
            if (a>n) break;
            auto rem1 = n/a;
            for (int j=i+1; j<m-1; ++j) {
                if (p[j]>rem1) {
                    break;
                }
                auto rem2 = rem1/p[j];
                for (int k=j+1; k<m; ++k) {
                    if (p[k]*p[k]>rem2) {
                        break;
                    }
                    ++cnt;
                }
            }
        }

        cout << cnt << '\n';

    }
    return 0;
}

