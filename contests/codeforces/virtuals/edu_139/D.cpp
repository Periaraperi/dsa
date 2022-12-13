#include <bits/stdc++.h>

using namespace std;

void sieve(vector<int>& pr, int n)
{
    for (long long i=2; i<=n; ++i) {
        if (pr[i]==0) {
            pr[i] = i;
            for (long long j=i*i; j<=n; j+=i) {
                pr[j] = i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int MAX = 1e7;
    vector<int> pr(MAX+1,0);
    sieve(pr,MAX);

    int tt = 1; //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i].first >> v[i].second;
        }

        for (int i=0; i<n; ++i) {
            auto& x = v[i].first;
            auto& y = v[i].second;
            if (y-x==1) {
                cout << "-1\n";
                continue;
            }
            if (__gcd(x,y)>1) {
                cout << "0\n";
                continue;
            }
            // gcd(x,y) = gcd(x,x+-y) ==> gcd(x+k,y+k) = gcd(x+k,y-x)
            // find minimum k so that gcd(x+k,y-x) > 1
            // this means, that x+k must contain at least 1 prime from prime factorization of (y-x)
            // use sieve to find prime factors
            // test against all unique prime factors and choose minimum k
            // k = a*pi-x   a*pi-x>=0    a = x/pi, plug a and get k

            int k = 1e9;
            int dif = y-x;
            while (pr[dif]>0) {
                int a = (x+pr[dif]-1) / pr[dif]; // same as ceil(x/pr[dif])
                k = min(k,a*pr[dif]-x);
                dif /= pr[dif];
            }
            cout << k << '\n';
        }

    }

    return 0;
}