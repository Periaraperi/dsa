#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,d;
        long long c;
        cin >> n >> c >> d;
        vector<long long> quests(n);
        for (auto& q:quests) {
            cin >> q;
        }
        sort(quests.begin(),quests.end(),greater<long long>());
        
        if (quests[0]*d<c) {
            cout << "Impossible\n";
            continue;
        }
        long long sm = 0;
        for (int i=0; i<min(d,n); ++i) {
            sm += quests[i]; 
        }
        if (sm>=c) {
            cout << "Infinity\n";
            continue;
        }
        
        int lo = 0;
        int hi = d;
        int k = 0;
        while (lo<=hi) {
            int m = (lo+hi)/2;
            long long local_score = 0;
            for (int i=0; i<d; ++i) {
                if (i%(m+1)<n)
                    local_score += quests[i%(m+1)];
            }
            if (local_score<c) {
                hi = m-1;
            } else {
                k = m;
                lo = m+1;
            }
        }
        cout << k << '\n';

    }
    return 0;
}
