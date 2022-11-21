#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    standard maximum subarray problem, but
    we need to find optimal subarray only of length between [a,b]
    in n*log(n) time;

    idea:
    maintain a prefixSum array. Now subarray sum in range [L+1,R] is
    Pref[R]-Pref[L] where a<=R-L<=b.
    for every R=a -> R=n find optimal pref[L].

    since we want to maximize Pref[R]-Pref[L], optimal Pref[L] will be minimum possible,
    such that L is in range [R-a,R-b].

    we store left prefixes in multiset because we can access optimal left prefix in log(n) time.

    if L goes out of range we will erase Pref[L] from multiset.
    at each iteration we add leftmost possible Pref[L] in multiset for future R points.

*/

int main()
{
    int n,a,b; cin >> n >> a >> b;
    vector<ll> pref(n+1,0);
    for(int i=1; i<=n; ++i)
    {
        int val; cin >> val;
        pref[i] += (pref[i-1]+val);
    }
    multiset<ll> leftPrefixes;
    ll ans = pref[a];
    for(int r=a; r<=n; ++r)
    {
        // all prefixSums which end at index r-b-1 are out of range.
        if(r>b) leftPrefixes.erase(leftPrefixes.lower_bound(pref[r-b-1]));
        leftPrefixes.insert(pref[r-a]); // insert current leftmost prefix
        ans = max(ans,pref[r]-(*leftPrefixes.begin())); // check if answer can be better.
    }
    cout << ans;
}
