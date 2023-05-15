#include <bits/stdc++.h>
 
using namespace std;
 
int64_t my_ceil(int64_t a, int64_t b)
{
    if (a==0) return 0LL;
    if (a%b==0) return a/b;
    return a/b + 1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int64_t n,q; cin >> n >> q;
        vector<int64_t> a(n);
        for (int i=0; i<n; ++i) { 
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        constexpr int64_t INF = 1e18;
        while (q--) {
            int64_t k; cin >> k;
            if (n==1) {
                if (k%2==1) cout << a[0]+my_ceil(k,2) << " ";
                else cout << a[0] - k/2 << " ";
                continue;
            }

            auto v = a;
            if (k<=n) { // we can only increase K values, so add k to min and k-1 to second min and so on
                for (int i=k-1; i>=0; --i) 
                    v[i] += (k-i);
                auto mn = INF;
                for (int i=0; i<n; ++i) 
                    mn = min(mn,v[i]);
                cout << mn << " ";
            } else if ((k-n)%2==0) { 
                // we can increase every value, last n increases are k, k-1, ... k-n+1
                // and distribute pairs that produce -1 optimally
                for (int i=0; i<n; ++i) // last n increments
                    v[i] += (k-i);
                auto mn = INF;
                for (int i=0; i<n; ++i)
                    mn = min(mn,v[i]);
                auto sm = 0LL;
                for (int i=0; i<n; ++i)
                    sm += (v[i]-mn);
                // first sm ops won't change min, after sm ops every elem will be mn
                // after that distribute remaining -1s optimally
                auto pairs = (k-n)/2;
                if (sm>pairs) cout << mn << " ";
                else cout << mn-my_ceil((pairs-sm),n) << " ";
            } else {
                auto init_max = v[n-1];
                for (int i=0; i<n-1; ++i) // last n-1 increments
                    v[i] += (k-i);
                auto mn = INF;
                for (int i=0; i<n; ++i)
                    mn = min(mn,v[i]);
                auto sm = 0LL;
                for (int i=0; i<n; ++i)
                    sm += (v[i]-mn);
                auto pairs = (k-n+1)/2;
                if (sm>pairs) cout << mn << " ";
                else cout << mn-my_ceil((pairs-sm),n) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
