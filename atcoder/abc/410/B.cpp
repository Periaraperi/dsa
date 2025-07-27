#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> boxes(n);
    while (q--) {
        int a; cin >> a;
        if (a == 0) {
            int j {};
            int mn {1000000000};
            for (int i{}; i<n; ++i) {
                if (boxes[i] < mn) {
                    mn = boxes[i];
                    j = i;
                }
            }
            cout << j+1 << " ";
            ++boxes[j];
        }
        else {
            cout << a << " ";
            --a;
            ++boxes[a];
        }
    }
    cout << '\n';
    return 0;
}

