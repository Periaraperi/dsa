#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;

    while (t--) {
        int a, b; cin >> a >> b;
        if ((a+b) % 3 == 0 && min(a,b)*2 >= max(a,b)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

