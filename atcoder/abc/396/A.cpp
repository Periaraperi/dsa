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
    bool ok {false};
    for (int i{1}; i<n-1; ++i) {
        if (v[i]==v[i-1] && v[i]==v[i+1]) {
            ok = true;
            break;
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

