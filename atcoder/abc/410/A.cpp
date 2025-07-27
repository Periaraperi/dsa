#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (auto& i:v) {
        cin >> i;
    }
    int k; cin >> k;
    int ans{};
    for (const auto& i:v) {
        if (k <= i) ++ans;
    }
    cout << ans << '\n';
    return 0;
}

