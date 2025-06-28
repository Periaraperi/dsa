#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int ans {};
    while (n--) {
        int a,b; cin >> a >> b;
        if (b > a) ++ans;
    }
    cout << ans << '\n';

    return 0;
}

