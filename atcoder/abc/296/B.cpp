#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        vector<string> v(8);
        vector<char> vv = {'a','b','c','d','e','f','g','h'};
        for (int i=0; i<8; ++i) {
            cin >> v[i];
            for (int j=0; j<8; ++j) {
                if (v[i][j]=='*') {
                    cout << vv[j] << 8-i << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}

