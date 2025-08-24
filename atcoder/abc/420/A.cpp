#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y; cin >> x >> y;
    int m {(x+y)%12};
    if (m==0) cout << 12 << '\n';
    else cout << m << '\n';
    return 0;
}

