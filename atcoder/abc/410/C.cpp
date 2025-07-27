#include <iostream>
#include <numeric>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int i {};
    while (q--) {
        int j; cin >> j;
        if (j == 1) {
            int p, x; cin >> p >> x;
            --p;
            v[(i+p)%n] = x;
        }
        else if (j == 2) {
            int p; cin >> p;
            --p;
            cout << v[(i+p)%n] << '\n';
        }
        else {
            int k; cin >> k;
            i = (i+k)%n;
        }
    }

    return 0;
}

