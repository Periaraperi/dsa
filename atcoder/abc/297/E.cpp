#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vector<int> v(n);
        set<long long> st;
        for (auto&& i:v) {
            cin >> i;
            st.insert(i);
        }

        long long ans = 0;
        for (int i=0; i<k; ++i) {
            auto next_lowest = *st.begin();
            ans = next_lowest;
            st.erase(st.begin());
            for (auto p:v) {
                st.insert(next_lowest+p);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

