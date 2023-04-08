#include <bits/stdc++.h>
    
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 1; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> deck(n);
        for (auto& i:deck) cin >> i;
        multiset<int> ms;
        long long ans = 0;
        for (int i=0; i<(int)deck.size(); ++i) {
            if (deck[i]==0) {
                if (ms.empty()) continue;
                auto best = --ms.end();
                ans += (*best);
                ms.erase(best);
            } else {
                ms.insert(deck[i]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}