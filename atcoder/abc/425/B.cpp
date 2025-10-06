#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> freq(n+1, 0);
    bool ok {true};
    for (int i{}; i<n; ++i) {
        cin >> v[i];
        const auto& a {v[i]};
        if (a!=-1) {
            ++freq[a];
            if (freq[a] > 1) {
                ok = false;
            }
        }
    }
    if (!ok) cout << "No\n";
    else {
        cout << "Yes\n";
        vector<int> unused;
        for (int i{1}; i<=n; ++i) {
            if (freq[i] == 0) unused.emplace_back(i);
        }
        int j{};
        for (const auto& i:v) {
            if (i==-1) {
                cout << unused[j] << " ";
                ++j;
            }
            else cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}

