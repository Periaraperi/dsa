#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t n; cin >> n;
    while (n > 1) {
        cout << n << ' ';
        if (n%2 == 1) {
            n *= 3;
            ++n;
        }
        else {
            n /= 2;
        }
    }
    cout << 1 << '\n';
    return 0;
}

