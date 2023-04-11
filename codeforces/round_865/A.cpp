#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        cout << "2\n" << a-1 << " " << 1 << '\n' << a << " " << b << '\n';
    }
    return 0;
}

