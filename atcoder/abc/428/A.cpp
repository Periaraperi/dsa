#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s, a, b, x; cin >> s >> a >> b >> x;
    int t {};
    int ans {};
    while (t < x) {
        for (int i{}; i<a && t < x; ++i) {
            ans += s;
            ++t;
        }
        t += b;
    }
    cout << ans << '\n';
    return 0;
}

