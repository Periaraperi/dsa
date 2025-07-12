#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int x{}, y{};
    for (int i{}; i<n-1; ++i) {
        int a; cin >> a;
        x ^= a;
    }
    for (int i{1}; i<=n; ++i) {
        y ^= i;
    }
    cout << (x^y) << '\n';

    return 0;
}
