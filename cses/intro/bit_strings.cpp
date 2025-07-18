#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int MOD {1000000000+7};
    
    int n; cin >> n;
    int k {1};
    for (int i{}; i<n; ++i) {
        k *= 2;
        k %= MOD;
    }
    cout << k << '\n';

    return 0;
}

