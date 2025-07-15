#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        int64_t layer {max(r, c)};
        int64_t left  {(layer-1)*(layer-1)+1};
        int64_t right {layer*layer};
        
        // direction changes with parity.
        // Mirror on diagonal.
        if (layer%2 == 0) {
            swap(r, c);
        }

        if (r < c) {
            cout << right - (r-1) << '\n';
        }
        else {
            cout << left + (c-1) << '\n';
        }
    }
    return 0;
}

