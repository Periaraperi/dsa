#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int ax,ay; cin >> ax >> ay;
        int bx,by; cin >> bx >> by;
        int cx,cy; cin >> cx >> cy;
        int x = 0;
        if ((cx>=ax && bx>=ax) || (cx<ax && bx<ax)) {
            x = min(abs(ax-cx),abs(ax-bx));
        }
        int y = 0;
        if ((cy>=ay && by>=ay) || (cy<ay && by<ay)) {
            y = min(abs(ay-cy),abs(ay-by));
        }
        cout << x + y + 1 << '\n';
    }
    return 0;
}

