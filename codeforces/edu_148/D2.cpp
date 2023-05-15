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

        // each element of sorted input array a gets decreased by i (efficient simulation of adding ks to elements)
        // since during last n increments, each elem at index i will be incremented by (k-i)
        auto fix = a; 
        for (int i=0; i<n; ++i) 
            fix[i] -= i;
        auto pref_min = fix; // prefix min for fix array, need this to calculate min after applying last k increments
        for (int i=1; i<n; ++i) 
            pref_min[i] = min(pref_min[i],pref_min[i-1]);
        auto suff_min = a; // suffix min for sorted input array a
        for (int i=n-2; i>=0; --i)
            suff_min[i] = min(suff_min[i],suff_min[i+1]);

        auto pref_sum = fix; // pref sum to calculate sum of differences between incremented values and min
        for (int i=1; i<n; ++i)
            pref_sum[i] += pref_sum[i-1];

        while (q--) {
            int64_t k; cin >> k;
            if (n==1) {
                if (k%2==1) cout << a[0]+my_ceil(k,2) << " ";
                else cout << a[0] - k/2 << " ";
                continue;
            }

            if (k<=n) { // we can only increase K values, so add k to min and k-1 to second min and so on
                auto l = pref_min[k-1]+k;
                auto r = INF;
                if (k<n) r = suff_min[k];
                cout << min(l,r) << " ";
            } else if ((k-n)%2==0) { 
                // we can increase every value, last n increases are k, k-1, ... k-n+1
                // and distribute pairs that produce -1 optimally
                
                auto mn = pref_min[n-1]+k; // after last k increments min of whole array
                auto sm = pref_sum[n-1]+k*n-mn*n; // after last k increments sum of difference between a[i] and min
                // first sm ops won't change min, after sm ops every elem will be mn
                // after that distribute remaining -1s optimally
                auto pairs = (k-n)/2;
                if (sm>pairs) cout << mn << " "; 
                else cout << mn-my_ceil((pairs-sm),n) << " ";
            } else {
                auto mn = min(pref_min[n-2]+k,suff_min[n-1]); // min after last n-1 incremenets
                auto sm = pref_sum[n-2]+k*(n-1)+suff_min[n-1]-mn*n;
                auto pairs = (k-n+1)/2;
                if (sm>pairs) cout << mn << " ";
                else cout << mn-my_ceil((pairs-sm),n) << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}

