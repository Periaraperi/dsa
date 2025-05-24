#include <cmath>
#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b; cin >> a >> b;
    if (a%b == 0) {
        cout << a/b << '\n';
    }
    else {
        int up {(int)ceil((double)a/b)};
        int down {a/b};
        double d {(double)a/b};
        if (abs(up - d) < abs(down - d)) {
            cout << up << '\n';
        }
        else {
            cout << down << '\n';
        }
    }

    return 0;
}

