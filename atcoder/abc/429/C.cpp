#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n+1);
    vector<int64_t> freq(n+1, 0);
    for (int i{1}; i<=n; ++i) {
        cin >> v[i];
        ++freq[v[i]];
    }
    int64_t sm {};
    for (int i{1}; i<=n; ++i) {
        sm += freq[i];
    }

    int64_t ans {};
    for (int i{1}; i<=n; ++i) {
        if (freq[i] == 0) continue;
        ans += (freq[i]*(freq[i]-1)/2)*(sm-freq[i]);
    }
    cout << ans << '\n';

    return 0;
}

