#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> v(n);
        for (auto& i:v) {
            cin >> i;
        }
        sort(v.begin(),v.end());
        if (v.front()==v.back()) {
            cout << "No\n";
        } else {
            long long m = v.back()-v.front(); 
            vector<int> ans;
            int i = 0;
            int j = n-1;
            long long sm = 0;
            while (i<=j) {
                if (v[i]+sm>-m && v[i]+sm<m) {
                    ans.push_back(v[i]);
                    sm += v[i];
                    ++i;
                } else {
                    ans.push_back(v[j]);
                    sm += v[j];
                    --j;
                }
            }
            cout << "Yes\n";
            for (const auto num:ans) cout << num << " ";
            cout << '\n';
        
        }
    }
    return 0;
}

