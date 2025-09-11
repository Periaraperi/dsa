#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i:v) cin >> i;
    bool ok{true};
    for (int i{1}; i<n; ++i) {
        if (v[i] <= v[i-1]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

