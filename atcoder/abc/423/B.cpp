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
    vector<int> freq(n+2, 0);
    freq[0] = 1;
    freq[n] = 1;
    for (int i{1}; i<n; ++i) {
        if (v[i-1] == 0) ++freq[i];
        else break;
    }
    for (int i{n-1}; i>=0; --i) {
        if (v[i] == 0) ++freq[i];
        else break;
    }

    int ans {};
    for (int i{0}; i<=n; ++i) {
        if (freq[i] == 0) ++ans;
    }
    cout << ans << '\n';
    return 0;
}

