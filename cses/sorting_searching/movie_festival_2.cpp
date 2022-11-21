#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    given starting and ending times of n movies. Determine maximum
    number of movies K people can watch, if they act optimally.
    n*Log(n)
*/

int main()
{
    int n,k; cin >> n >> k;
    vector<pair<int,int>> times(n);
    for(int i=0; i<n; ++i)
        cin >> times[i].second >> times[i].first;
    sort(times.begin(),times.end());

    multiset<int> endTimes;
    int ans = 0;
    for(int i=0; i<n; ++i)
    {
        auto it = endTimes.lower_bound(times[i].second);
        if(endTimes.empty())
        {
            endTimes.insert(times[i].first);
            --k;
            ++ans;
            continue;
        }
        if(it==endTimes.end()) --it;
        else if(times[i].second!=*it)
        {
            if(it==endTimes.begin())
            {
                if(k>0)
                {
                    endTimes.insert(times[i].first);
                    --k;
                    ++ans;
                }
                continue;
            }
            else --it;
        }

        endTimes.erase(it);
        endTimes.insert(times[i].first);
        ++ans;
    }
    cout << ans;
}
