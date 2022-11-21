#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(vector<int> &v,ll maxPossibleSum,int k)
{
    ll currSum = 0;
    int cntSubArrays = 0;

    for(int i=0; i<v.size(); ++i)
    {
        if(v[i]>maxPossibleSum)
            return 0;
        currSum += v[i];

        if(currSum>maxPossibleSum)
        {
            ++cntSubArrays;
            currSum = v[i];
        }
    }
    ++cntSubArrays;
    return (cntSubArrays<=k);
}

int main()
{
    int n,k; cin >> n >> k;
    vector<int> v(n);
    ll lo = 1, hi = 0;
    for(int i=0; i<n; ++i)
    {
        cin >> v[i];
        hi += v[i];
    }

    ll ans = -1;
    while(lo<=hi)
    {
        ll m = (lo+hi)/2;

        if(ok(v,m,k))
        {
            ans = m;
            hi = m-1;
        }
        else lo = m+1;
    }
    cout << ans;
}
