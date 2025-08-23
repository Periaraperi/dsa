#include <iostream>
#include <vector>
 
using namespace std;

constexpr int MAX_ALLOC {(int)1e6};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i:v) {
        cin >> i;
    }
    vector<int> freq(MAX_ALLOC, 0);
    int64_t ans {};
    for (int i{n}; i>=1; --i) {
        // j - i = ai + aj
        // j - aj = ai + i
        const auto& a {v[i-1]};
        ans += freq[a+i];
        if (i-a > 0) {
            ++freq[i-a];
        }
    }
    cout << ans << '\n';
    return 0;
}

