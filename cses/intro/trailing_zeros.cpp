#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t n; cin >> n;
    int ans {};
    for (int64_t i{5}; i<=n; i*=5) {
        ans += n/i;
    }
    cout << ans << '\n';
    return 0;
}

