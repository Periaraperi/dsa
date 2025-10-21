#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> tree(n);
    tree[0] = -1;
    for (int i{1}; i<=n-1; ++i) {
        int a; cin >> a;
        --a;
        tree[i] = a;
    }
    
    vector<vector<int>> jump(n, vector<int>(31, -1));

    for (int i{}; i<n; ++i) {
        jump[i][0] = tree[i];
    }
    for (int j{1}; j<=30; ++j) {
        for (int i{}; i<n; ++i) {
            if (jump[i][j-1] != -1) {
                jump[i][j] = jump[jump[i][j-1]][j-1];
            }
        }
    }

    while (q--) {
        int x, k; cin >> x >> k;
        --x;
        int a {x};
        for (int i{30}; i>=0; --i) {
            if ((1<<i) <= k) {
                a = jump[a][i];
                k -= (1<<i);
                if (a == -1) break;
            }
        }
        if (a != -1) ++a;
        cout << a << '\n';
    }

    return 0;
}

