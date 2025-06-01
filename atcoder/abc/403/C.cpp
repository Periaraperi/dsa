#include <iostream>
#include <set>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q; cin >> n >> m >> q;
    set<int> all;
    set<pair<int, int>> user_page;
    while (q--) {
        int k; cin >> k;
        if (k == 1) {
            int x, y; cin >> x >> y;
            user_page.insert({x, y});
        }
        else if (k == 2) {
            int x; cin >> x;
            all.insert(x);
        }
        else {
            int x, y; cin >> x >> y;
            if (all.find(x) != all.end() || user_page.find({x, y}) != user_page.end()) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}

