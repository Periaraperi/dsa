#include <bits/stdc++.h>
 
using namespace std;

void compress(const vector<pair<pair<int,int>,int>>& v, map<int,int>& otc)
{
    for (auto& d:v) { // put values as keys in map otc (does not matter value for now default = 1)
        otc[d.first.first] = 1;
        otc[d.first.second] = 1;
    }
    int id = 1;
    for (auto& [key,val]:otc) { // keys are sorted, so let value be monotonically increasing index
        val = id;
        ++id;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<pair<int,int>,int>> v(n);
        for (auto& d:v) 
            cin >> d.first.first >> d.first.second >> d.second; 

        map<int,int> otc; // original_to_compressed
        compress(v,otc);

        int last_day = (--otc.end())->second;

        vector<vector<pair<int,int>>> end_days(last_day+1);
        for (auto& d:v) {
            int ending = otc[d.first.second];
            int starting = otc[d.first.first];
            int val = d.second;
            end_days[ending].push_back({starting,val}); // [bi] -> {ai vi}, already compressed
        }

        vector<long long> dp(last_day+1,0);
        for (int day=1; day<=last_day; ++day) {
            if (end_days[day].empty()) {
                dp[day] = dp[day-1];
            } else {
                long long best = 0;
                for (auto& p:end_days[day]) {
                    best = max(best,dp[p.first-1]+p.second);
                }
                dp[day] = max(best,dp[day-1]);
            }
        }
        cout << dp[last_day] << '\n';
    }
    return 0;
}

