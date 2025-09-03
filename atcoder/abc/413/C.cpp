#include <iostream>
#include <queue>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    struct info {
        int64_t val{};
        int count{};
    };
    queue<info> qu;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int c, val; cin >> c >> val;
            qu.push({val, c});
        }
        else {
            int k; cin >> k;
            int64_t sm{};
            while (k>0) {
                const auto i {qu.front()};
                if (k < i.count) {
                    qu.front().count -= k;
                    sm += i.val*k;
                    k = 0;
                }
                else {
                    k -= i.count;
                    sm += i.count*i.val;
                    qu.pop();
                }
            }
            cout << sm << '\n';
        }
    }
    return 0;
}

