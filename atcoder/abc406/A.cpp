#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d; cin >> a >> b >> c >> d;

    if (a < c) {
        cout << "No\n";
    }
    else {
        if (a == c) {
            if (b < d) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
        else {
            cout << "Yes\n";
        }
    }

    return 0;
}

