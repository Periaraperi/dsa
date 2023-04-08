#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,s1,s2; cin >> n >> s1 >> s2;
        vector<pair<int,int>> v(n);
        for (int i=0; i<n; ++i) {
            cin >> v[i].first;
            v[i].second = i+1;
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int> a,b;
        for (auto [_,color]:v) {
            auto [A,B] = make_pair((int)a.size(),(int)b.size());
            if (s1*(A+1)<=s2*(B+1)) {
                a.push_back(color);
            } else {
                b.push_back(color);
            }
        }
        cout << a.size() << " ";
        for (auto i:a) cout << i << " ";
        cout << '\n';
        cout << b.size() << " ";
        for (auto i:b) cout << i << " ";
        cout << '\n';
    }
    return 0;
}

