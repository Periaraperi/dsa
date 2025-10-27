#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> freq(n, 1);
    int r {-1};
    while (q--) {
        int x, y; cin >> x >> y;
        --x; --y;
        if (r==-1) {
            cout << x+1 << '\n';
            freq[y] += (x+1);
        }
        else {
            if (x <= r) {
                cout << 0 << '\n';
                continue;
            }
            int sm {};
            for (int i{r+1}; i<=x; ++i) {
                sm += freq[i];
            }
            cout << sm << '\n';
            freq[y] += sm;
        }
        r = x;
    }
    return 0;
}

