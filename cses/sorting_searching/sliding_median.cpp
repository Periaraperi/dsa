#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<int> lower,upper;

void update(int k)
{
    if(upper.size()>k/2)
    {
        int val = *upper.begin();
        lower.insert(val);
        upper.erase(upper.begin());
    }
    else if(lower.size()>(k+1)/2)
    {
        int val = *--lower.end();
        upper.insert(val);
        lower.erase(--lower.end());
    }
}

void add(int x,int lastMedian,int k)
{
    if(x<=lastMedian)
        lower.insert(x);
    else
        upper.insert(x);
    update(k);
}

void rem(int x,int lastMedian)
{
    if(x>lastMedian)
    {
        auto it = upper.find(x);
        if(it!=upper.end())
            upper.erase(it);
    }
    else
    {
        auto it = lower.find(x);
        if(it!=lower.end())
            lower.erase(it);
    }
}

int main()
{
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
         cin >> v[i];
    for(int i=0; i<k; ++i) add(v[i],-1,k);

    int median = *--lower.end();
    cout << median << " ";

    for(int i=k; i<n; ++i)
    {
        rem(v[i-k],median);
        add(v[i],median,k);
        median = *--lower.end();
        cout << median << " ";
    }
}
