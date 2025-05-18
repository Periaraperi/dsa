#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,x; cin >> n >> x;
        vector<int> v(n);
        map<int,bool> mp;
        for (auto& i:v) {
            cin >> i;
            mp[i] = true;
        }
        bool ok = false;
        for (auto i:v) {
            int need = i-x;
            //cout << "need: " << need << " " << "elem: " << i << '\n';
            if (mp.find(need)!=mp.end()) {
                ok = true;
                break;
            }
        }
        cout << (ok?"Yes\n":"No\n");
    }
    return 0;
}

