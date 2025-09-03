#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

void recurse(int l, int r, vector<int>& v)
{
    if (l+1 == r) {
        if (v[r] < v[l]) swap(v[l], v[r]);
        return;
    }
    int m {(l+r) / 2};
    recurse(l, m, v);
    recurse(m+1, r, v);
    if (v[m+1] < v[l]) {
        reverse(v.begin()+l, v.begin()+m+1);
        reverse(v.begin()+m+1, v.begin()+r+1);
        reverse(v.begin()+l, v.begin()+r+1);
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(1<<n);
        for (auto& i:v) cin >> i;
        recurse(0, (int)v.size()-1, v);
        for (const auto& i:v) cout << i << " ";
        cout << '\n';
    }
    return 0;
}

// we can reverse ranges whose lengths are powers of two
// reversible ranges start at 0, len, 2*len, 3*len ...
// nLog(n)
// 1 2 3 4 5 6 7 8
// --- --- --- ---
// ------- -------
// ---------------
