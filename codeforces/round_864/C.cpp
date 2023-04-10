#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m; 
        int dd = -1;
        int x = 1, y = 1;

        cout << "? " << x << " " << y << endl; 
        int d; cin >> d;
        if (x+d<=n && y+d<=m) {
            x += d;
            dd = d;
            cout << "? " << x << " " << y << endl;
            cin >> d;
            if (d==dd) {
                y += d;
                cout << "? " << x << " " << y << endl;
                cin >> d;
                cout << "! " << x-d << " " << y << endl;
            } else {
                cout << "! " << x << " " << y+d << endl;
            }
        } else if (x+d<=n) {
            x += d;
            cout << "? " << x << " " << y << endl;
            cin >> d;
            cout << "! " << x << " " << y+d << endl;
        } else if (y+d<=m) {
            y += d;
            cout << "? " << x << " " << y << endl;
            cin >> d;
            cout << "! " << x+d << " " << y << endl;
        }
    }
    return 0;
}

