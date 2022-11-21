#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n+1);
        for (int i=1; i<=n; ++i)
            cin >> v[i];
        
        vector<long long> cnt0(n+1,0);
        vector<long long> cnt1(n+1,0);

        for (int i=1; i<=n; ++i) {
            if (v[i]==0) cnt0[i] = 1;
            else cnt1[i] = 1;
            cnt0[i] += cnt0[i-1];
            cnt1[i] += cnt1[i-1];
        }
        
        long long ans = 0;
        for (int i=1; i<=n; ++i) {
            if (v[i]==0) {
                ans += cnt1[i-1];
            }
        }
        
        long long ans_copy = ans;

        for (int i=1; i<=n; ++i) {
            if (v[i]==0) {
                ans = max(ans,ans_copy+(cnt0[n]-cnt0[i])-cnt1[i-1]);
            } else {
                ans = max(ans,ans_copy-(cnt0[n]-cnt0[i])+cnt1[i-1]);
            }
            
        }
        cout << ans << '\n';
    }
    return 0;
}

