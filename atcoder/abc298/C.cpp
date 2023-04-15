#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    constexpr int maxn = 2e5 + 1;
    while(t--) {
        int n,q; cin >> n >> q;
        vector<multiset<int>> a(maxn);
        vector<set<int>> b(maxn);
        
        while (q--) {
            int x; cin >> x;
            if (x==1) {
                int card,box; cin >> card >> box;
                a[box].insert(card);
                b[card].insert(box);
            } else if (x==2) {
                int box; cin >> box;
                for (const auto& i:a[box]) {
                    cout << i << " ";
                }
                cout << '\n';
            } else if (x==3) {
                int card; cin >> card;
                for (const auto& i:b[card]) {
                    cout << i << " ";
                }
                cout << '\n';
            }
        }

    }
    return 0;
}

