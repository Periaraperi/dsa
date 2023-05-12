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
        for (auto& i:v) cin >> i;
        vector<int> a;
        for (int i=0; i<n; ++i) {
            a.push_back(v[i]);
            while (i+1<n && v[i]==v[i+1]) ++i;
        }
        int ans = a.size();
        for (int i=1,l=0; i<a.size()-1; ++i) {
            if (abs(a[i]-a[l])+abs(a[i]-a[i+1])==abs(a[l]-a[i+1])) {
                --ans;
            } else {
                l = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

