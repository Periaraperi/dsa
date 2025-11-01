#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d; cin >> a >> b >> c >> d;
    if (c<a) cout << "No\n";
    else {
        if (d>=b) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}

