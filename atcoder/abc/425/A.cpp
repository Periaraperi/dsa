#include <cmath>
#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int ans {};
    for (int i{1}; i<=n; ++i) {
        ans += (pow(-1, i)*i*i*i);
    }
    cout << ans << '\n';
    return 0;
}

