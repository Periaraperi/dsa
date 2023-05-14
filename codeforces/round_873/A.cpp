#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);        
        for (int i=0; i<n; ++i) v[i] = 1+i;
        int sm = accumulate(v.begin(),v.end(),0);
        if (sm%n!=0) {
            int x = (int)ceil((double)sm/n);
            x *= n;
            v[0] += (x-sm);
        }
        for (auto& i:v) cout << i << " ";
        cout << '\n';
    }
    return 0;
}

