#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    int cnt = 0;
    unordered_map<int,int> freq;
    freq.reserve(1<<20);
    ll ans = 0;
    int i = 0,j = 0;
    while(i<n && j<n)
    {
        if(freq[v[j]]==0)
        {
            ++freq[v[j]];
            ++cnt;
            if(cnt>k)
            {
                while(1)
                {
                    --freq[v[i]];
                    if(freq[v[i]]==0)
                    {
                        --cnt;
                        ans += (j-i);
                        ++i;
                        break;
                    }
                    ++i;
                }
            }
            else ans += (j-i+1);
        }
        else
        {
            ans += (j-i+1);
            ++freq[v[j]];
        }
        ++j;
    }
    cout << ans << '\n';
}

